#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <errno.h>
#include <iostream>

#include <time.h> 
#include <vector>

#include "TestEffectDefault.h"
#include "TestEffectFont5x5.h"
#include "TestEffectWandering.h"

static bool run = true;

void siginthandler(int param)
{
    run = false;
}

int resolvehelper(const char* hostname, int family, const char* service,
        sockaddr_storage* pAddr)
{
    int result;
    addrinfo* result_list = NULL;
    addrinfo hints =
    { };
    hints.ai_family = family;
    hints.ai_socktype = SOCK_DGRAM; // without this flag, getaddrinfo will return 3x the number of addresses (one for each socket type).
    result = getaddrinfo(hostname, service, &hints, &result_list);
    if (result == 0)
    {
        //ASSERT(result_list->ai_addrlen <= sizeof(sockaddr_in));
        memcpy(pAddr, result_list->ai_addr, result_list->ai_addrlen);
        freeaddrinfo(result_list);
    }

    return result;
}

static int sock;
static sockaddr_storage addrDest =
{ };

void drawBuffer(const std::vector<uint8_t>& buffer)
{

    sendto(sock, &buffer[0], buffer.size(), 0, (sockaddr*) &addrDest,
            sizeof(addrDest));
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    ITestEffect* effect = NULL;
    std::string selectedEffect = "default";
    if (argc == 2)
    {
        selectedEffect = argv[1];
    }

    if (selectedEffect == "default")
    {
        effect = new TestEffectDefault();
    }
    else if (selectedEffect == "font5x5")
    {
        effect = new TestEffectFont5x5();
    }
    else if (selectedEffect == "wandering")
    {
        effect = new TestEffectWandering();
    }
    else
    {
        fprintf(stdout, "Unknown effect \"%s\" selected.\n", selectedEffect.c_str());
        return 1;
    }

    effect->Reset(0);

    int result = 0;
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in addrListen =
    { }; // zero-int, sin_port is 0, which picks a random port for bind.
    addrListen.sin_family = AF_INET;
    result = bind(sock, (sockaddr*) &addrListen, sizeof(addrListen));
    if (result == -1)
    {
        int lasterror = errno;
        std::cout << "error: " << lasterror;
        exit(1);
    }

    result = resolvehelper("127.0.0.1", AF_INET, "4098", &addrDest);
    if (result != 0)
    {
        int lasterror = errno;
        std::cout << "error: " << lasterror;
        exit(1);
    }

    signal(SIGINT, siginthandler);

    fprintf(stdout, "Start loop.\n");

    DisplayBuffer buffer =
    {
        .width = 11,
        .height = 5,
        .pixels = (Color**)malloc(11 * 5 * sizeof(Color*))
    };

    for (int16_t x = 0; x < buffer.width * buffer.height; ++x)
    {
        buffer.pixels[x] = new Color;
    }

    std::vector<uint8_t> colorBuffer;
    colorBuffer.resize(buffer.width * buffer.height * 3);

    systime_t ticks = 0;
    while (run)
    {

        Color reset = {0, 0, 0};
        for (int16_t x = 0; x < buffer.width * buffer.height; ++x)
        {
            ColorCopy(&reset, buffer.pixels[x]);
        }

        effect->Update(ticks, buffer);
        for (int16_t x = 0; x < buffer.width; ++x)
        {
            for (int16_t y = 0; y < buffer.height; ++y)
            {
                uint16_t lednum = 0;
                if (DisplayCoordToLed(x, y, &lednum, &buffer) == true)
                {
                    uint16_t component = lednum * 3;
                    Color* col = buffer.pixels[lednum];
                    colorBuffer[component] = col->R;
                    colorBuffer[component + 1] = col->G;
                    colorBuffer[component + 2] = col->B;
                }
            }
        }

        drawBuffer(colorBuffer);

        usleep(10000);

        ticks += 10;
    }

    fprintf(stdout, "Stopped loop.\n");

    close(sock);

    delete effect;

    return 0;
}

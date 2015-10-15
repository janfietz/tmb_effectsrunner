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

static bool run = true;

void siginthandler(int param)
{
  run = false;
}

int resolvehelper(const char* hostname, int family, const char* service, sockaddr_storage* pAddr)
{
    int result;
    addrinfo* result_list = NULL;
    addrinfo hints = {};
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
static sockaddr_storage addrDest = {};

void drawBuffer(const std::vector<uint8_t>& buffer)
{

  sendto(sock, &buffer[0], buffer.size(), 0, (sockaddr*)&addrDest, sizeof(addrDest));
}

int main (int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stdout,"Usage: %s ledcount\n",argv[0]);
    return 1;
  }

  srand(time(NULL));

  int result = 0;
  sock = socket(AF_INET, SOCK_DGRAM, 0);

  sockaddr_in addrListen = {}; // zero-int, sin_port is 0, which picks a random port for bind.
  addrListen.sin_family = AF_INET;
  result = bind(sock, (sockaddr*)&addrListen, sizeof(addrListen));
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

  fprintf(stdout,"Start loop.\n");

  int ledcount = atoi(argv[1]);


  std::vector<uint8_t> colorBuffer;
  colorBuffer.resize(ledcount * 3);

  while (run)
  {
    for (size_t led = 0; led < colorBuffer.size(); ++led)
    {
      colorBuffer[led] = (uint8_t)(rand() % 256);
    }

    drawBuffer(colorBuffer);
    

    usleep(1000);
  }

  fprintf(stdout,"Stopped loop.\n");

  close(sock);
      
  return 0;
}
cmake_minimum_required (VERSION 2.6)
project (tmb_effectstest)


include_directories ("${PROJECT_SOURCE_DIR}/submodules/tmb_effects")

add_subdirectory("${PROJECT_SOURCE_DIR}/src")

add_subdirectory("${PROJECT_SOURCE_DIR}/submodules/tmb_effects")

add_executable(effectstest ${SOURCE})
target_link_libraries (effectstest effects)
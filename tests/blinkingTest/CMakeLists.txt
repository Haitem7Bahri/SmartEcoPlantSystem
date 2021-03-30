cmake_minimum_required(VERSION 3.13.4)
project(blinkingTest)


find_library( WIRINGPI_LIBRARIES wiringPi )
find_path( WIRINGPI_INCLUDE_DIRS NAMES "wiringPi.h" )
include_directories( ${WIRINGPI_INCLUDE_DIRS} )
message(STATUS "wiringPi: lib:${WIRINGPI_LIBRARIES}, incl:${WIRINGPI_INCLUDE_DIRS}")

add_executable(blinkingTest blinkingTest.cxx)
target_link_libraries(blinkingTest ${WIRINGPI_LIBRARIES})
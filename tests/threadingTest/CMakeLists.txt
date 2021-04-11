cmake_minimum_required(VERSION 3.13.4)
project(threadingTest)


find_library(WIRINGPI_LIBRARIES wiringPi )
find_path(WIRINGPI_INCLUDE_DIRS NAMES "wiringPi.h" )
include_directories(${WIRINGPI_INCLUDE_DIRS} )

find_library(THREADLIB_LIBRARIES pthread )
find_path(THREADLIB_INCLUDE_DIRS NAMES "pthread.h" )
include_directories(${THREADLIB_INCLUDE_DIRS} )


add_executable(threadingTest
	threadingTest.cpp
	blinkingConst.cpp
	blinkingVar.cpp

)
target_link_libraries(threadingTest ${WIRINGPI_LIBRARIES})
target_link_libraries(threadingTest ${THREADLIB_LIBRARIES})
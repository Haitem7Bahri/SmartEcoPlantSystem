cmake_minimum_required(VERSION 3.13.4)
project(SmartEcoPlantSystem)


find_library(WIRINGPI_LIBRARIES wiringPi )
find_path(WIRINGPI_INCLUDE_DIRS NAMES "wiringPi.h" )
include_directories(${WIRINGPI_INCLUDE_DIRS} )

find_library(THREADLIB_LIBRARIES pthread )
find_path(THREADLIB_INCLUDE_DIRS NAMES "pthread.h" )
include_directories(${THREADLIB_INCLUDE_DIRS} )


add_executable(SmartEcoPlantSystem
	src/Main.cpp
	src/mcp3008Spi.cpp
	src/moistureSensor.cpp
	src/tempSensor.cpp
	src/ventilatingSystem.cpp
	src/ventilatingSystemThread.cpp
	src/wateringSystem.cpp
	src/wateringSystemThread.cpp


)
target_link_libraries(SmartEcoPlantSystem ${WIRINGPI_LIBRARIES})
target_link_libraries(SmartEcoPlantSystem ${THREADLIB_LIBRARIES})
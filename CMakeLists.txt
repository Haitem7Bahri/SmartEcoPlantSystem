## setting min required version of cmake
cmake_minimum_required(VERSION 3.13.4)


## setting project name
project(SmartEcoPlantSystem)


## searching for wiringPi library
find_library(WIRINGPI_LIBRARIES wiringPi )
find_path(WIRINGPI_INCLUDE_DIRS NAMES "wiringPi.h" )
include_directories(${WIRINGPI_INCLUDE_DIRS} )


## searching for pthread library
find_library(THREADLIB_LIBRARIES pthread )
find_path(THREADLIB_INCLUDE_DIRS NAMES "pthread.h" )
include_directories(${THREADLIB_INCLUDE_DIRS} )


## adding required files to the compilation
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

## adding wiringPi library
target_link_libraries(SmartEcoPlantSystem ${WIRINGPI_LIBRARIES})


## adding pthread library
target_link_libraries(SmartEcoPlantSystem ${THREADLIB_LIBRARIES})
cmake_minimum_required(VERSION 3.13.4)
project(moistureSensorTest)

add_executable(moistureSensorTest
	moistureSensorTest.cpp
	mcp3008Spi.cpp
)

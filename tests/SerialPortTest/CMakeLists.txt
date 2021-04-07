cmake_minimum_required (VERSION 2.8)
project (Serial)

add_executable(main serialtest.cxx)
target_link_libraries(main ${WIRINGPI_LIBRARIES})
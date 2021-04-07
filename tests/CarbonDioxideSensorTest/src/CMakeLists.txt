aux_source_directory (. SRC_LIST)

include_directories (../include)

add_executable (main ${SRC_LIST})

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

target_link_libraries(main ${WIRINGPI_LIBRARIES})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

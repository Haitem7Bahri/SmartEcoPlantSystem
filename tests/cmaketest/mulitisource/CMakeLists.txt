cmake_minimum_required (VERSION 2.8)

project (demo)

set( SRC_LIST 
	./main.cxx
	./testFunc1.cxx
	./testFunc.cxx)

add_executable(main ${SRC_LIST})
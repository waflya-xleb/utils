cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling utils..." )

set ( CMAKE_CXX_STANDARD 23 )

project( utils
	VERSION 0.0.1
	LANGUAGES CXX )

add_library( ${PROJECT_NAME} SHARED utils.cpp terminal.cpp )
add_library( utils::utils ALIAS ${PROJECT_NAME} )

add_library( ${PROJECT_NAME}_terminal SHARED terminal.cpp )
add_library( utils::terminal ALIAS ${PROJECT_NAME}_terminal )

cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling utils..." )

set ( CMAKE_CXX_STANDARD 23 )

project( utils
	VERSION 0.0.1
	LANGUAGES CXX )

set ( LIBRARY_OUTPUT_PATH /home/eugene/FILES/Programming/Real\ Engine\ extended\ dev/Real\ Engine\ v0.0.0.1\ dev/bin/lib )# paste your project directory


add_library( ${PROJECT_NAME} SHARED utils.cpp terminal.cpp )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	PREFIX ""
	OUTPUT_NAME "utils"
	SUFFIX ".so"
)
add_library( utils::utils ALIAS ${PROJECT_NAME} )

add_library( ${PROJECT_NAME}_static STATIC utils.cpp terminal.cpp )
set_target_properties( ${PROJECT_NAME}_static PROPERTIES
	PREFIX "static_"
	OUTPUT_NAME "utils"
	SUFFIX ".a"
)
add_library( utils::static_utils ALIAS ${PROJECT_NAME}_static )

add_library( ${PROJECT_NAME}_terminal SHARED terminal.cpp )
set_target_properties( ${PROJECT_NAME}_terminal PROPERTIES
	PREFIX ""
	OUTPUT_NAME "utils_terminal"
	SUFFIX ".so"
)
add_library( utils::terminal ALIAS ${PROJECT_NAME}_terminal )

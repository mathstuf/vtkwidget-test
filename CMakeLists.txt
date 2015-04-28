project( BasicVTKPipeline )

cmake_minimum_required( VERSION 3.0 )

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

find_package(Qt5Widgets REQUIRED)

# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable( BasicVTKPipeline BasicVTKPipeline.cpp )
target_link_libraries( BasicVTKPipeline ${VTK_LIBRARIES} )


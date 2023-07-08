cmake_minimum_required(VERSION 3.25)
project(gdatum)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "**/*.cc")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        VERSION ${GDATUM_TARGET_VERSION}
        SOVERSION ${GDATUM_TARGET_VERSION})

#
# Boost
#
find_package(Boost 1.82.0 REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARIES})

#
# Glog
#
find_package(glog 0.6.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} glog::glog)
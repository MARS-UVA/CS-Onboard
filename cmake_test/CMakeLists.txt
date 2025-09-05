cmake_minimum_required(VERSION 3.8)
project(test)

find_package(realsense2 REQUIRED)
add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} realsense2::realsense2)

#also run linux command
#sudo sed -i '/include("${CMAKE_CURRENT_LIST_DIR}\/realsense2Targets.cmake")/i find_package(fastcdr REQUIRED)\nfind_package(fastrtps REQUIRED)' /usr/lib/x86_64-linux-gnu/cmake/realsense2/realsense2Config.cmake
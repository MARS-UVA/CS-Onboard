cmake_minimum_required(VERSION 3.8)
project(realsense)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(realsense2 2.56 REQUIRED)

add_executable(realsense_test src/motion_capture.cpp)

target_include_directories(realsense_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

target_compile_features(realsense_test PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17


set(dependencies 
  realsense2
  rclcpp
  std_msgs
)

target_link_libraries(realsense_test 

  realsense2::realsense2
  rclcpp::rclcpp
  ${std_msgs_TARGETS}
)

install(TARGETS realsense_test
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


ament_export_dependencies(${dependencies})
ament_package()

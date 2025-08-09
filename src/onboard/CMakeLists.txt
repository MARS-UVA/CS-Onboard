cmake_minimum_required(VERSION 3.8)
project(onboard)

#most of this is auto-generated with ros2 pkg create

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED) #require dependencies
find_package(std_msgs REQUIRED)

add_executable(example_node src/example_node.cpp)

target_include_directories(example_node PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

target_compile_features(example_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(example_node #attach dependencies to the executable
  rclcpp
  std_msgs
)


install(TARGETS example_node
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

ament_package()

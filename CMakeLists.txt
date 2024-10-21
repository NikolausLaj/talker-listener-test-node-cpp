cmake_minimum_required(VERSION 3.5)
project(test-talker-listener)

# Find necessary packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add executables for both talker and listener
add_executable(talker src/talker.cpp)
add_executable(listener src/listener.cpp)

# Link against dependencies
ament_target_dependencies(talker rclcpp std_msgs)
ament_target_dependencies(listener rclcpp std_msgs)

# Install both executables
install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()

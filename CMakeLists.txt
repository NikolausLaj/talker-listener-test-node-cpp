cmake_minimum_required(VERSION 3.5)   # Minimum version of CMake required
project(test-talker)        # Name of your ROS 2 package

# Find all required packages
find_package(ament_cmake REQUIRED)    # Required for building ROS 2 packages
find_package(rclcpp REQUIRED)         # Required for ROS 2 C++ API
find_package(std_msgs REQUIRED)       # Standard ROS 2 messages

# Declare the executable
add_executable(talker src/talker.cpp)

# Link against the required libraries
ament_target_dependencies(talker rclcpp std_msgs)

# Install the executable
install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

# Mark the package
ament_package()

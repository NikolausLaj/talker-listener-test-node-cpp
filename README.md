
# ROS 2 Test-Talker-Listener Package

This package contains simple ROS 2 nodes for testing the publish-subscribe communication model. The `talker` node publishes messages on a topic, and the `listener` node subscribes to that topic to receive and print those messages.

## Package Overview

- **talker**: A publisher node that sends a string message (`"Hello, ROS 2!"`) to a topic called `/test_topic` every second.
- **listener**: A subscriber node that listens to the `/test_topic` topic and prints the messages received.

## Nodes

### Talker Node

- **Executable**: `talker`
- **Description**: This node publishes a message of type `std_msgs/String` to the `/test_topic` topic.
- **Topic Published**: `/test_topic`
- **Message Type**: `std_msgs/String`
  
  **Talker Code**: [talker.cpp](src/talker.cpp)

### Listener Node

- **Executable**: `listener`
- **Description**: This node subscribes to the `/test_topic` topic and prints the received messages.
- **Topic Subscribed**: `/test_topic`
- **Message Type**: `std_msgs/String`
  
  **Listener Code**: [listener.cpp](src/listener.cpp)

## Building the Package

To build the package, navigate to the root of your ROS 2 workspace and run:

```bash
colcon build
```

## Running the Nodes

### 1. Run the Talker Node

In one terminal, source your workspace and run the `talker` node:

```bash
source install/setup.bash
ros2 run test-talker-listener talker
```

### 2. Run the Listener Node

In another terminal, source your workspace and run the `listener` node:

```bash
source install/setup.bash
ros2 run test-talker-listener listener
```

### Expected Output

- **Talker Terminal**: The `talker` node will publish messages and print something like:

  ```
  [INFO] [<timestamp>]: Publishing: 'Hello, ROS 2!'
  ```

- **Listener Terminal**: The `listener` node will receive the messages and print something like:

  ```
  [INFO] [<timestamp>]: I heard: 'Hello, ROS 2!'
  ```

## Dependencies

This package depends on the following ROS 2 packages:
- `rclcpp`: The ROS 2 C++ client library.
- `std_msgs`: Standard message types, including `std_msgs/String`.

## License

This project is licensed under the Apache 2.0 License.

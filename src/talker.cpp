#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
    Talker() : Node("talker_node")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("test_topic", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&Talker::publish_message, this));
        RCLCPP_INFO(this->get_logger(), "Talker node has been started.");
    }

private:
    void publish_message()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, ROS 2 from C++!";
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Talker>());
    rclcpp::shutdown();
    return 0;
}

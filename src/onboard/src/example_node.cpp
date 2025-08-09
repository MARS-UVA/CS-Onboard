
#include <cstdio>
#include <rclcpp/node.hpp>
#include <rclcpp/node_options.hpp>
#include <rclcpp/rclcpp.hpp>
#include <string>
#include <chrono>
#include <std_msgs/msg/string.hpp>

using namespace::std::chrono_literals;

class ExampleNode : public rclcpp::Node {
  public:
    ExampleNode() : rclcpp::Node("example_publisher") {
      example_publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
        500ms, std::bind(&ExampleNode::timer_callback, this));

    }
  private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr example_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "hi";
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      example_publisher_->publish(message);
    }
    
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ExampleNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  printf("publishing \"hi\" to \"topic\" every 500ms");
  return 0;
}

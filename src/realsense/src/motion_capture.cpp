#include <cstdio>
#include <rclcpp/node.hpp>
#include <rclcpp/node_options.hpp>
#include "rclcpp/rclcpp.hpp"
#include <string>
#include <chrono>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/string.hpp>
#include <iostream>

#include <librealsense2/rs.hpp>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace::std::chrono_literals;

class RSNode : public rclcpp::Node {
    public:
        public:
        RSNode()
        : Node("rs_node") {
            std::cout << ("Started constructor\n");
            example_publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
            printf("Made publisher\n");
            timer_ = this->create_wall_timer(
            500ms, std::bind(&RSNode::timer_callback, this));
        }

        void startPipeline() {
            printf("pipeline test start\n");
            rs2::context ctx;
            auto list = ctx.query_devices();
            if (list.size() == 0) {
                RCLCPP_ERROR(this->get_logger(), "No RealSense devices found");
                return;
            }

            try {
                pipeline_ = std::make_unique<rs2::pipeline>();
                rs2::config cfg;
                // cfg.enable_stream(RS2_STREAM_DEPTH, 848, 480, RS2_FORMAT_Z16, 30);
                cfg.enable_stream(RS2_STREAM_COLOR, 1280, 720, RS2_FORMAT_RGB8, 30);
                pipeline_->start(cfg);
            } catch (const rs2::error & e) {
                RCLCPP_ERROR(this->get_logger(),
                            "Failed to start RealSense pipeline: %s", e.what());
            }
        }

    private:
        std::unique_ptr<rs2::pipeline> pipeline_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr example_publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        void timer_callback()
        {
            printf("waiting for frame\n");
            rs2::frameset frame = pipeline_->wait_for_frames();
            printf("frame received\n");
            auto message = std_msgs::msg::String();
            message.data = "publishing";
            example_publisher_->publish(message);
        }
};

int main(int argc, char ** argv)
{
    std::cout << ("Started main\n");
    rclcpp::init(argc, argv);
    std::cout << ("Initialized ROS\n");
    // RSNode node = RSNode();
    // auto node = rclcpp::Node("example_publisher");
    auto node = std::make_shared<RSNode>();
    std::cout << "Starting pipeline 0\n";
    node->startPipeline();
    // node.startPipeline();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
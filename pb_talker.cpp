#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "publish_info.pb.h"
#include "ros/ros.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher proto_pub =
      n.advertise<superbai::sample::PublishInfo>("/test_superbai", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    superbai::sample::PublishInfo proto_msg_info;
    proto_msg_info.set_name("superbai");
    proto_msg_info.set_message_type("ros_protobuf");
    proto_msg_info.set_publish_msg("superbai is a bilibili up");

    proto_pub.publish(proto_msg_info);
    std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
#include "ros/ros.h"
#include "msg_to_csv.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "data_processing_node");
	ros::NodeHandle nh;

    // Create instances for processing each topic data
    std::string topic_name1 = "steer_position_cmd_out";
    MsgToCSV topic1(&nh, &topic_name1);

    std::string topic_name2 = "steer_position_out";
    MsgToCSV topic2(&nh, &topic_name2);

    std::string topic_name3 = "lh_tire_position_out";
    MsgToCSV topic3(&nh, &topic_name3);

    std::string topic_name4 = "rh_tire_position_out";
    MsgToCSV topic4(&nh, &topic_name4);

    std::string topic_name5 = "motor_position_cmd_in";
    MsgToCSV topic5(&nh, &topic_name5);

	while (ros::ok()) {
		ros::spinOnce();
	}

	return 0;
}
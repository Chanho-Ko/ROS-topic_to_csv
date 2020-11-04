#include "iostream"
#include "se88_socketcan_bridge/Float32stamped.h"
#include "can_msgs/Frame.h"
#include "string"
#include "fstream"

class MsgToCSV
{
private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    std::string topic_name_;
    std::string file_name_;
    

public:
    MsgToCSV(ros::NodeHandle* nodehandle, const std::string* topic_name);
    void msgCallback(const se88_socketcan_bridge::Float32stamped::ConstPtr& msg);
};

MsgToCSV::MsgToCSV(ros::NodeHandle* nodehandle, const std::string* topic_name) : nh_(*nodehandle)
{
    topic_name_ = *topic_name; 
    sub_ = nh_.subscribe(topic_name_, 1, &MsgToCSV::msgCallback, this);

}

void MsgToCSV::msgCallback(const se88_socketcan_bridge::Float32stamped::ConstPtr& msg)
{
    //std::cout << topic_name_ << " is received!" << std::endl;

    //############### Write data in .csv ###################
    file_name_ = topic_name_ + ".csv";
    std::ofstream writeFile(file_name_, std::ios::app);
    if (writeFile.is_open())
    {
        writeFile << msg->stamp << " " << msg->data << std::endl;
        std::cout << file_name_ << " is writted!" << std::endl;
    }

}

# ROS-topic_to_csv
This ROS package is for writing a .csv file from topic messages.

  1. Clone to your catkin workspace and build it.
  2. Change dependencies for topic message which you want to write.
  3. Edit message type of callback function in [the header file](./include/msg_to_csv.h).
  4. Take instances in the source file for any topics you want to write.s

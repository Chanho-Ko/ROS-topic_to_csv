cmake_minimum_required(VERSION 3.0.2)
project(data_processing)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  can_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp std_msgs can_msgs
)
include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_executable(data_processing_node src/data_processing.cpp)
add_dependencies(data_processing_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(data_processing_node ${catkin_LIBRARIES})

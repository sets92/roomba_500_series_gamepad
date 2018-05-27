cmake_minimum_required(VERSION 2.8.3)
project(roomba_500_series_gamepad)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  sensor_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package()

add_executable(${PROJECT_NAME}_node src/main.cpp src/roomba_gamepad.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})

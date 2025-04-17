#!/bin/bash
set -e  # Exit immediately if a command exits with a non-zero status

# Source ROS 2 and workspace setup
source /opt/ros/humble/setup.bash
source /ros2_ws/install/setup.bash

echo "Starting Zenoh middleware..."
ros2 run rmw_zenoh_cpp rmw_zenohd &  # Run in background
ZENOH_PID=$!  # Store the Zenoh process ID

# Wait for Zenoh to initialize
sleep 2

echo "Launching Spot ROS 2 driver..."
exec ros2 launch spot_driver spot_driver.launch.py config_file:=/ros2_ws/src/robot.yaml \
  spot_name:=${SPOT_NAME} launch_rviz:=False publish_point_coud:=False
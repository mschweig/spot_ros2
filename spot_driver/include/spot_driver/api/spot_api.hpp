// Copyright (c) 2023 Boston Dynamics AI Institute LLC. All rights reserved.

#pragma once

#include <spot_driver/api/kinematic_api.hpp>
#include <spot_driver/api/state_client_interface.hpp>
#include <spot_driver/api/time_sync_api.hpp>
#include <spot_driver/interfaces/image_client_interface.hpp>
#include <tl_expected/expected.hpp>

#include <memory>
#include <string>

namespace spot_ros2 {

class SpotApi {
 public:
  virtual ~SpotApi() = default;

  virtual tl::expected<void, std::string> createRobot(const std::string& ip_address, const std::string& robot_name) = 0;
  virtual tl::expected<void, std::string> authenticate(const std::string& username, const std::string& password) = 0;
  virtual tl::expected<bool, std::string> hasArm() const = 0;
  virtual std::shared_ptr<KinematicApi> kinematicApi() const = 0;
  virtual std::shared_ptr<ImageClientInterface> image_client_interface() const = 0;

  /**
   * @brief Get a StateClientInterface that communicates with Spot's robot state server.
   * @return A shared_ptr to an instance of StateClientInterface which is owned by this object.
   */
  virtual std::shared_ptr<StateClientInterface> stateClientInterface() const = 0;
  virtual std::shared_ptr<TimeSyncApi> timeSyncInterface() const = 0;
};
}  // namespace spot_ros2

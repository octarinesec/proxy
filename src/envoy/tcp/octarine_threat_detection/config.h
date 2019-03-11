/* Copyright 2018 Istio Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "envoy/server/filter_config.h"

namespace Envoy {
namespace Tcp {
namespace ThreatDetection {

/**
 * Config registration for the OctarineThreatDetection filter. @see
 * NamedNetworkFilterConfigFactory.
 */
class ThreatDetectionConfigFactory
    : public Server::Configuration::NamedNetworkFilterConfigFactory {
 public:
  // NamedNetworkFilterConfigFactory
  Network::FilterFactoryCb createFilterFactory(
      const Json::Object&,
      Server::Configuration::FactoryContext& context) override;

  Network::FilterFactoryCb createFilterFactoryFromProto(
      const Protobuf::Message&,
      Server::Configuration::FactoryContext& context) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override;

  std::string name() override { return "octarine.threat_detection"; }

 private:
  Network::FilterFactoryCb createFilterFactoryFromContext(
      Server::Configuration::FactoryContext& context);
};

}  // namespace ThreatDetection
}  // namespace Tcp
}  // namespace Envoy
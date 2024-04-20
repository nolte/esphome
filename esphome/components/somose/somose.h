#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace somose {

/// This class implements support for the i2c-based SoMoSe ambient light sensor.
class SoMoSeComponent : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
 public:
  // ========== INTERNAL METHODS ==========
  // (In most use cases you won't need these)
  void setup() override;
  void dump_config() override;
  void update() override;
  float get_setup_priority() const override;

  void set_temperature_sensor(sensor::Sensor *temperature_sensor) { this->temperature_sensor_ = temperature_sensor; }
  void set_moisture_sensor(sensor::Sensor *moisture_sensor) { this->moisture_sensor_ = moisture_sensor; }


 protected:
  // int readline_(int readch, char *buffer, int len);
  unsigned read_count_{};
  void read_data_();
  void restart_read_();

  sensor::Sensor *moisture_sensor_{nullptr};
  sensor::Sensor *temperature_sensor_{nullptr};
  

  uint32_t start_time_{0};
};

}  // namespace somose
}  // namespace esphome

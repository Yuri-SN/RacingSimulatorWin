#include "VehicleGround.h"

VehicleGround::VehicleGround(const std::string &name, int speed, int movingTime)
    : m_speed(speed), m_movementTime(movingTime) {

    m_name = name;
}

bool VehicleGround::isTypeAir() const { return false; }

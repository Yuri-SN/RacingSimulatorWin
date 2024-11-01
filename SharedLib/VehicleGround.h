#pragma once

#include "Vehicle.h"

class VehicleGround : public Vehicle {
public:
    VehicleGround(const std::string &name, int speed, int movementTime);

    bool isTypeAir() const override;

protected:
    int m_speed{};
    int m_movementTime{};
};

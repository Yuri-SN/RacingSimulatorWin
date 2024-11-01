#pragma once

#include "Vehicle.h"

class VehicleAir : public Vehicle {

public:
    VehicleAir(const std::string &name, int speed);

    bool isTypeAir() const override;

protected:
    int m_speed{};
    double m_distanceReductionFactor{};
};

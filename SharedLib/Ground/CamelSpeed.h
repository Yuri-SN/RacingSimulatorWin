#pragma once

#include "../VehicleGround.h"

class CamelSpeed : public VehicleGround {
public:
    CamelSpeed();

    double calculateTotalTime(int distance) override;
};

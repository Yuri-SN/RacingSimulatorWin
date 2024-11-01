#pragma once

#include "../VehicleGround.h"

class Camel : public VehicleGround {
public:
    Camel();

    double calculateTotalTime(int distance) override;
};

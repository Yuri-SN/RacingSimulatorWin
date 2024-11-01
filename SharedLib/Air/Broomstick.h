#pragma once

#include "../VehicleAir.h"

class Broomstick : public VehicleAir {
public:
    Broomstick();

    virtual double calculateTotalTime(int distance) override;
};

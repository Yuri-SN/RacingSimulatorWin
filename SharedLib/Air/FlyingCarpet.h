#pragma once

#include "../VehicleAir.h"

class FlyingCarpet : public VehicleAir {
public:
    FlyingCarpet();

    virtual double calculateTotalTime(int distance) override;
};

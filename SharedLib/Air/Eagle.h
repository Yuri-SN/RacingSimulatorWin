#pragma once

#include "../VehicleAir.h"

class Eagle : public VehicleAir {
public:
    Eagle();

    virtual double calculateTotalTime(int distance) override;
};

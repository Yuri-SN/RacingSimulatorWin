#pragma once

#include "../VehicleGround.h"

class Centaur : public VehicleGround {
public:
    Centaur();

    double calculateTotalTime(int distance) override;
};

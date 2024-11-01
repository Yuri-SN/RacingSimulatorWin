#pragma once

#include "../VehicleGround.h"

class AllTerrainBoots : public VehicleGround {
public:
    AllTerrainBoots();

    double calculateTotalTime(int distance) override;
};

#pragma once

#include "Vehicle.h"
#include "RaceType.h"
#include "VehicleResult.h"

#include <vector>

class Race {
public:
    Race();

    // Очищает все данные между гонками
    void clean();

    bool setRaceType(int type);
    bool setRaceDistance(int distance);

    size_t getVehiclesCount();

    std::vector<std::string> getAvailableVahicles();

    std::string getRaceParams();
    std::string getRegisteredVehicles();

    std::string registerVehicle(int vehicleIndex);

    std::vector<VehicleResult> calculateResult();

private:
    bool isVehicleTypeAceptable(Vehicle *);

    std::vector<Vehicle *> m_availableVehicles{};
    std::vector<Vehicle *> m_registeredVehicles{};

    RaceType m_raceType{};
    int m_raceDistance{};
};

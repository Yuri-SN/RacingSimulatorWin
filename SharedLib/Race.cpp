#include "Race.h"
#include "Air/Broomstick.h"
#include "Air/Eagle.h"
#include "Air/FlyingCarpet.h"
#include "Ground/AllTerrainBoots.h"
#include "Ground/Camel.h"
#include "Ground/CamelSpeed.h"
#include "Ground/Centaur.h"
#include <algorithm>

Race::Race() {
    m_availableVehicles.push_back(new AllTerrainBoots());
    m_availableVehicles.push_back(new Broomstick());
    m_availableVehicles.push_back(new Camel());
    m_availableVehicles.push_back(new Centaur());
    m_availableVehicles.push_back(new Eagle());
    m_availableVehicles.push_back(new CamelSpeed());
    m_availableVehicles.push_back(new FlyingCarpet());
}

void Race::clean() {
    m_registeredVehicles = {};
    m_raceType = {};
    m_raceDistance = 0;
}

bool Race::setRaceType(int type) {
    bool result{};
    RaceType raceTypeEnum = static_cast<RaceType>(type);

    switch (raceTypeEnum) {
    case RaceType::AIR:
    case RaceType::GROUND:
    case RaceType::GROUND_AND_AIR:
        m_raceType = raceTypeEnum;
        result = true;
        break;
    default:
        result = false;
        break;
    }

    return result;
}

bool Race::setRaceDistance(int distance) {
    if (distance > 0) {
        m_raceDistance = distance;
        return true;
    } else {
        return false;
    }
}

size_t Race::getVehiclesCount() { return m_registeredVehicles.size(); }

std::vector<std::string> Race::getAvailableVahicles() {
    std::vector<std::string> result{};

    for (auto const vehicle : m_availableVehicles) {
        result.push_back(vehicle->getName());
    }

    return result;
}

std::string Race::getRaceParams() {
    std::string result{};

    switch (m_raceType) {
    case RaceType::GROUND:
        result = "Гонка для наземного транспорта. ";
        break;
    case RaceType::AIR:
        result = "Гонка для воздушного транспорта. ";
        break;
    case RaceType::GROUND_AND_AIR:
        result = "Гонка для наземного и воздушного транспорта. ";
        break;
    default:
        result = "Ошибка. ";
        break;
    }

    result = result + "Расстояние: " + std::to_string(m_raceDistance);

    return result;
}

std::string Race::getRegisteredVehicles() {
    std::string result{};

    if (!m_registeredVehicles.empty()) {
        result = "Зарегистрированные транспортные средства: ";

        for (auto vehicle : m_registeredVehicles) {
            result += vehicle->getName();

            if (vehicle != m_registeredVehicles.back()) {
                result += ", ";
            }
        }
    }

    return result;
}

std::string Race::registerVehicle(int vehicleIndex) {
    std::string result{};

    Vehicle *selectedVehicle = m_availableVehicles.at(vehicleIndex);

    if (isVehicleTypeAceptable(selectedVehicle)) {
        auto it = std::find(m_registeredVehicles.begin(),
                            m_registeredVehicles.end(), selectedVehicle);

        if (it != m_registeredVehicles.end()) {
            result += selectedVehicle->getName() + " уже зарегистрирован!";
        } else {
            result += selectedVehicle->getName() + " успешно зарегистрирован!";
            m_registeredVehicles.push_back(selectedVehicle);
        }
    } else {
        result +=
            "Попытка зарегистрировать неправильный тип транспортного средства!";
    }

    return result;
}

std::vector<VehicleResult> Race::calculateResult() {
    std::vector<VehicleResult> results{};

    for (auto *vehicle : m_registeredVehicles) {
        results.push_back({vehicle->getName(), vehicle->calculateTotalTime(m_raceDistance)});
    }

    std::sort(results.begin(), results.end(),
              [](const auto &a, const auto &b) { return a.time < b.time; });

    return results;
}

bool Race::isVehicleTypeAceptable(Vehicle *vehicle) {
    if (vehicle->isTypeAir() &&
        (m_raceType == RaceType::AIR || m_raceType == RaceType::GROUND_AND_AIR)) {
        return true;
    };

    if (!vehicle->isTypeAir() && (m_raceType == RaceType::GROUND ||
                                  m_raceType == RaceType::GROUND_AND_AIR)) {
        return true;
    };

    return false;
}

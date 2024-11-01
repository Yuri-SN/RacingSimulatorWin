#include "VehicleAir.h"

VehicleAir::VehicleAir(const std::string &name, int speed) : m_speed{speed} {
    m_name = name;
}

bool VehicleAir::isTypeAir() const { return true; }

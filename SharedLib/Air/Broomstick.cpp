#include "Broomstick.h"

#include <cmath>

Broomstick::Broomstick() : VehicleAir("Метла", 20) {}

double Broomstick::calculateTotalTime(int distance) {
    // Фактор уменьшения расстояния (увеличивается на 1% за каждые 1000км)
    const double reductionFactor = 0.01;

    // Расчет уменьшенного расстояния
    double effectiveDistance =
        distance * (1 - reductionFactor * ceil(distance / 1000));

    // Общее время прохождения гонки
    double totalTime = effectiveDistance / m_speed;

    return totalTime;
}

#include "Eagle.h"

Eagle::Eagle() : VehicleAir("Орёл", 8) {}

double Eagle::calculateTotalTime(int distance) {
    // Фиксированный фактор уменьшения расстояния (6%)
    const double reductionFactor = 0.06;

    // Расчет уменьшенного расстояния
    double effectiveDistance = distance * (1 - reductionFactor);

    // Общее время прохождения гонки
    double totalTime = effectiveDistance / m_speed;

    return totalTime;
}

#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet() : VehicleAir("Ковёр-самолёт", 10) {}

double FlyingCarpet::calculateTotalTime(int distance) {
    // Расчёт уменьшения расстояния
    double reductionFactor = 0.0;
    if (distance < 1000) {
        reductionFactor = 0.0;
    } else if (distance < 5000) {
        reductionFactor = 0.03;
    } else if (distance < 10000) {
        reductionFactor = 0.10;
    } else {
        reductionFactor = 0.05;
    }

    // Расчёт уменьшенного расстояния
    double effectiveDistance = distance * (1 - reductionFactor);

    // Общее время прохождения гонки
    double totalTime = effectiveDistance / m_speed;

    return totalTime;
}

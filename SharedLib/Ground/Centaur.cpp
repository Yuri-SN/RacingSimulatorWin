#include "Centaur.h"

Centaur::Centaur() : VehicleGround("Кентавр", 15, 8) {}

double Centaur::calculateTotalTime(int distance) {
    const int restDuration = 2; // Длительность отдыха (ч)

    // Общее время движения без учета отдыха
    double totalTime = distance / m_speed;

    // Количество перерывов
    int breaks = static_cast<int>(totalTime / m_movementTime);

    // Проверяем, нужно ли делать последний отдых или путь будет пройден до конца
    if (static_cast<int>(totalTime) % m_movementTime == 0) {
        // Остатка нет, значит последний отдых не требуется
        breaks--;
    }

    // Добавление времени отдыха
    for (int i{0}; i < breaks; ++i) {
        totalTime += restDuration;
    }

    return totalTime;
}

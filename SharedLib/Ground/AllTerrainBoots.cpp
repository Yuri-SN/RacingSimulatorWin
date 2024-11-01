#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots()
    : VehicleGround("Ботинки-вездеходы", 6, 60) {}

double AllTerrainBoots::calculateTotalTime(int distance) {
    const int firstRestDuration = 10;     // Длительность первого отдыха (ч)
    const int subsequentRestDuration = 5; // Длительность последующих отдыхов (ч)

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
        if (i == 0) {
            totalTime += firstRestDuration;
        } else {
            totalTime += subsequentRestDuration;
        }
    }

    return totalTime;
}

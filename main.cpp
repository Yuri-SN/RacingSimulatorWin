#include <Windows.h>
#include <iostream>
#include "SharedLib/Race.h"

int const MIN_VEHICLES{2};

void showRegisterHint() {
    std::cout << "Должно быть зарегистрировано хотя бы " << MIN_VEHICLES
        << " транспортных средства" << std::endl;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

    Race* race = new Race();

    int raceType{};
    int raceDistance{};
    int registrationMenuitem{};
    int anotherRaceMenuitem{};

    bool exitApp{};
    bool raceTypeCorrect{};
    bool raceDistanceCorrect{};
    bool raceRegistrationComplete{};
    bool raceAddVehicleComplete{};
    bool raceReady{};

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

    do {
        raceRegistrationComplete = false;

        race->clean();

        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        // Указываем тип гонки
        do {
            std::cout << "Выберите тип гонки: ";
            std::cin >> raceType;

            raceTypeCorrect = race->setRaceType(raceType);

            if (!raceTypeCorrect) {
                std::cout << "Неверный тип гонки" << std::endl;
            }
        } while (!raceTypeCorrect);

        // Указываем дистанцию
        do {
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> raceDistance;

            raceDistanceCorrect = race->setRaceDistance(raceDistance);

            if (!raceDistanceCorrect) {
                std::cout << "Неверное значение" << std::endl;
            }
        } while (!raceDistanceCorrect);

        // Регистрируем транспорт
        do {
            if (race->getVehiclesCount() == 0) {
                showRegisterHint();
            }

            raceReady = race->getVehiclesCount() >= MIN_VEHICLES;

            std::cout << "1. Зарегистрировать транспорт" << std::endl;

            if (race->getVehiclesCount() >= MIN_VEHICLES) {
                std::cout << "2. Начать гонку" << std::endl;
            }

            std::cout << "Выберите действие: ";
            std::cin >> registrationMenuitem;

            if (registrationMenuitem != 1 && registrationMenuitem != 2) {
                std::cout << "Неверное значение" << std::endl;
            }

            if (registrationMenuitem == 2 && !raceReady) {
                std::cout << "Неверное значение" << std::endl;
            }

            if (registrationMenuitem == 2 && raceReady) {
                raceRegistrationComplete = true;
            }

            if (registrationMenuitem == 1) {
                raceAddVehicleComplete = false;
                std::vector<std::string> availableVahicles =
                    race->getAvailableVahicles();
                int vehicleMenuitem{};

                do {
                    std::cout << race->getRaceParams() << std::endl;

                    if (race->getVehiclesCount() > 0) {
                        std::cout << race->getRegisteredVehicles() << std::endl;
                    }

                    for (int i{}; i < availableVahicles.size(); ++i) {
                        std::cout << i + 1 << ". " << availableVahicles.at(i) << std::endl;
                    }
                    std::cout << "0. Закончить регистрацию" << std::endl;

                    std::cout << "Выберите транспорт или 0 для окончания процесса "
                        "регистрации: ";
                    std::cin >> vehicleMenuitem;

                    if (vehicleMenuitem < 0 &&
                        vehicleMenuitem > availableVahicles.size()) {
                        std::cout << "Неверное значение" << std::endl;
                    }
                    else if (vehicleMenuitem == 0) {
                        raceAddVehicleComplete = true;
                    }
                    else {
                        std::cout << race->registerVehicle(vehicleMenuitem - 1)
                            << std::endl;
                    }
                } while (!raceAddVehicleComplete);
            }
        } while (!raceRegistrationComplete);

        auto raceResult = race->calculateResult();

        std::cout << std::endl;
        std::cout << "Результаты гонки:" << std::endl;
        for (int i{ 0 }; i < raceResult.size(); ++i) {
            std::cout << i + 1 << ". " << raceResult.at(i).name
                << ". Время: " << raceResult.at(i).time << std::endl;
        }
        std::cout << std::endl;

        bool anotherRaceMenuitemCorrect{};

        do {
            std::cout << "1. Провести ещё одну гонку" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> anotherRaceMenuitem;

            anotherRaceMenuitemCorrect =
                anotherRaceMenuitem == 1 || anotherRaceMenuitem == 2;

            if (!anotherRaceMenuitemCorrect) {
                std::cout << "Неверное значение" << std::endl;
            }
        } while (!anotherRaceMenuitemCorrect);

        if (anotherRaceMenuitem == 2) {
            exitApp = true;
        }
    } while (!exitApp);

    delete race;

    return 0;
}

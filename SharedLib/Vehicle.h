#pragma once

#include <string>

class Vehicle {
public:
    virtual ~Vehicle() {}

    virtual double calculateTotalTime(int distance) = 0;

    virtual bool isTypeAir() const = 0;

    std::string getName() const;

protected:
    std::string m_name{};
};

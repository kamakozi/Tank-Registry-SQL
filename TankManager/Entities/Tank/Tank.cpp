//
// Created by ziga zoric on 18.05.25.
//
#include <string>
#include "Tank.h"

Tank::Tank(std::string name, std::string creationYear, std::string country): name(std::move(name)), creationYear(std::move(creationYear)),country(std::move(country)) {
}

std::string Tank::getName() const {
    return name;
}
std::string Tank::getCountry() const {
    return country;
}

std::string Tank::getCreationYear() const {
    return creationYear;
}

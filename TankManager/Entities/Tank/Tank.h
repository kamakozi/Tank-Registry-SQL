
#ifndef TANK_H
#define TANK_H
#include <string>


class Tank {
protected:
    std::string name;
    std::string creationYear;
    std::string country;

public:
    Tank(std::string name,std::string creationYear,std::string country);
    [[nodiscard]] std::string getName()const;
    [[nodiscard]] std::string getCreationYear()const;
    [[nodiscard]] std::string getCountry()const;
};



#endif //TANK_H

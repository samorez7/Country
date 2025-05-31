#pragma once
#include <string>
#include <vector>

class City {
private:
    std::string name;
    int population;

public:
    City(const std::string& name, int population);

    std::string getName() const;
    int getPopulation() const;
};

class Country {
private:
    std::vector<City> cities;

public:
    void addCity(const City& city);
    void removeCity(const std::string& name);
    void printCities() const;
};

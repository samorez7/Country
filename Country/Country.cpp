#include "Country.h"
#include <iostream>

// --- City ---

City::City(const std::string& name, int population)
    : name(name), population(population) {
}

std::string City::getName() const {
    return name;
}

int City::getPopulation() const {
    return population;
}

// --- Country ---

void Country::addCity(const City& city) {
    cities.push_back(city);
}

void Country::removeCity(const std::string& name) {
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        if (it->getName() == name) {
            cities.erase(it);
            std::cout << "City \"" << name << "\" has been removed.\n";
            return;
        }
    }
    std::cout << "City \"" << name << "\" not found.\n";
}

void Country::printCities() const {
    std::cout << "Cities in the country:\n";
    for (const auto& city : cities) {
        std::cout << " - " << city.getName()
            << ", Population: " << city.getPopulation() << "\n";
    }
}

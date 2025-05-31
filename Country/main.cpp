#include <iostream>
#include <limits>
#include "Country.h"

void showMenu() {
    std::cout << "\n--- Country Management Menu ---\n";
    std::cout << "1. Add a city\n";
    std::cout << "2. Remove a city\n";
    std::cout << "3. Show all cities\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Country country;

    // Додаємо 8 міст на старті
    country.addCity(City("Kyiv", 2900000));
    country.addCity(City("Lviv", 720000));
    country.addCity(City("Odesa", 1010000));
    country.addCity(City("Dnipro", 980000));
    country.addCity(City("Kharkiv", 1500000));
    country.addCity(City("Zaporizhzhia", 730000));
    country.addCity(City("Vinnytsia", 370000));
    country.addCity(City("Chernihiv", 285000));

    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            std::string name;
            int population;

            std::cout << "Enter city name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Enter population: ";
            std::cin >> population;

            country.addCity(City(name, population));
            std::cout << "City added.\n";

        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Enter city name to remove: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            country.removeCity(name);

        }
        else if (choice == 3) {
            country.printCities();

        }
        else if (choice == 4) {
            std::cout << "Exiting.\n";
            break;

        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}

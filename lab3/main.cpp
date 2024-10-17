// Вариант 22

#include <iostream>
#include <memory>
#include <limits>

#include "include/pentagon.hpp"
#include "include/hexagon.hpp"
#include "include/octagon.hpp"
#include "include/array.hpp"

void printMenu() {
    std::cout << "Menu:\n"
              << "1. Add pentagon figure\n"
              << "2. Add hexagon figure\n"
              << "3. Add octagon figure\n"
              << "4. Show figures info\n"
              << "5. Calculate total figure area\n"
              << "6. Remove figure by index\n"
              << "7. Exit\n"
              << "your choice: ";
}

Pentagon* createPentagon() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    std::cout << "Input 5 coordinates for pentagon figure (format: x, y)";

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;

    if (!std::cin) {
            std::cerr << "Incorrect input. Try again\n";
        return nullptr;
    }

    return new Pentagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
}

Hexagon* createHexagon() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

    std::cout << "Input 6 coordinates for hexagon figure (format: x, y)";

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    if (!std::cin) {
            std::cerr << "Incorrect input. Try again\n";
        return nullptr;
    }
    
    return new Hexagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6);
}

Octagon* createOctagon() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;

    std::cout << "Input 6 coordinates for hexagon figure (format: x, y)";

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7 >> x8 >> y8;

    if (!std::cin) {
            std::cerr << "Incorrect input. Try again\n";
        return nullptr;
    }
    
    return new Octagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8);
}

void printAllFigures(const Array& array) {
    std::cout << "\nAll figures:\n";
    array.getCoordinates(std::cout);
}

void printTotalArea(const Array& array) {
    std::cout << "Figures' total area : " << array.getFigureAreaSum() << "\n";
}

void deleteFigure(Array& array) {
    int index;
    std::cout << "Input index for delete: ";
    std::cin >> index;

    array.remove(index);
    std::cout << "The figure was removed successfully.\n";
}

int main() {
    /*int s;
    std::cout << "Input array size: ";
    std::cin >> s;

    if (!std::cin || s <= 0) {
        std::cerr << "Oopss..... Incorrect array size.\n";
        return 1;
    }

    Array array(s);
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        if (!std::cin) {
            std::cerr << "Incorrect input. Try again\n";
            continue;
        }

        switch (choice) {
            case 1: {
                Pentagon* penta = createPentagon();

                if (penta) {
                    array.add(penta);
                    std::cout << "The pentagon figure wsa added\n";
                }

                break;
            }
            case 2: {
                Hexagon* hexa = createHexagon();
                if (hexa) {
                    array.add(hexa);
                    std::cout << "The hexagon figure wsa added\n";
                }
                break;
            }
            case 3: {
                Octagon* octa = createOctagon();
                if (octa) {
                    array.add(octa);
                    std::cout << "The octagon figure wsa added\n";
                }
                break;
            }
            case 4:
                printAllFigures(array);
                break;
            case 5:
                printTotalArea(array);
                break;
            case 6:
                deleteFigure(array);
                break;
            case 7:
                std::cout << "Exit\n";
                break;
            default:
                std::cerr << "Incorrect input, wrong choice. Try again\n";
        }
    } while (choice != 7);*/

    Hexagon hexa = Hexagon(1, 0, 2, 1.73, 2, 3.46, 1, 4.46, 0, 3.46, 0, 1.73);

    std::cout << hexa.getFigureArea() << ' ' << hexa.getGeometricalCenter() << std::endl;

    Pentagon penta = Pentagon(0, 6, 4, 0, 2, -4, -2, -4, -4, 0);

    std::cout << penta.getFigureArea() << ' ' << penta.getGeometricalCenter() << std::endl;

    Octagon octa = Octagon(1, 2, 3, 4, 5, 3, 6, 1, 5, -1, 3, -2, 1, -1, 0, 1);

    std::cout << octa.getFigureArea() << ' ' << octa.getGeometricalCenter() << std::endl;
    return 0;
}
#include "Headers/utilitare.h"
#include "Headers/arta.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cctype>

double sumaMasa(const Lot& lot) {
    double suma = lot.masaRamasa + lot.deseu;
    for (const auto& el : lot.materiale) {
        suma += el.second;
    }
    return suma;
}

bool masaCorecta(const Lot& lot) {
    return std::abs(sumaMasa(lot) - lot.masaInitiala) < 1e-6;
}

void afiseazaLot(const Lot& lot) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nMasa initiala: " << lot.masaInitiala << " kg\n\n";

    double masaValorificata{};
    for (const auto& el : lot.materiale) {
        std::cout << std::left << std::setw(18) << el.first
                  << std::right << std::setw(12) << el.second << " kg\n";
        masaValorificata += el.second;
    }

    std::cout << std::left << std::setw(18) << "Deseu"
              << std::right << std::setw(12) << lot.deseu << " kg\n";
    std::cout << std::left << std::setw(18) << "Ramas"
              << std::right << std::setw(12) << lot.masaRamasa << " kg\n";

    const double procentValorificat = lot.masaInitiala > 0.0
        ? masaValorificata / lot.masaInitiala * 100.0
        : 0.0;
    std::cout << std::left << std::setw(20) << "Procent Valorificat: "
              << std::right << std::setw(9) << procentValorificat << " %\n";

    const double procentEliminat = lot.masaInitiala > 0.0
        ? (lot.masaInitiala - masaValorificata) / lot.masaInitiala * 100.0
        : 0.0;
    std::cout << std::left << std::setw(18) << "Procent Eliminat: "
              << std::right << std::setw(12) << procentEliminat << " %\n";
}

int citesteNrPanouri() {
    int nr{};
    while (true) {
        std::cout << "Numar de panouri: ";
        if (std::cin >> nr && nr > 0) {
            return nr;
        }
        std::cout << "Valoare invalida, scrie un numar intreg pozitiv.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

char citesteYorN() {
    char decision{};

    std::cout << COLOR::GALBEN << "Doresti sa continui?(y/n):";
    while(true) {
        if(std::cin >> decision &&
             (static_cast<char>(std::toupper(static_cast<unsigned char>(decision))) == 'Y' ||
              static_cast<char>(std::toupper(static_cast<unsigned char>(decision))) == 'N' )) {
                return static_cast<char>(std::toupper(static_cast<unsigned char>(decision)));
        }

        std::cerr << "Valoare invalida, introdu 'y' sau 'n':";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
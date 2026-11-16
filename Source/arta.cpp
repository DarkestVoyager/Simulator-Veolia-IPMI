#include "Headers/arta.h"

#include <algorithm>
#include <iostream>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace {

int latimeTerminal() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) {
        return info.srWindow.Right - info.srWindow.Left + 1;
    }
#endif
    return 80;
}

// Afiseaza un bloc de linii la mijlocul ferestrei.
// latimeBloc = 0 -> se calculeaza din cea mai lunga linie.
void afiseazaCentrat(const std::vector<std::string>& linii, const char* culoare,
                     int latimeBloc = 0) {
    if (latimeBloc == 0) {
        for (const auto& l : linii) {
            latimeBloc = std::max(latimeBloc, static_cast<int>(l.size()));
        }
    }
    const int margine = std::max(0, (latimeTerminal() - latimeBloc) / 2);

    for (const auto& l : linii) {
        std::cout << culoare
                  << std::string(static_cast<std::string::size_type>(margine), ' ')
                  << l << COLOR::RESET << "\n";
    }
}

// Pune textul la mijlocul unui cadru de latime fixa: |   text   |
std::string linieCadru(const std::string& text, int latime) {
    const int total = latime - static_cast<int>(text.size());
    const int stanga = total / 2;
    return "|" + std::string(static_cast<std::string::size_type>(stanga), ' ') + text +
           std::string(static_cast<std::string::size_type>(total - stanga), ' ') + "|";
}

}  // namespace

void afiseazaBanner() {
    constexpr int LAT = 46;
    const std::string margine = "+" + std::string(LAT, '=') + "+";

    const std::vector<std::string> banner = {
        margine,
        linieCadru("", LAT),
        linieCadru("S I M U L A T O R  V E O L I A ", LAT),
        linieCadru("R O U S S E T - F R A N T A", LAT),
        linieCadru("", LAT),
        linieCadru("Reciclarea panourilor fotovoltaice", LAT),
        linieCadru("", LAT),
        margine
    };

    std::cout << "\n";
    afiseazaCentrat(banner, COLOR::VERDE);
}

void afiseazaPanou() {
    constexpr int COLOANE = 6;
    constexpr int RANDURI = 3;
    constexpr int LAT_CELULA = 6;
    constexpr int LAT_PANOU = COLOANE * (LAT_CELULA + 1) + 1;  // 43

    // soare
    const std::vector<std::string> soare = {
        "     \\  |  /",
        "      .---.",
        " ---- (   ) ----",
        "      '---'",
        "     /  |  \\"
    };

    // grila panoului, construita in bucle
    std::string orizontal;
    std::string celule;
    for (int c = 0; c < COLOANE; ++c) {
        orizontal += "+" + std::string(LAT_CELULA, '-');
        celule += "|" + std::string(LAT_CELULA, '/');
    }
    orizontal += "+";
    celule += "|";

    std::vector<std::string> grila;
    grila.push_back(orizontal);
    for (int r = 0; r < RANDURI; ++r) {
        grila.push_back(celule);
        grila.push_back(celule);
        grila.push_back(orizontal);
    }

    // suportul
    const std::vector<std::string> suport = {
        std::string(21, ' ') + "||",
        std::string(21, ' ') + "||",
        std::string(15, ' ') + "______||______",
        std::string(14, ' ') + "/______________\\"
    };

    std::cout << "\n";
    afiseazaCentrat(soare, COLOR::GALBEN);
    afiseazaCentrat(grila, COLOR::ALBASTRU, LAT_PANOU);
    afiseazaCentrat(suport, COLOR::GRI, LAT_PANOU);
}

void afiseazaEtapa(int nr, int total, const std::string& nume) {
	constexpr int LATIME = 20;
	const int procent = nr * 100 / total;
	const int plin = procent * LATIME / 100;

	std::cout << "\n" << COLOR::VERDE << "[Etapa " << nr << "/" << total << "] "
 		<< nume << COLOR::RESET << "\n";
	std::cout << "[" << std::string(static_cast<std::string::size_type>(plin), '#')
		<< std::string(static_cast<std::string::size_type>(LATIME - plin), '.') << "] "
		<< procent << "%\n";
}
#ifndef ARTA_H
#define ARTA_H

#include <string>

namespace COLOR {
constexpr const char* VERDE = "\033[32m";
constexpr const char* ALBASTRU = "\033[34m";
constexpr const char* GALBEN = "\033[33m";
constexpr const char* ROSU = "\033[31m";
constexpr const char* GRI = "\033[90m";
constexpr const char* RESET = "\033[0m";
}

void afiseazaBanner();
void afiseazaPanou();
void afiseazaEtapa(int nr, int total, const std::string& nume);

#endif
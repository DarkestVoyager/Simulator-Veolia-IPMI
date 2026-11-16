#ifndef DATE_H
#define DATE_H

#include <map>
#include <string>

constexpr double MASA_PANOU_KG{ 25.0 };
constexpr double PROCENT_ALUMINIU{ 10.0 };
constexpr double RATA_RECICLARE{ 95.0 };

std::map<std::string, double> creeazaProcente();
std::map<std::string, double> creeazaReciclabilitate();

#endif
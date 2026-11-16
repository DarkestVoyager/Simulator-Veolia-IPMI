#ifndef LOT_H
#define LOT_H

#include <map>
#include <string>
#include <cstdint>

struct Lot {
	double masaInitiala{};
	double masaRamasa{};
	double deseu{};
	double masaValorificata{};
	std::map<std::string, double> materiale;
};

Lot creeazaLot(std::int32_t nrPanouri);

#endif
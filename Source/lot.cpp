#include "../Headers/date.h"
#include "../Headers/lot.h"

Lot creeazaLot(std::int32_t nrPanouri) {
	Lot lot;
	lot.masaInitiala = nrPanouri * MASA_PANOU_KG;
	lot.masaRamasa = lot.masaInitiala;
	lot.deseu = 0.0;
	lot.masaValorificata = 0.0;
	return lot;
}
#include "../Headers/etape.h"
#include "../Headers/date.h"

void decadrare(Lot& lot) {
    const double alu = lot.masaInitiala * PROCENT_ALUMINIU / 100.0;
    lot.materiale["Aluminiu"] += alu;
    lot.masaRamasa -= alu;
}

void separare(Lot& lot, const std::map<std::string, double>& procente) {
    for (const auto& el : procente) {
        const double kg = lot.masaInitiala * el.second / 100.0;
        lot.materiale[el.first] += kg;
        lot.masaRamasa -= kg;
    }
}

void valorificare(Lot& lot, const std::map<std::string, double>& reciclabilitate) {
    for (auto& el : lot.materiale) {
        const double recuperat = el.second * reciclabilitate.at(el.first) / 100.0;
        lot.deseu += el.second - recuperat;
        el.second = recuperat;
    }
}
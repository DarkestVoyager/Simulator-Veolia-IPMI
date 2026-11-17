#ifndef ETAPE_H
#define ETAPE_H

#include "lot.h"

void decadrare(Lot& lot);
void separare(Lot& lot, const std::map<std::string, double>& procente);
void valorificare(Lot& lot, const std::map<std::string, double>& reciclabilitatea);

#endif
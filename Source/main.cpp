#include <chrono>
#include <iostream>
#include <limits>
#include <thread>

#include "../Headers/arta.h"
#include "../Headers/date.h"
#include "../Headers/etape.h"
#include "../Headers/lot.h"
#include "../Headers/utilitare.h"

namespace {
void pauza() {
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
}
}

int main() {
    // cat la suta se valorifica si cat la suta se elimina
    while(true) {   
        afiseazaBanner();
        afiseazaPanou();

        const int nr{citesteNrPanouri()};

        Lot lot = creeazaLot(nr);
        const auto procente = creeazaProcente();
        const auto reciclabilitate = creeazaReciclabilitate();

        afiseazaEtapa(1, 3, "Decadrare");
        decadrare(lot);
        pauza();

        afiseazaEtapa(2, 3, "Separare");
        separare(lot, procente);
        pauza();

        afiseazaEtapa(3, 3, "Valorificare");
        valorificare(lot, reciclabilitate);
        pauza();

        afiseazaLot(lot);

        if (masaCorecta(lot)) {
            std::cout << "\n" << COLOR::VERDE << "Verificare masa: OK" << COLOR::RESET << "\n";
        } else {
            std::cout << "\n" << COLOR::ROSU << "EROARE: masa nu se conserva!" << COLOR::RESET << "\n";
        }

        if(citesteYorN() == 'N') { break; };
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
    }
    return 0;
}
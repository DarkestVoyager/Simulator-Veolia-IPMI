#include "../Headers/date.h"

std::map<std::string, double> creeazaProcente() {
    return {
        {"Sticla", 75.0},
        {"Siliciu", 5.0},
        {"EVA", 5.0},
        {"Backsheet", 3.5},
        {"Cupru si conectori", 1.0},
        {"Argint si staniu", 0.5}
    };
}

std::map<std::string, double> creeazaReciclabilitate() {
    return {
        {"Aluminiu", RATA_RECICLARE},
        {"Sticla", RATA_RECICLARE},
        {"Siliciu", RATA_RECICLARE},
        {"EVA", RATA_RECICLARE},
        {"Backsheet", RATA_RECICLARE},
        {"Cupru si conectori", RATA_RECICLARE},
        {"Argint si staniu", RATA_RECICLARE}
    };
}
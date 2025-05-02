#include "Reteta.h"
#include <iostream>

Reteta::Reteta(std::shared_ptr<Pacient> p, std::shared_ptr<Medic> m, const std::string& d)
    : pacient(p), medic(m), detalii(d) {
    if (detalii.empty()) throw ExceptieDetalii();
}

void Reteta::afiseaza() const {
    std::cout << "\nReteta:\n";
    pacient->afiseazaRol();
    medic->afiseazaRol();
    std::cout << "Detalii: " << detalii << "\n";
}

void Reteta::adaugaDetalii(const std::string& extra) {
    detalii += extra;
}

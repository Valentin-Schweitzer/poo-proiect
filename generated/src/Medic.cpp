#include "../include/Medic.h"
#include <iostream>

Medic::Medic(const std::string& nume, int id) : Persoana(nume), id(id) {
    if (id <= 0) throw ExceptieIdInvalid();
}

bool Medic::esteRezident() const {
    return id < 100;
}

int Medic::getId() const {
    return id;
}

void Medic::afiseazaRol() const {
    std::cout << "Medic: " << nume << ", ID: " << id;
    if (esteRezident()) std::cout << " (rezident)";
    std::cout << "\n";
}

std::shared_ptr<Persoana> Medic::clone() const {
    return std::make_shared<Medic>(*this);
}

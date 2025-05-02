#include "Pacient.h"
#include <iostream>

Pacient::Pacient(const std::string& nume, int varsta, double greutate)
    : Persoana(nume), varsta(varsta), greutate(greutate) {
    if (varsta <= 0) throw ExceptieVarsta();
}

bool Pacient::eMinor() const {
    return varsta < 18;
}

int Pacient::getVarsta() const {
    return varsta;
}

double Pacient::getGreutate() const {
    return greutate;
}

void Pacient::afiseazaRol() const {
    std::cout << "Pacient: " << nume << ", varsta: " << varsta << ", greutate: " << greutate << "\n";
}

std::shared_ptr<Persoana> Pacient::clone() const {
    return std::make_shared<Pacient>(*this);
}

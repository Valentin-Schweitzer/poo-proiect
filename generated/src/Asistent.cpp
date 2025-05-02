#include "../include/Asistent.h"
#include <iostream>

Asistent::Asistent(const std::string& nume, int ani)
    : Persoana(nume), aniExperienta(ani) {}

void Asistent::afiseazaRol() const {
    std::cout << "Asistent: " << nume << ", experienta: " << aniExperienta << " ani\n";
}

std::shared_ptr<Persoana> Asistent::clone() const {
    return std::make_shared<Asistent>(*this);
}

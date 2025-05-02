#ifndef ASISTENT_H
#define ASISTENT_H

#include "Persoana.h"

class Asistent : public Persoana {
private:
    int aniExperienta;

public:
    Asistent(const std::string& nume, int ani);

    void afiseazaRol() const override;
    std::shared_ptr<Persoana> clone() const override;
};

#endif // ASISTENT_H

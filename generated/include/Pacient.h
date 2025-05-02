#ifndef PACIENT_H
#define PACIENT_H

#include "Persoana.h"
#include "Exceptii.h"

class Pacient : public Persoana {
private:
    int varsta;
    double greutate;

public:
    Pacient(const std::string& nume, int varsta, double greutate);

    bool eMinor() const;
    int getVarsta() const;
    double getGreutate() const;

    void afiseazaRol() const override;
    std::shared_ptr<Persoana> clone() const override;
};

#endif // PACIENT_H

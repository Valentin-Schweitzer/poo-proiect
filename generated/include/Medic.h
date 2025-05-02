#ifndef MEDIC_H
#define MEDIC_H

#include "Persoana.h"
#include "Exceptii.h"

class Medic : public Persoana {
private:
    int id;

public:
    Medic(const std::string& nume, int id);

    bool esteRezident() const;
    int getId() const;

    void afiseazaRol() const override;
    std::shared_ptr<Persoana> clone() const override;
};

#endif // MEDIC_H

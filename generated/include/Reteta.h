#ifndef RETETA_H
#define RETETA_H

#include <memory>
#include <string>
#include "Pacient.h"
#include "Medic.h"
#include "Exceptii.h"

class Reteta {
private:
    std::shared_ptr<Pacient> pacient;
    std::shared_ptr<Medic> medic;
    std::string detalii;

public:
    Reteta(std::shared_ptr<Pacient> p, std::shared_ptr<Medic> m, const std::string& d);

    void afiseaza() const;
    void adaugaDetalii(const std::string& extra);
};

#endif // RETETA_H

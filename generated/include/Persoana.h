#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <memory>
#include <iostream>

class Persoana {
protected:
    std::string nume;

public:
    Persoana(const std::string& nume) : nume(nume) {}
    virtual ~Persoana() = default;

    virtual void afiseazaRol() const = 0;
    virtual std::shared_ptr<Persoana> clone() const = 0;

    std::string getNume() const { return nume; }
};

#endif // PERSOANA_H

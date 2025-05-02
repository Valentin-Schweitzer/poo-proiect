#include "generated/include/Persoana.h"
#include "generated/include/Pacient.h"
#include "generated/include/Medic.h"
#include "generated/include/Asistent.h"
#include "generated/include/Reteta.h"
#include "generated/include/Exceptii.h"

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

int main() {
    try {
        std::cout << "\n=== Testare clase Persoana (polimorfism) ===\n";
        std::vector<std::shared_ptr<Persoana>> persoane;

        // Pacienți
        auto p1 = std::make_shared<Pacient>("Ion Popescu", 17, 65.5);
        auto p2 = std::make_shared<Pacient>("Ana Ionescu", 30, 52.0);
        auto p3 = std::make_shared<Pacient>("Marian Georgescu", 12, 40.0);

        // Medici
        auto m1 = std::make_shared<Medic>("Dr. Ionescu", 120);
        auto m2 = std::make_shared<Medic>("Dr. Vasilescu", 95);
        auto m3 = std::make_shared<Medic>("Dr. Stan", 200);

        // Asistenți
        auto a1 = std::make_shared<Asistent>("Maria Vasile", 6);
        auto a2 = std::make_shared<Asistent>("Andrei Coman", 10);

        persoane.push_back(p1);
        persoane.push_back(p2);
        persoane.push_back(p3);
        persoane.push_back(m1);
        persoane.push_back(m2);
        persoane.push_back(m3);
        persoane.push_back(a1);
        persoane.push_back(a2);

        for (const auto& pers : persoane) {
            pers->afiseazaRol();
        }

        std::cout << "\n=== Testare functionalitate Reteta ===\n";
        Reteta r1(p1, m1, "Paracetamol 500mg, de 3 ori pe zi");
        r1.adaugaDetalii(" dupa mese");
        r1.afiseaza();

        Reteta r2(p2, m2, "Ibuprofen 400mg, 2x/zi");
        r2.afiseaza();

        std::cout << "\n=== Test sortare medici dupa ID ===\n";
        std::vector<std::shared_ptr<Medic>> listaMedici = {m1, m2, m3};

        std::sort(listaMedici.begin(), listaMedici.end(), [](const std::shared_ptr<Medic>& a, const std::shared_ptr<Medic>& b) {
            return a->getId() < b->getId();
        });

        for (const auto& m : listaMedici) {
            m->afiseazaRol();
        }

        std::cout << "\n=== Test exceptii ===\n";
        try {
            auto pInvalid = std::make_shared<Pacient>("Invalid", -2, 70);
        } catch (const ExceptieCabinet& e) {
            std::cerr << "[Exceptie catch 1] " << e.what() << '\n';
        }

        try {
            auto mInvalid = std::make_shared<Medic>("Invalid Medic", 0);
        } catch (const ExceptieCabinet& e) {
            std::cerr << "[Exceptie catch 2] " << e.what() << '\n';
        }

        try {
            Reteta rInvalid(p3, m3, "");
        } catch (const ExceptieCabinet& e) {
            std::cerr << "[Exceptie catch 3] " << e.what() << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "Eroare generala: " << e.what() << std::endl;
    }

    return 0;
}

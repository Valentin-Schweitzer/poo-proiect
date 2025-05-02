# Cabinet Medical

## Descriere

Acest proiect gestionează entități dintr-un cabinet medical folosind programarea orientată pe obiecte (POO). Aplicația acoperă două etape de dezvoltare:
- **Tema 1**: implementare de bază POO cu 3 clase, constructori, operatori și metode utile.
- **Tema 2**: utilizarea moștenirii, funcțiilor virtuale, excepțiilor personalizate și STL.

## Funcționalități

- Gestionarea de pacienți, medici și asistenți (toți derivați dintr-o clasă abstractă `Persoana`).
- Afișarea rolului fiecărei persoane folosind funcții virtuale.
- Gestionarea rețetelor care conțin pacienți și medici prin pointeri inteligenți (`std::shared_ptr`).
- Tratarea excepțiilor specifice domeniului (ex: vârstă invalidă, ID invalid, detalii lipsă).

## Structură

- `Persoana.h` – clasă abstractă de bază
- `Pacient.h/.cpp`, `Medic.h/.cpp`, `Asistent.h/.cpp` – clase derivate
- `Reteta.h/.cpp` – clasa pentru gestionarea rețetelor
- `Exceptii.h` – ierarhia de excepții
- `main.cpp` – codul principal de testare

## Cerințe

Structura proiectului respectă cerințele din enunțurile pentru Tema 1 și Tema 2:

### Tema 1 – Programare orientată pe obiecte (bază)

- Cel puțin 3 clase proprii: `Pacient`, `Medic`, `Reteta`
- Implementarea de constructori, operator=, operator<<, metode utile precum:
  - `eMinor()` – verifică dacă un pacient este minor;
  - `esteRezident()` – determină dacă un medic este rezident;
  - `adaugaDetalii()` – adaugă informații la rețetă.
- Separarea codului în fișiere header `.h` și surse `.cpp`
- Codul respectă convențiile de stil: `PascalCase` pentru clase, `camelCase` pentru metode și variabile, fără `using namespace std`
- Teste și date de intrare hardcodate în `main.cpp`

### Tema 2 – Moșteniri și excepții

- Moștenire: clasă de bază abstractă `Persoana` și 3 clase derivate: `Pacient`, `Medic`, `Asistent`
- Funcție virtuală pură: `afiseazaRol()` suprascrisă în fiecare clasă derivată
- Funcție `clone()` în fiecare clasă derivată (constructor virtual)
- Pointeri inteligenți (`std::shared_ptr<Persoana>`) folosiți pentru apeluri polimorfice
- Clasa `Reteta` deține pointeri la `Pacient` și `Medic` și apelează metode virtuale
- Ierarhie proprie de excepții derivată din `std::exception`:
  - `ExceptieVarsta`, `ExceptieIdInvalid`, `ExceptieDetalii`
- Tratare excepții: `throw` în constructori, `try/catch` în `main()`
- Utilizare STL: `std::vector`, `std::string`, `std::shared_ptr`
- Cod cât mai `const`-corect
- Eliminare de getteri/setteri redundanți, favorizând metode polimorfice precum `afiseazaRol()`

## Exemplu rulare
```
=== Testare clase Persoana (polimorfism) ===
Pacient: Ion Popescu, varsta: 17, greutate: 65.5
Pacient: Ana Ionescu, varsta: 30, greutate: 52
Pacient: Marian Georgescu, varsta: 12, greutate: 40
Medic: Dr. Ionescu, ID: 120
Medic: Dr. Vasilescu, ID: 95 (rezident)
Medic: Dr. Stan, ID: 200
Asistent: Maria Vasile, experienta: 6 ani
Asistent: Andrei Coman, experienta: 10 ani

=== Testare functionalitate Reteta ===

Reteta:
Pacient: Ion Popescu, varsta: 17, greutate: 65.5
Medic: Dr. Ionescu, ID: 120
Detalii: Paracetamol 500mg, de 3 ori pe zi dupa mese

Reteta:
Pacient: Ana Ionescu, varsta: 30, greutate: 52
Medic: Dr. Vasilescu, ID: 95 (rezident)
Detalii: Ibuprofen 400mg, 2x/zi

=== Test sortare medici dupa ID ===
Medic: Dr. Vasilescu, ID: 95 (rezident)
Medic: Dr. Ionescu, ID: 120
Medic: Dr. Stan, ID: 200

=== Test exceptii ===
[Exceptie catch 1] ExceptieVarsta: Varsta pacientului este invalida.
[Exceptie catch 2] ExceptieIdInvalid: ID-ul medicului este invalid.
[Exceptie catch 3] ExceptieDetalii: Detaliile retetei sunt invalide.
```

## Compilare

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -o cabinet_medical main.cpp \
generated/src/Pacient.cpp \
generated/src/Medic.cpp \
generated/src/Asistent.cpp \
generated/src/Reteta.cpp
```

## Rulare

```bash
./cabinet_medical
```

## Bibliografie

- https://github.com/mcmarius/poo
- https://github.com/mcmarius/oop-template
- Modele de colocviu și exemple din laborator

## Autor

Schweitzer Karl-Valentin – Facultatea de Matematică și Informatică, Universitatea din București – 2025

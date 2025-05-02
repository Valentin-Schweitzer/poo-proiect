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

### Tema 1
- Cel puțin 3 clase: `Pacient`, `Medic`, `Reteta`
- Constructori, operator=, operator<<, metode utile
- Cod separat în fișiere `.h` și `.cpp`
- Stil de codare conform ghidului laboratorului

### Tema 2
- Moștenire: `Persoana` este clasă abstractă, celelalte clase o derivă
- Cel puțin o funcție virtuală pură (`afiseazaRol()`)
- Constructori virtuali (`clone()`)
- Apeluri prin pointeri inteligenți
- Clasă care gestionează pointeri la clase de bază (`Reteta`)
- Excepții personalizate (cel puțin 3 clase)
- Utilizare STL (`vector`, `string`, `shared_ptr`)
- Fără `using namespace std`, cât mai multe `const`

## Exemplu rulare
```
Pacient: Ion Popescu, varsta: 17, greutate: 65.5
Medic: Dr. Ionescu, ID: 120
Asistent: Maria Vasile, experienta: 6 ani

Reteta:
Pacient: Ion Popescu, varsta: 17, greutate: 65.5
Medic: Dr. Ionescu, ID: 120
Detalii: Paracetamol 500mg, de 3 ori pe zi dupa mese
```

## Compilare

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -o cabinet_medical main.cpp Pacient.cpp Medic.cpp Asistent.cpp Reteta.cpp
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

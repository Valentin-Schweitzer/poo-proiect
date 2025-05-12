# OUTLINE - Prezentare Proiect POO (Tema 2)

## 1. Introducere

- **Numele proiectului**: Cabinet Medical  
- **Scopul**: gestionarea pacienților, medicilor, asistenților și rețetelor într-un sistem orientat pe obiecte.  
- **Extensii față de Tema 1**: moșteniri, funcții virtuale, excepții, STL, smart pointers etc.

---

## 2. Structura generală

- **Clasa abstractă de bază**: `Persoana`  
- **Clase derivate**: `Pacient`, `Medic`, `Asistent`  
- **Clasă compusă**: `Reteta` (conține pointeri la persoane)  
- **Ierarhie de excepții**: `ExceptieCabinet`, `ExceptieVarsta`, `ExceptieIdInvalid`, `ExceptieDetalii`

---

## Explicație completă pentru Cerințele Tema 2 + Implementare

### 1. Separarea codului în fișiere `.h` și `.cpp` + fără `using namespace std`

#### Ce înseamnă:
- `.h` → declarații: clase, metode, membri  
- `.cpp` → implementări  
- Fără `using namespace std;`

#### Cum am făcut:
- Fiecare clasă are fișier `.h` și `.cpp`:  
  - `Pacient.h` / `Pacient.cpp`  
  - `Medic.h` / `Medic.cpp`  
  - `Asistent.h` / `Asistent.cpp`  
  - `Reteta.h` / `Reteta.cpp`  
  - `Persoana.h` (doar `.h` – clasă abstractă)  
- Folosesc `std::string`, `std::cout` etc.

#### Exemplu: `Pacient.h`
```cpp
#include <string>
#include <iostream>

class Pacient : public Persoana {
    // ...
};
```
### ✅ 2. Moșteniri: 1 clasă de bază + 3 derivate

🔍 **Ce înseamnă:**  
O clasă de bază (`Persoana`) oferă o "rețetă" generală, iar celelalte clase (`Pacient`, `Medic`, `Asistent`) o extind, adăugând detalii proprii.

📁 **Cum am făcut:**  
- `Persoana` este o clasă abstractă care conține un nume și două funcții pure.  
- `Pacient`, `Medic`, `Asistent` moștenesc `Persoana` cu `: public Persoana`.

#### 📄 Fragment – `Persoana.h`
```cpp
class Persoana {
protected:
    std::string nume;
public:
    Persoana(const std::string& nume);
    virtual void afiseazaRol() const = 0;
    virtual std::shared_ptr<Persoana> clone() const = 0;
};
```

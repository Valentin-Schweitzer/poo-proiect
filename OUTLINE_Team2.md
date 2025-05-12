# OUTLINE - Prezentare Proiect POO (Tema 2)

## Introducere

- **Numele proiectului**: Cabinet Medical  
- **Scopul**: gestionarea pacienților, medicilor, asistenților și rețetelor într-un sistem orientat pe obiecte.  
- **Extensii față de Tema 1**: moșteniri, funcții virtuale, excepții, STL, smart pointers etc.

---

## Structura generală

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

---

### 2. Moșteniri: 1 clasă de bază + 3 derivate

**Ce înseamnă:**  
O clasă de bază (`Persoana`) oferă o "rețetă" generală, iar celelalte clase (`Pacient`, `Medic`, `Asistent`) o extind, adăugând detalii proprii.

**Cum am făcut:**  
- `Persoana` este o clasă abstractă care conține un nume și două funcții pure.  
- `Pacient`, `Medic`, `Asistent` moștenesc `Persoana` cu `: public Persoana`.

#### Fragment – `Persoana.h`
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
#### Fragment – `Medic.h`
```cpp
cpp
class Medic : public Persoana {
private:
    int id;
public:
    Medic(const std::string& nume, int id);
    void afiseazaRol() const override;
    std::shared_ptr<Persoana> clone() const override;
};
```
---

### 3. Funcții virtuale (pure) specifice temei

**Ce înseamnă:**
Funcțiile virtuale sunt funcții care pot fi "rescrise" în clasele derivate.
Funcțiile pure (`= 0`) înseamnă că obligi fiecare clasă derivată să le implementeze.

**Cum am făcut:**

* În `Persoana.h`:

```cpp
virtual void afiseazaRol() const = 0;
```

* În `Pacient.cpp`:

```cpp
void Pacient::afiseazaRol() const {
    std::cout << "Sunt un pacient: " << nume << "\n";
}
```

* Similar pentru `Medic` și `Asistent`.

---

### 4. Apeluri prin pointeri la clasa de bază

**Ce înseamnă:**
Stochezi obiecte de diferite tipuri (`Pacient`, `Medic`...) în aceeași listă, tratându-le uniform ca `Persoana*` sau `std::shared_ptr<Persoana>`.

**Cum am făcut:**
În `main.cpp`:

```cpp
std::vector<std::shared_ptr<Persoana>> persoane;
persoane.push_back(std::make_shared<Medic>("Dr. Ionescu", 101));
persoane.push_back(std::make_shared<Pacient>("Ion Popescu", 35, 75));

for (const auto& p : persoane) {
    p->afiseazaRol();  // Apelează metoda corespunzătoare din clasa reală
}
```

**Rezultat:**
Programul decide automat ce `afiseazaRol()` să apeleze — al pacientului, medicului etc.

---

### 5. Constructori virtuali (clone)

**Ce înseamnă:**
O metodă `clone()` îți permite să creezi copii ale obiectelor chiar dacă nu știi exact ce tip sunt (`Pacient`, `Medic`...).

**Cum am făcut:**

* În `Persoana.h`:

```cpp
virtual std::shared_ptr<Persoana> clone() const = 0;
```

* În `Medic.cpp`:

```cpp
std::shared_ptr<Persoana> Medic::clone() const {
    return std::make_shared<Medic>(*this);
}
```

---

### 6. Apel constructor bază din derivate

**Ce înseamnă:**
Când creezi un `Pacient`, apelezi constructorul `Persoana` pentru a seta `nume`.

**Cum am făcut:**

* În `Medic.cpp`:

```cpp
Medic::Medic(const std::string& nume, int id)
    : Persoana(nume), id(id) {}
```

---

### 7. O clasă cu pointeri la bază și apeluri virtuale

**Ce înseamnă:**
Ai o clasă (de exemplu `Reteta`) care conține un `Persoana*` (sau `shared_ptr<Persoana>`) și apelează metode virtuale prin acesta.

**Cum am făcut:**

* În `Reteta.h`:

```cpp
std::shared_ptr<Persoana> pacient;
std::shared_ptr<Persoana> medic;
```

* În `Reteta.cpp`:

```cpp
void Reteta::afiseaza() const {
    std::cout << "Reteta:\n";
    pacient->afiseazaRol();
    medic->afiseazaRol();
}
```

---

### 8. Copy/Assignment (operator=) – eliminat

**Ce înseamnă:**
Nu am mai scris manual `operator=`, deoarece `std::string` și `shared_ptr` știu să se copieze corect.

**Cum am făcut:**
Am eliminat complet `operator=`. Codul este sigur pentru că STL gestionează automat memoria.

---

### 9. Downcast cu `dynamic_pointer_cast`

**Ce înseamnă:**
Treci de la pointer la `Persoana` la pointer la `Pacient` doar dacă obiectul este într-adevăr un pacient.

**Cum am făcut:**

```cpp
if (auto p = std::dynamic_pointer_cast<Pacient>(persoana)) {
    std::cout << "Greutatea pacientului este: " << p->getGreutate() << "\n";
}
```

---

### 10. Smart pointers (`shared_ptr`)

**Ce înseamnă:**
În loc să gestionezi manual memoria cu `new` și `delete`, folosești `shared_ptr`, care eliberează automat memoria când nu mai este folosit.

**Cum am făcut:**
Peste tot:

```cpp
std::shared_ptr<Persoana> p = std::make_shared<Pacient>(...);
```

---

### 11. Excepții – ierarhie proprie

**Ce înseamnă:**
Ai clase de erori care derivă din `std::exception`, pentru cazuri precum:

* vârstă invalidă
* ID invalid
* detalii lipsă în rețetă

**Fișier: `Exceptii.h`**

```cpp
class ExceptieVarsta : public std::exception {
public:
    const char* what() const noexcept override {
        return "Varsta pacientului invalida!";
    }
};
```

**Fișier: `main.cpp`**

```cpp
try {
    auto pacient = Pacient("Anonim", -5, 70);
} catch (const std::exception& e) {
    std::cerr << "Eroare: " << e.what() << "\n";
}
```

---

### 12. STL, `const`, funcții de nivel înalt

**Ce înseamnă:**

* **STL:** `vector`, `string`, `shared_ptr` în loc de array-uri statice sau `char*`.
* **`const`:** Funcțiile care nu modifică obiectul au `const` la final.
* **Funcții de nivel înalt:** Nu te bazezi doar pe getter/setteri simpli, ci pe metode clare, cu scop definit (ex: `afiseazaRol()`).

**Exemple:**

```cpp
std::vector<std::shared_ptr<Persoana>> persoane;
const std::string& getNume() const;
void afiseazaRol() const override;
```



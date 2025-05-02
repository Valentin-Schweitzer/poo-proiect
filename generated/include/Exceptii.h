#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>

class ExceptieCabinet : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "ExceptieCabinet: Eroare generică în cabinet";
    }
};

class ExceptieVarsta : public ExceptieCabinet {
public:
    const char* what() const noexcept override {
        return "ExceptieVarsta: Varsta pacientului este invalida.";
    }
};

class ExceptieIdInvalid : public ExceptieCabinet {
public:
    const char* what() const noexcept override {
        return "ExceptieIdInvalid: ID-ul medicului este invalid.";
    }
};

class ExceptieDetalii : public ExceptieCabinet {
public:
    const char* what() const noexcept override {
        return "ExceptieDetalii: Detaliile retetei sunt invalide.";
    }
};

#endif // EXCEPTII_H

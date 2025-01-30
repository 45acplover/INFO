#include <iostream>
#include <cmath>

class Rettangolo {
private:
    double base;
    double altezza;

public:
    // Costruttore senza parametri
    Rettangolo() : base(0), altezza(0) {}

     // Costruttore con un parametro (overloading)
    Rettangolo(double parametro) : base(parametro), altezza(parametro) {}

    // Costruttore con due parametri (overloading)
    Rettangolo(double base, double altezza) : base(base), altezza(altezza) {}

    // Distruttore
    ~Rettangolo() {
        std::cout << "Hai chiamato il distruttore\n";
    }

     // Metodi setter e getter per la base
    void setBase(double base) {
        this->base = base;
    }

    double getBase() const {
        return base;
    }

    // Metodi setter e getter per l'altezza
    void setAltezza(double altezza) {
        this->altezza = altezza;
    }

};


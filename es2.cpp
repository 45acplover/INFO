#include <iostream>
#include <cmath>

class Rettangolo {
private:
    double base;
    double altezza;

public:
    // Costruttore senza parametri
    Rettangolo() : base(0), altezza(0) {}

    // Costruttore con un parametro 
    Rettangolo(double parametro) : base(parametro), altezza(parametro) {}

    // Costruttore con due parametri 
    Rettangolo(double base, double altezza) : base(base), altezza(altezza) {}

    // Distruttore
    ~Rettangolo() {
        std::cout << "Hai chiamato il distruttore\n";
    }

    
    void setBase(double base) {
        this->base = base;
    }

    double getBase() const {
        return base;
    }

    
    void setAltezza(double altezza) {
        this->altezza = altezza;
    }

    double getAltezza() const {
        return altezza;
    }

   
    double calcolaPerimetro() const {
        return 2 * (base + altezza);
    }

    
    double calcolaArea() const {
        return base * altezza;
    }

   
    double calcolaDiagonale() const {
        return sqrt(base * base + altezza * altezza);
    }
};

int main() {
    
    Rettangolo r1; 
    Rettangolo r2(5); 
    Rettangolo r3(4, 6); 

   
    std::cout << "Rettangolo 1 (default): base = " << r1.getBase() << ", altezza = " << r1.getAltezza() << "\n";
    std::cout << "Perimetro: " << r1.calcolaPerimetro() << ", Area: " << r1.calcolaArea() << ", Diagonale: " << r1.calcolaDiagonale() << "\n";

    
    std::cout << "Rettangolo 2 (base=altezza=5): base = " << r2.getBase() << ", altezza = " << r2.getAltezza() << "\n";
    std::cout << "Perimetro: " << r2.calcolaPerimetro() << ", Area: " << r2.calcolaArea() << ", Diagonale: " << r2.calcolaDiagonale() << "\n";

    
    std::cout << "Rettangolo 3 (base=4, altezza=6): base = " << r3.getBase() << ", altezza = " << r3.getAltezza() << "\n";
    std::cout << "Perimetro: " << r3.calcolaPerimetro() << ", Area: " << r3.calcolaArea() << ", Diagonale: " << r3.calcolaDiagonale() << "\n";

    return 0;
}
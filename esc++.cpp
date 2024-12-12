#include <iostream>
using namespace std; 

class Frazione { 
private: 
int numeratore;
int denominatore;
public:
Frazione (){}; 
void setNumeratore(int n) {
numeratore = n; }
void setDenominatore(int n) {
denominatore = n; }

int getNumeratore() { return numeratore; }
int getDenominatore() { return denominatore; }

void setNumeratoreDenom(int n, int d)
{ numeratore = n;
denominatore =d; }

void stampa() { 
cout << numeratore << "/" << denominatore;

int n=getNumeratore(); 
int d=getDenominatore();
cout << n<< "/" << d;
}
}; 
int main() { 
Frazione f1, f2; 
f1.setNumeratore(12); 
f1.setDenominatore(3);
f1.stampa();
system("pause");
}


class Rettangolo{
    private:
    double altezza;
    double base;


    public:

    void setaltezza(double x){altezza + x;}
    void setbase(double y){base + y;}


};

#include <iostream>
using namespace std;

// Define a structure for the vector
struct Vector {
    int* niz;     // pointer na niz
    int broj_elemenata;   // broj elemenata u nizu
    int kapacitet_niza;  // kapacitet niza

    Vector(int init) : niz(new int[init]), broj_elemenata(0), kapacitet_niza(init) {} // incicijalizacija vektora sa danim kapacitetom

    ~Vector() {
        delete[] niz; //brisanje vektora
    }

    
    void push_back(int n) {     //dodaj element na kraj vektora
        if (broj_elemenata >= kapacitet_niza) { //Resize
        
            int* newElements = new int[kapacitet_niza * 2];
            for (int i = 0; i < broj_elemenata; ++i) {
                newElements[i] = niz[i];
            }
            delete[] niz;
            niz = newElements;
            kapacitet_niza *= 2;
        }
        niz[broj_elemenata++] = n;
    }

    
    int pop_back() { // vrati zadnji vektor
        if (broj_elemenata > 0) {
            return niz[--broj_elemenata];
        } else {

            return 0; 
        }
    }

    
    int front() { // prvi element vektora
        if (broj_elemenata > 0) {
            return niz[0];
        } else {

            return 0; 
        }
    }

    
    int back() { // Zadnji element vektora
        if (broj_elemenata > 0) {
            return niz[broj_elemenata - 1];
        } else {

            return 0;
        }
    }

    
    int size() { //velicina vektora
        return broj_elemenata;
    }
};

int main() {

    Vector myVector(5);

 
    myVector.push_back(42);
    int zadnji_element = myVector.pop_back();

 
    cout << "Zadnji element: " << zadnji_element;


    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

// struktura matrice
struct Matrica {
    int redovi;       
    int stupci;    
    float** p;   // pointer u 2D nizu

    // za praznu matricu
    Matrica(int m, int n) : redovi(m), stupci(n), p(new float*[m]) {
        for (int i = 0; i < m; ++i) {
            p[i] = new float[n];
        }
    }

    // dealociranje
    ~Matrica() {
        for (int i = 0; i < redovi; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    // unijeti vrijednosti
    void ulaz_matrica() {
        for (int i = 0; i < redovi; ++i) {
            for (int j = 0; j < stupci; ++j) {
                cout << "Vrijednosti elemenata (" << i << "," << j << "): ";
                cin >> p[i][j];
            }
        }
    }

    // Random elementi matrice [a, b]
    void generiraj_matricu(float a, float b) {
        for (int i = 0; i < redovi; ++i) {
            for (int j = 0; j < stupci; ++j) {
                p[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
            }
        }
    }

    // zbrajanje dvije matrice
    static Matrica zbroj(const Matrica& mat1, const Matrica& mat2) {
        if (mat1.redovi != mat2.redovi || mat1.stupci != mat2.stupci) {
            throw runtime_error("Ne valjaju dimenzije matrice!");
        }

        Matrica rezultat(mat1.redovi, mat1.stupci);

        for (int i = 0; i < mat1.redovi; ++i) {
            for (int j = 0; j < mat1.stupci; ++j) {
                rezultat.p[i][j] = mat1.p[i][j] + mat2.p[i][j];
            }
        }

        return rezultat;
    }

    // oduzimanje matrica
    static Matrica subtract(const Matrica& mat1, const Matrica& mat2) {
        if (mat1.redovi != mat2.redovi || mat1.stupci != mat2.stupci) {
            throw runtime_error("dimenzije matrije ne dopustaju oduzimanje.");
        }

        Matrica result(mat1.redovi, mat1.stupci);

        for (int i = 0; i < mat1.redovi; ++i) {
            for (int j = 0; j < mat1.stupci; ++j) {
                result.p[i][j] = mat1.p[i][j] - mat2.p[i][j];
            }
        }

        return result;
    }

    // mnozenje matrica
    static Matrica umnozak(const Matrica& mat1, const Matrica& mat2) {
        if (mat1.stupci != mat2.redovi) {
            throw runtime_error("Matrice se ne mogu pomnoziti");
        }

        Matrica rezultat(mat1.redovi, mat2.stupci);

        for (int i = 0; i < mat1.redovi; ++i) {
            for (int j = 0; j < mat2.stupci; ++j) {
                rezultat.p[i][j] = 0;
                for (int k = 0; k < mat1.stupci; ++k) {
                    rezultat.p[i][j] += mat1.p[i][k] * mat2.p[k][j];
                }
            }
        }

        return rezultat;
    }

    // transponiranje matrice
    Matrica transponiraj() {
        Matrica result(stupci, redovi);

        for (int i = 0; i < redovi; ++i) {
            for (int j = 0; j < stupci; ++j) {
                result.p[j][i] = p[i][j];
            }
        }

        return result;
    }

    // printanje matrice
    void print_matrica() {
        for (int i = 0; i < redovi; ++i) {
            for (int j = 0; j < stupci; ++j) {
                cout << setw(8) << fixed << setprecision(4) << p[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // random elementi 
    srand( static_cast<unsigned>(time(0)));

    
    Matrica A(3, 3);
    Matrica B(3, 3);
    Matrica C(3, 3);

    // matrica A
    cout << "Vrijednosti matrice A:";
    A.ulaz_matrica();

    // matrica B s rasponom [-1.0, 1.0]
    B.generiraj_matricu(-1.0, 1.0);

    // A i B
    cout << "Matrica A:";
    A.print_matrica();
    cout << "Matria B:";
    B.print_matrica();

    // zbrajanje
    try {
        C = Matrica::zbroj(A, B);
        cout << "Matrica A + B:";
        C.print_matrica();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    // oduzimanje
    try {
        C = Matrica::subtract(A, B);
        cout << "Matrica A - B: ";
        C.print_matrica();
     } catch (const runtime_error& e) {
        cerr << e.what();
    }

    // transponiranje
    Matrica D = A.transponiraj();
    cout << "Transponirana matrica A: ";
    D.print_matrica();

    return 0;
}
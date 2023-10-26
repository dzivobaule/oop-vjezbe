#include <iostream>

using namespace std;

void min_max(const int arr[], int n, int &min_vrijednost, int &max_vrijednost) {
    if (n <= 0) {
        cout << "Prazan niz." << endl;
        return;
    }

    min_vrijednost = max_vrijednost = arr[0]; 

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_vrijednost) {
            min_vrijednost = arr[i];
        }
        if (arr[i] > max_vrijednost) {
            max_vrijednost = arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Broj prirodnih brojeva u nizu: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error." << endl;
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int min_vrijednost, max_vrijednost;
    min_max(arr, n, min_vrijednost, max_vrijednost);

    cout << "Najmanji broj: " << min_vrijednost << endl;
    cout << "Najveci broj: " << max_vrijednost << endl;

    return 0;
}
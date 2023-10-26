#include <iostream>

using namespace std;

int& element(int array[], int index)
{
    return array[index];
}

int main()
{
    int niz[] = { 10, 20, 30, 40, 50, 60 };
    int indeks = 2;
    
    element(niz, indeks) += 1;

    int n = sizeof(niz) / sizeof(niz[0]);

    for (int i = 0; i < n; i++)
    {
        cout << niz[i] << " ";
    }

    return 0;
}
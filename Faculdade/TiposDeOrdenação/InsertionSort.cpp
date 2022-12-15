#include <iostream>
using namespace std;

int InsertionSort(int *v, int n) // n é tamanho do vetor
{
    int i = 0;
    int j = 1;
    int aux = 0,cont=0;
    while (j < n)
    {
        aux = v[j];
        i = j - 1;
        while ((i >= 0) && (v[i] < aux))
        {
            v[i + 1] = v[i];
            i--;
           cont++;
        }
        v[i + 1] = aux;
        j++; 
    }
    return cont;
}

int main()
{
    int X[4] = {3,3,2,1};
    cout<<InsertionSort(X, 4)<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout << X[i] << " ";
    }
}

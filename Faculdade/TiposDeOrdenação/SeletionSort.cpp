#include <iostream>
using namespace std;

 /* template<class T>
    void selection_sort(vector<T> &vec )
    {
        vector<T>::iterator it1;
        for(it1 = vec.begin(); it1 != vec.end()-1; ++it1 ){
        iter_swap(it1, min_element(it1, vec.end()));
        }
    }
*/
void SelectionSort(int * vec, int tam)
{
    int i, j, min, aux;
    for (i = 0; i < tam - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vec[j] < vec[min])
                min = j;
        }
        aux = vec[i];
        vec[i] = vec[min];
        vec[min] = aux;
    }
}

    int main()
    {
        int X[8] = {9, 3, 83, 7, 83, 94, 8, 7};
        SelectionSort(X, 8);
        for (int i = 0; i < 8; i++)
        {
            cout << X[i] << " ";
        }
    }

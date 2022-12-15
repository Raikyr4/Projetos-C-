#include <iostream>
using namespace std;

/*    template<class T>
       void bubble_sort(vector<T> &vec)
       {
           vector<T>::reverse_iterator it1;
           for(it1 = vec.rbegin(); it1 != vec.rend(); ++it1 )
            {
                vector<T>::iterator it2;
                bool troca = false;
                for(it2 = vec.begin(); &*it2 != &*it1; ++it2 ) 
                {
                        if (*it2 > *(it2+1)) 
                        {
                        iter_swap(it2, it2+1);
                        troca = true;
                        }
                }
                if (!troca) return;
            }
       }
   */
  
void bubble_sort(int vec[], int n)
{
    
    int troca, i, j, aux,cont=0;
    for (i = n - 1; i > 0; i--)
    {
        // o maior valor entre vec[0] e vec[i] vai para a posição vec[i]
        troca = 0;
        for (j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
                cont++;
                troca = 1;
            }
        }
        if (!troca)
            return;
    }
}

int main()
{
    int X[8] = {9, 3, 83, 7, 83, 94, 8, 7};
    bubble_sort(X, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << X[i] << " ";
    }
}

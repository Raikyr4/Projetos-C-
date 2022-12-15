#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //complexidade O(logN);

     int X[8] = {9, 3, 83, 7, 83, 94, 8, 7};
     sort(X,X+8); // ou sort(X.begin(),X.end()); É O BASICO DA STL E NORMALMENTE USAREMOS ISSO NOS PROBLEMAS 
      for (int i = 0; i < 8; i++)
      {
        cout << X[i] << " ";
      }
}
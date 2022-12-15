#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*template <class T>
int BUSCA_BIN(vector<T> &vector, int Pi ,int Pf, int N)
{
   int M;
   if(Pi==Pf)
   return vector[Pi]== N ? Pi : -1;

   M=(Pi+Pf)/2;

   if(N<=vector[M])
   return BUSCA_BIN(vector,Pi,M,N);

   return BUSCA_BIN(vector,M,Pf,N);
}
*/
int BUSCA_BIN(int *vector, int Pi, int Pf, int N)
{
   int M;
   if (Pi == Pf)
      return vector[Pi] == N ? Pi : -1;

   M = (Pi + Pf) / 2;

   if (N <= vector[M])
      return BUSCA_BIN(vector, Pi, M, N);

   return BUSCA_BIN(vector, M, Pf, N);
}
int main()
{
   int N;
   cin >> N;
   int X[8] = {1, 3, 5, 6, 7, 88, 75, 42};
   sort(X, X + 8);
   cout << BUSCA_BIN(X, X[0], X[7], N) << endl;
   

 
}
#include <iostream>
using namespace std;
void Merge(int *vet, int Pi, int M, int Pf)
{
   int i,j,K;
   int N= Pf -Pi+1;
   int A[N];
   i=Pi;
   j=M+1;
   K=0;
   while (i<=M && j<=Pf)
   {
     if(vet[i]<=vet[j])
     {
        A[K]=vet[i];
        i++;
     }
     else
     {
        A[K]=vet[j];
        j++;
     }
     K++;
   }
   
}
void Merge_Sort(int * vet, int Pi, int Pf)
{
    if(Pi<Pf)
    {
      int M=(Pi+Pf)/2;
      Merge_Sort(vet,Pi,M);
      Merge_Sort(vet,M+1,Pf);
      Merge(vet,Pi,M,Pf);
    }
}

int main()
{
    
    int X[8] = {9, 3, 83, 7, 83, 94, 8, 7};
    for (int i = 0; i < 8; i++)
    {
        cout << X[i] << " ";
    }
}

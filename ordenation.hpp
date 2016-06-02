#include <iostream>
#include <string>
#include <cstdlib>
#define N 10

using namespace std;


class Ordenation {

private:
  int vetor[N];

public:
    Ordenation(){

      int i;
      for (i=0; i<N; i++){
        vetor[i]= rand() % 100 + 1;
      }
    };

    ~Ordenation(){
      cout << "Deleting values..." << endl;
    };

    void mostrar (){
      int i;
      for (i=0; i<N; i++){
        cout<<vetor[i]<<endl;
      }
    }

    void bubbleSort (){
      int i, j=N-1, aux, k;
      for (k=N-1; k>0; k--){
        for (i=0; i<k; i++){
          if (vetor[i]>vetor[i+1]){
            aux = vetor[i+1];
            vetor[i+1]=vetor[i];
            vetor[i]=aux;
          }
        }
      }
    }

    void selectionSort(){
      int i, j=N, k, menor, aux;
      for (i=0; i<j; i++){
        menor = vetor[i];
        for (k=i+1; k<j; k++){
          if (vetor[k]<menor){
            aux = vetor[k];
            vetor[k] = menor;
            menor = aux;
          }
        }
        vetor[i]=menor;
      }
    }

    void insertionSort(){ //ERRADO
      int i, j, k, aux, numDeElementos=1, primeiro=0;
      for (i=1; i<N; i++){ //elemento que será comparado (fora do grupo de elementos)
        for (k=primeiro; k<primeiro+numDeElementos; k++){
          if (vetor[i]<vetor[k]){
            aux = vetor[i];
            for (j=i; j>primeiro; j--){
              vetor[j] = vetor[j-1];
            }
            vetor[primeiro] = aux;
            primeiro++;
          }
        }
      }
    }

    // void shellSort(){
    //
    // }
};

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

    void insertionSort(){
      int i, aux, flag;
      for(i = 0; i < N; i++){
          if(vetor[i] > vetor[i+1]){
              aux = vetor[i+1];
              vetor[i+1] = vetor[i];
              vetor[i] = aux;
              flag = i;
              while(flag > 0){
                  if(vetor[flag] < vetor[flag-1]){
                      aux = vetor[flag-1];
                      vetor[flag-1] = vetor[flag];
                      vetor[flag] = aux;
                  }else{
                      break;
                  }
                  flag--;
              }
          }
      }
    }

    void shellSort(){
      int i, aux;
      int metade = N/2 + 1;
      while(metade > 0){
        for(i = 0; i < N-metade; i++){
          if(vetor[i] > vetor[i+metade]){
            aux = vetor[i];
            vetor[i] = vetor[i+metade];
            vetor[i+metade] = aux;
          }
        }
        metade--;
      }
    }

    void mergeSort(int inc, int fim){ // Não está pronto
      if (inc != fim){
        int meio = (inc+fim)/2;
        mergeSort(inc, metade);
        mergeSort(metade+1, fim);
      } else {
        return inc;
      }


    }


};

#include <iostream>
#include <string>
#include <cstdlib>
#define N 20

using namespace std;


class Ordenation {

public:
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

    int mergeSort(int inc, int fim){ // Não está pronto
      int i, j, k, meio = (inc+fim)/2;

      // se for só 1 elemento
      if (inc == fim) return 0;

      mergeSort(inc, meio);
      mergeSort(meio+1, fim);

      i=inc;
      j=meio+1;
      k=0;
      int *temporario = new int[fim - inc + 1];
      while(i < meio + 1 || j  < fim + 1) {
        if (i == meio + 1 ) {
            temporario[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == fim + 1) {
                temporario[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    temporario[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    temporario[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = inc; i <= fim; i++) {
      vetor[i] = temporario[i - inc];
  }

  delete [] temporario;

    }


    void quickSort (int esq, int dir){
      if (esq < dir) {
        int pivo = particao(esq, dir);
        quickSort(esq, pivo-1);
        quickSort(pivo+1, dir);
      }

    }

    int particao (int esq, int dir){
      int pivo = vetor[esq];
      while (esq != dir){
        if (pivo == vetor[esq]){
          if (pivo > vetor[dir]){
            vetor[esq] = vetor[dir];
            vetor[dir] = pivo;
            esq++;
          } else {
            dir--;
          }
        } else {
          if (pivo < vetor[esq]){
            vetor[dir] = vetor[esq];
            vetor[esq] = pivo;
            dir--;
          } else {
            esq ++;
          }
        }
      }

      return esq;
    }

};

#include <iostream>
#include "pessoa.hpp"

using namespace std;

  Pessoa *raiz = NULL;

int main(int argc, char **argv){
  string nome;
  int idade;
  int i;

  for (i=0; i<3; i++){

  Pessoa *novo;

  cout << "Insira nome" << endl;
  cin >> nome;
  cout << "Insira idade" << endl;
  cin >> idade;

  novo = new Pessoa(nome,idade);

  if (raiz == NULL){
    raiz = novo;
  } else {
    raiz->inserirFilho(novo);
  }

  }

  raiz->caminhoPreOrdem();
  cout << endl;
  raiz->caminhoOrdem();
  cout << endl;
  raiz->caminhoPosOrdem();
  cout << endl;

  raiz->caminhoPosOrdemDelete();

     return 0;
}

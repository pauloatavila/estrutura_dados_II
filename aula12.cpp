#include <iostream>
// #include "pessoa.hpp"
#include "ordenation.hpp"

using namespace std;


int main(int argc, char **argv){

  Ordenation execucao;
  execucao.mostrar();
  int teste = execucao.mergeSort(0, N-1);
  cout<<endl<<"Nova Ordenacao: "<< endl;
  execucao.mostrar();

  // string nome;
  // int idade;
  // int i;
  // Pessoa *raiz = NULL;
  //
  // for (i=0; i<9; i++){
  //
  // Pessoa *novo;
  //
  // cout << "Insira nome" << endl;
  // cin >> nome;
  // cout << "Insira idade" << endl;
  // cin >> idade;
  //
  // novo = new Pessoa(nome,idade);
  //
  // if (raiz == NULL){
  //   raiz = novo;
  //   novo->setPai();
  // } else {
  //   raiz->inserirFilho(novo, &raiz);
  // }
  //
  // }

  // raiz->caminhoPreOrdem();
  // cout << endl;

  // raiz->caminhoOrdem();
  // cout << endl;
  // raiz->caminhoPosOrdem();
  // cout << endl;

  // i = 0;
  // while (i<5){
  //   cout << "Insira idade do elemento para apagar" << endl;
  //   cin >> idade;
  //   Pessoa *b = raiz->buscar(idade);
  //
  //   if (b != NULL){
  //     nome_apagado[i] = b->nome;
  //     idade_apagada[i] = b->idade;
  //     b->deleteEscolhido(&b,&raiz);
  //     i++;
  //   } else {
  //     cout << "Não Encontrado, informe outra idade" << endl;
  //   }
  // }
  // cout << "Lista de Deletados" << endl;
  // for (i=0; i<5; i++){
  //   cout << "Nome: " << nome_apagado[i] << " Idade: " << idade_apagada[i] << endl;
  // }



  // cout << "Insira idade do elemento para apagar" << endl;
  // cin >> idade;

  // Pessoa *b = raiz->buscar(idade);
  //
  // if (b != NULL)
  //   b->deleteEscolhido(&b,&raiz);
  // else
  //   cout << "Não Encontrado" << endl;
//
// if (raiz != NULL){
//   raiz->caminhoPreOrdem();
//   cout << endl;
// }
     return 0;
}

#include "veiculo.hpp"

int main (){

  // string texto;
  // float valor;
  // int numero;

  // Aviao *veiculo;
  // veiculo = new Aviao("Azul","H700B2",500000,32,"Medeiros,Carlos","Disel");

  Aviao *vetor_veiculo;
  vetor_veiculo = new Aviao[5];
  int i;
  for (i=0; i<5; i++){
    vetor_veiculo[i].setMarca("Azul");
    vetor_veiculo[i].setModelo("H4B57");
    vetor_veiculo[i].setNumeroPoltronas(i*2);
    vetor_veiculo[i].setPreco((i*2)*5);
    vetor_veiculo[i].setPiloto("Mendes,Carlos");
    vetor_veiculo[i].setCombustivel("Disel");

    vetor_veiculo[i].Imprimir();
  }

  delete[] vetor_veiculo;


  // cout << "Informe a marca do veiculo" << endl;
  // cin >> texto;
  // veiculo->setMarca(texto);
  // //
  // cout << "Informe o modelo do veiculo" << endl;
  // cin >> texto;
  // veiculo->setModelo(texto);
  // //
  // cout << "Informe o preco do veiculo" << endl;
  // cin >> valor;
  // veiculo->setPreco(valor);
  // //
  // // cout << "Informe o tipo de cambio" << endl;
  // // cin >> numero;
  // // veiculo.setTipoCambio(numero);
  // // //
  // // cout << "Informe o numero de assentos" << endl;
  // // cin >> numero;
  // // veiculo.setNumeroAssentos(numero);
  // // //
  // cout << "Informe o numero de poltronas" << endl;
  // cin >> numero;
  // veiculo->setNumeroPoltronas(numero);
  // //
  // cout << "Informe o nome do piloto" << endl;
  // cin >> texto;
  // veiculo->setPiloto(texto);
  // //
  // cout << "Informe o combustivel" << endl;
  // cin >> texto;
  // veiculo->setCombustivel(texto);
  //



  // cout << "Dados do Veiculo:    ";
  // cout << veiculo->getMarca() << " - ";
  // cout << veiculo->getModelo() << " - ";
  // cout << veiculo->getPreco() << " - ";
  // cout << veiculo->getNumeroPoltronas() << " - ";
  // cout << veiculo->getPiloto() << " - ";
  // cout << veiculo->getCombustivel() << endl << endl;
  // delete(veiculo);

  return 0;
}

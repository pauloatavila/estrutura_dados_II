#include <iostream>
#include <string>
using namespace std;


// class PessoaTeste {
//   protected:
//     int variavel;
//   public:
//     PessoaTeste();
//     void Aula();
// };
//
// PessoaTeste *raiz_teste = NULL;
//
// void PessoaTeste::Aula()
// {
//   raiz_teste = NULL;
//
// };




class Pessoa {
public:
    string nome;
    int idade;
    Pessoa *filhoEsquerda;
    Pessoa *filhoDireita;
    Pessoa *pai;
    int balancD;
    int balancE;

  public:
    Pessoa(){
      nome = "NULL";
      idade = 0;
    };

    Pessoa(string name, int age){
      nome = name;
      idade = age;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      balancD = 0;
      balancE = 0;
    };

    ~Pessoa(){
      cout << "IML sendo acionado..." << endl;
    };

    void inserirFilho(Pessoa *novo){
      if (novo->idade > this->idade){
          if (this->filhoDireita == NULL){
            this->filhoDireita = novo;
            novo->pai = this;
            atualizarValores(novo, true);
            verificardDesbalanceamento(novo);
          } else {
            this->filhoDireita->inserirFilho(novo);
          }
      } else {
        if (this->filhoEsquerda == NULL){
          this->filhoEsquerda = novo;
          novo->pai = this;
          atualizarValores(novo, true);
          verificardDesbalanceamento(novo);
        } else {
          this->filhoEsquerda->inserirFilho(novo);
        }
      }
    }

    void atualizarValores(Pessoa* pessoa, bool opcao){
        Pessoa* aux = pessoa;
        Pessoa* auxPai = pessoa->pai;
        bool segundoFilho;
        if(auxPai->filhoEsquerda!=NULL && auxPai->filhoDireita!=NULL){
          segundoFilho = true;
        }else{
          segundoFilho = false;
        }
        while(aux->pai != NULL){
            if(auxPai->filhoEsquerda == aux){
              if(opcao){
                auxPai->balancE++;
              }else{
                auxPai->balancE--;
              }
            }else{
              if(opcao){
                auxPai->balancD++;
              }else{
                auxPai->balancD--;
              }
            }
            if(segundoFilho){
              return;
            }
            aux=aux->pai;
            auxPai=aux->pai;
        }
    }

    void caminhoPreOrdem (){
      cout << " " << this->nome << endl << "BalE: "<< this->balancE << " BalD: "<< this->balancD << " Valor: " <<  this->balancD-this->balancE << endl;
      if (filhoEsquerda != NULL){
        this->filhoEsquerda->caminhoPreOrdem();
      }
      if (filhoDireita != NULL){
          this->filhoDireita->caminhoPreOrdem();
      }
    }

    void caminhoOrdem (){
      if (filhoEsquerda != NULL){
        this->filhoEsquerda->caminhoOrdem();
      }
      cout << " " << this->nome;
      if (filhoDireita != NULL){
          this->filhoDireita->caminhoOrdem();
      }
    }

    void caminhoPosOrdem (){
      if (filhoEsquerda != NULL){
        this->filhoEsquerda->caminhoPosOrdem();
      }
      if (filhoDireita != NULL){
          this->filhoDireita->caminhoPosOrdem();
      }
      cout << " " << this->nome;
    }

    void caminhoPosOrdemDelete (){
      if (filhoEsquerda != NULL){
        this->filhoEsquerda->caminhoPosOrdemDelete();
      }
      if (filhoDireita != NULL){
          this->filhoDireita->caminhoPosOrdemDelete();
      }
      delete this;
    }

    void deleteEscolhido (Pessoa ** apagar, Pessoa ** raiz)
    {
      if (filhoDireita == NULL && filhoEsquerda == NULL) deleteNoFolha(apagar, raiz);
      else if (filhoDireita == NULL) delete1FilhoD(apagar, raiz);
      else if (filhoEsquerda == NULL) delete1FilhoE(apagar, raiz);
      else delete2Filhos(apagar, raiz);
    }

    void deleteNoFolha (Pessoa ** apagar, Pessoa ** raiz){
      if ((*apagar)->pai != NULL)
      {
        if ((*apagar)->pai->filhoDireita == (*apagar))
        {
              (*apagar)->pai->filhoDireita = NULL;

              delete (*apagar);
        }
         else
         {
            (*apagar)->pai->filhoEsquerda = NULL;

            delete (*apagar);
        }
      }
      else { //caso não tenha pai
        delete (*apagar);
        (*raiz) = NULL;
      }
    }

    void delete1FilhoD (Pessoa ** apagar, Pessoa ** raiz){
      if ((*apagar) != (*raiz)){
        if ((*apagar)->pai->filhoDireita == (*apagar))
        {
            (*apagar)->pai->filhoDireita = (*apagar)->filhoEsquerda;
            (*apagar)->filhoEsquerda->pai = (*apagar)->pai;
            delete (*apagar);
        }
         else
         {
           (*apagar)->pai->filhoEsquerda = (*apagar)->filhoEsquerda;
           (*apagar)->filhoEsquerda->pai = (*apagar)->pai;
           delete (*apagar);
         }
      } else {
        (*raiz) = (*apagar)->filhoEsquerda;
        (*apagar)->filhoEsquerda->pai = NULL;
        delete (*apagar);
      }
    }

    void delete1FilhoE (Pessoa ** apagar, Pessoa ** raiz){
      if ((*apagar) != (*raiz)){
        if ((*apagar)->pai->filhoDireita == (*apagar))
        {

            (*apagar)->pai->filhoDireita = (*apagar)->filhoDireita;
            (*apagar)->filhoDireita->pai = (*apagar)->pai;
            delete (*apagar);
        }
         else
         {
           (*apagar)->pai->filhoEsquerda = (*apagar)->filhoDireita;
           (*apagar)->filhoDireita->pai = (*apagar)->pai;
           delete (*apagar);
         }
      } else {
        (*raiz) = (*apagar)->filhoDireita;
        (*apagar)->filhoDireita->pai = NULL;
        delete (*apagar);
      }
    }

    void delete2Filhos (Pessoa ** apagar, Pessoa ** raiz){
      Pessoa *aux;
      if ((*apagar) != (*raiz)){
        aux = (*apagar)->filhoDireita;
        if ((*apagar)->pai->filhoEsquerda == (*apagar)){
          while (aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }
          if (aux == (*apagar)->filhoDireita) aux->pai->filhoDireita = aux->filhoDireita;
          else aux->pai->filhoEsquerda = aux->filhoDireita;
          if (aux->filhoDireita != NULL){
            aux->filhoDireita->pai = aux->pai;
          }
          aux->pai = (*apagar)->pai;
          (*apagar)->pai->filhoEsquerda = aux;
          aux->filhoDireita = (*apagar)->filhoDireita;
          aux->filhoEsquerda = (*apagar)->filhoEsquerda;
          (*apagar)->filhoDireita->pai = aux;
          (*apagar)->filhoEsquerda->pai = aux;
          delete (*apagar);
          } else {
            while (aux->filhoEsquerda != NULL){
              aux = aux->filhoEsquerda;
            }
            if (aux == (*apagar)->filhoDireita) aux->pai->filhoDireita = aux->filhoDireita;
            else aux->pai->filhoEsquerda = aux->filhoDireita;
            if (aux->filhoDireita != NULL){
              aux->filhoDireita->pai = aux->pai;
            }
            aux->pai = (*apagar)->pai;
            (*apagar)->pai->filhoDireita = aux;
            aux->filhoDireita = (*apagar)->filhoDireita;
            aux->filhoEsquerda = (*apagar)->filhoEsquerda;
            (*apagar)->filhoDireita->pai = aux;
            (*apagar)->filhoEsquerda->pai = aux;
            delete (*apagar);
          }
      } else {
        aux = (*raiz)->filhoDireita;
        while (aux->filhoEsquerda != NULL){
          aux = aux->filhoEsquerda;
        }
        if (aux == (*apagar)->filhoDireita) aux->pai->filhoDireita = aux->filhoDireita;
        else aux->pai->filhoEsquerda = aux->filhoDireita;
        if (aux->filhoDireita != NULL){
          aux->filhoDireita->pai = aux->pai;
        }
        (*raiz) = aux;
        (*raiz)->pai = NULL;
        (*raiz)->filhoDireita = (*apagar)->filhoDireita;
        (*raiz)->filhoEsquerda = (*apagar)->filhoEsquerda;
        (*apagar)->filhoDireita->pai = aux;
        (*apagar)->filhoEsquerda->pai = aux;
        delete (*apagar);
      }

      }

    Pessoa * buscar (int idade){

      if (idade == this->idade) return this;
      else {
        if (idade > this->idade && filhoDireita != NULL) this->filhoDireita->buscar(idade);
        else {
          if (idade < this->idade && filhoEsquerda != NULL) this->filhoEsquerda->buscar(idade);
          else return NULL;
        }
      }
    }

    void verificardDesbalanceamento(Pessoa *inserido){
      int tipoDeRotacao;
      while (inserido->pai != NULL){
        if (inserido->pai->balancD - inserido->pai->balancE < -1 || inserido->pai->balancD - inserido->pai->balancE > 1){
          cout << "Está desbalanceado" << inserido->pai->nome << " Valor: " << inserido->pai->balancD - inserido->pai->balancE << endl;
          tipoDeRotacao = qualTipoDesb(inserido);
          cout << "VERIFICOU " << tipoDeRotacao << endl;
          switch (tipoDeRotacao){
            case 1:
              rotaEsquerda(inserido->pai);
              break;
          }
          break;
        } else inserido = inserido->pai;
      }
    }

    int qualTipoDesb(Pessoa *desbalanceado){ //TA COM ERRO (FAZ CONTA DO VALOR DO BALANCEAMENTO DO FILHO SEM TER UM FILHO)
      //1= Rotação a direita      2= Rotação a esquerda     3= Rotação dupla à direita    4= Rotação dupla à esquerda
      if (desbalanceado->filhoDireita != NULL && desbalanceado->filhoEsquerda != NULL){
        if((desbalanceado->balancD - desbalanceado->balancE) < 0 && (desbalanceado->filhoEsquerda->balancD - desbalanceado->filhoEsquerda->balancE) < 0) return 1;
        else if((desbalanceado->balancD - desbalanceado->balancE) > 0 && (desbalanceado->filhoDireita->balancD - desbalanceado->filhoDireita->balancE) > 0) return 2;
        else if((desbalanceado->balancD - desbalanceado->balancE) < 0 && (desbalanceado->filhoEsquerda->balancD - desbalanceado->filhoEsquerda->balancE) > 0) return 3;
        else return 4;
      } else {
        if (desbalanceado->filhoDireita == NULL){
          if ((desbalanceado->balancD - desbalanceado->balancE) < 0 && (desbalanceado->filhoEsquerda->balancD - desbalanceado->filhoEsquerda->balancE) < 0)) return 1;
          else if ((desbalanceado->balancD - desbalanceado->balancE) > 0) return 1;
        }
      }

    }

    void rotaEsquerda(Pessoa *desbalanceado){
      Pessoa *aux = desbalanceado->filhoDireita;
      if (desbalanceado->pai != NULL){
        if (desbalanceado->pai->filhoDireita == desbalanceado){ // o desbalanceado é filho a direita do pai dele.
          desbalanceado->pai->filhoDireita = aux;
          aux->pai = desbalanceado->pai;
          if (aux->filhoEsquerda != NULL) {
            Pessoa *filho = aux->filhoEsquerda;
            desbalanceado->filhoDireita = filho;
            filho->pai = desbalanceado;
          }else {
            desbalanceado->filhoDireita = NULL;
          }
          aux->filhoEsquerda = desbalanceado;
        } else { // o desbalanceado é filho a esquerda do pai dele.
          desbalanceado->pai->filhoEsquerda = aux;
          aux->pai = desbalanceado->pai;
          if (aux->filhoEsquerda != NULL) {
            Pessoa *filho = aux->filhoEsquerda;
            desbalanceado->filhoDireita = filho;
            filho->pai = desbalanceado;
          }else {
            desbalanceado->filhoDireita = NULL;
          }
          aux->filhoEsquerda = desbalanceado;
        }
      } else {

      }
    }





    string getNome(){
      return nome;
    };

    void setNome(string name){
      nome = name;
    };

    int getIdade(){
      return idade;
    };

    void setIdade(int ida){
      idade = ida;
    };

    void setPai(){
      pai = NULL;
    };
};

class PessoaFisica: public Pessoa {
  private:
    string cpf;

  public:
    PessoaFisica(){
      cpf = "NULL";
    };

    PessoaFisica(string cadastroF){
      cpf = cadastroF;
    };

    ~PessoaFisica(){
      cout << "Cadastro Fisico sendo excluido" << endl << endl;
    };

    string getCPF(){
      return cpf;
    };

    void setCPF(string cadastroF){
      cpf = cadastroF;
    };
};

class PessoaJuridica: public Pessoa {
  private:
    string cnpj;

  public:
    PessoaJuridica(){
      cnpj = "NULL";
    };

    PessoaJuridica(string cadastroJ){
      cnpj = cadastroJ;
    };

    ~PessoaJuridica(){
      cout << "Cadastro Juridico sendo excluido" << endl << endl;
    };

    string getCPF(){
      return cnpj;
    };

    void setCPF(string cadastroJ){
      cnpj = cadastroJ;
    };
};

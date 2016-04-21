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
  protected:
    string nome;
    int idade;
    Pessoa *filhoEsquerda;
    Pessoa *filhoDireita;
    Pessoa *pai;

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
    };

    ~Pessoa(){
      cout << "IML sendo acionado..." << endl;
    };

    void inserirFilho(Pessoa *novo){
      if (novo->idade > this->idade){
          if (filhoDireita == NULL){
            filhoDireita = novo;
            novo->pai = this;
          } else {
            this->filhoDireita->inserirFilho(novo);
          }
      } else {
        if (filhoEsquerda == NULL){
          filhoEsquerda = novo;
          novo->pai = this;
        } else {
          this->filhoEsquerda->inserirFilho(novo);
        }
      }
    }

    void caminhoPreOrdem (){
      cout << " " << this->nome;
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
      else if (filhoDireita == NULL) delete1FilhoD(apagar);
      else if (filhoEsquerda == NULL) delete1FilhoE(apagar);
      else delete2Filhos(apagar);
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
            delete (*apagar);
        }
         else
         {
           (*apagar)->pai->filhoEsquerda = (*apagar)->filhoEsquerda;
           delete (*apagar);
         }
      } else {
        (*raiz) = (*apagar)->filhoEsquerda;
        delete (*apagar);
      }
    }

    void delete1FilhoE (Pessoa ** apagar){
      if ((*apagar) != (*raiz)){
        if ((*apagar)->pai->filhoDireita == (*apagar))
        {

            (*apagar)->pai->filhoDireita = (*apagar)->filhoDireita;
            delete (*apagar);
        }
         else
         {
           (*apagar)->pai->filhoEsquerda = (*apagar)->filhoDireita;
           delete (*apagar);
         }
      } else {
        (*raiz) = (*apagar)->filhoDireita;
        delete (*apagar);
      }
    }

    void delete2Filhos (Pessoa ** apagar){
      Pessoa *aux;
      aux = (*apagar)->filhoDireita;
        if ((*apagar)->pai->filhoEsquerda == (*apagar)){
          while (aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }
          aux->pai->filhoEsquerda = aux->filhoDireita;
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
            aux->pai->filhoEsquerda = aux->filhoDireita;
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

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

    void inserirFilho(Pessoa *novo, Pessoa** raiz){
      if (novo->idade > this->idade){
          if (this->filhoDireita == NULL){
            this->filhoDireita = novo;
            novo->pai = this;
            (*raiz)->profundidadeNos();
            (*raiz)->verificardDesbalanceamento(raiz);
          } else {
            this->filhoDireita->inserirFilho(novo, raiz);
          }
      } else {
        if (this->filhoEsquerda == NULL){
          this->filhoEsquerda = novo;
          novo->pai = this;
          (*raiz)->profundidadeNos();
          (*raiz)->verificardDesbalanceamento(raiz);
        } else {
          this->filhoEsquerda->inserirFilho(novo, raiz);
        }
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

    int profundidadeNos(){
        balancE = 0;
        balancD = 0;
        if (filhoEsquerda != NULL) {
            balancE = filhoEsquerda->profundidadeNos()+1;
        }
        if (filhoDireita != NULL) {
            balancD = filhoDireita->profundidadeNos()+1;
        }
        return (balancE > balancD) ? balancE : balancD;
    }


    void verificardDesbalanceamento(Pessoa** raiz){
        int a;
        a = this->balancD - this->balancE;
        if(a < -1 || a > 1){
          cout << "Desbalanceada: " << this->idade << endl;
          chamarBalanceamento(a, this, raiz);
          return;
        }
        if(filhoEsquerda != NULL){
          this->filhoEsquerda->verificardDesbalanceamento(raiz);
        }
        if(filhoDireita != NULL){
          this->filhoDireita->verificardDesbalanceamento(raiz);
        }
    }

    void chamarBalanceamento(int t, Pessoa *pessoa, Pessoa** raiz){
      int tipoFilho;
      if(t < 0){
        tipoFilho = pessoa->filhoEsquerda->balancD - pessoa->filhoEsquerda->balancE;
        if(tipoFilho <= 0){
          rotaDireita(pessoa, raiz);
        }else{
          rotaDuplaEsquerda(pessoa, raiz);
        }
      }else{
        tipoFilho = pessoa->filhoDireita->balancD - pessoa->filhoDireita->balancE;
        if(tipofilho >= 0){
          rotaEsquerda(pessoa, raiz);
        }else{
          rotaDuplaDireita(pessoa, raiz);
        }
      }
      (*raiz)->profundidadeNos();
    }

    void rotaDireita(Pessoa* pessoa, Pessoa** raiz){
      if(pessoa->pai == NULL){
        (*raiz) = pessoa->filhoEsquerda;
        pessoa->filhoEsquerda = (*raiz)->filhoDireita;
        (*raiz)->filhoDireita = pessoa;
        (*raiz)->pai = NULL;
        pessoa->pai = (*raiz);
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->pai = pessoa;
        }
      }else{
        Pessoa* pai2 = pessoa->pai;
        Pessoa* aux = pessoa->filhoEsquerda;
        if(pai2->filhoEsquerda == pessoa){
          pai2->filhoEsquerda = aux;
        }else{
          pai2->filhoDireita = aux;
        }
        aux->pai = pai2;
        pessoa->filhoEsquerda = aux->filhoDireita;
        aux->filhoDireita = pessoa;
        pessoa->pai = aux;
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->pai = pessoa;
        }

      }
    }

    void rotaEsquerda(Pessoa* pessoa, Pessoa** raiz){
      if(pessoa->pai == NULL){
        (*raiz) = pessoa->filhoDireita;
        pessoa->filhoDireita = (*raiz)->filhoEsquerda;
        (*raiz)->filhoEsquerda = pessoa;
        (*raiz)->pai = NULL;
        pessoa->pai = (*raiz);
        if(pessoa->filhoDireita != NULL){
          pessoa->filhoDireita->pai = pessoa;
        }
      }else{
        Pessoa* pai2 = pessoa->pai;
        Pessoa* aux = pessoa->filhoDireita;;
        if(pai2->filhoEsquerda == pessoa){
          pai2->filhoEsquerda = aux;
        }else{
          pai2->filhoDireita = aux;
        }
        aux->pai = pai2;
        pessoa->filhoDireita = aux->filhoEsquerda;
        aux->filhoEsquerda = pessoa;
        pessoa->pai = aux;
        if(pessoa->filhoDireita != NULL){
          pessoa->filhoDireita->pai = pessoa;
        }
      }
    }

    void rotaDuplaDireita(Pessoa* pessoa, Pessoa** raiz){
        rotaDireita(pessoa->filhoDireita, raiz);
        rotaEsquerda(pessoa, raiz);
    }

    void rotaDuplaEsquerda(Pessoa* pessoa, Pessoa** raiz){
        rotaEsquerda(pessoa->filhoEsquerda, raiz);
        rotaDireita(pessoa, raiz);
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

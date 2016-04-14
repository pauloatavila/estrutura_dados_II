#include <iostream>
#include <string>
using namespace std;


// class Teste {
//   protected:
//     int variavel;
//   public:
//     Teste();
//     void Aula();
// };
//
// Teste * raiz_teste = NULL;
//
// void Teste::Aula()
// {
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

    void deleteEscolhido (Pessoa ** apagar)
    {
      if (filhoDireita == NULL && filhoEsquerda == NULL)
      {
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
          // raiz = NULL;
        }
      }
      else {
        if (filhoDireita == NULL){
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
          if (filhoEsquerda == NULL){
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
              
          }
        }
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




      // string a = "Acho Que Deu um BUGzinho";
      // if (indicado->idade == this->idade){
      //   a = this->nome;
      //   return a;
      // }
      // else {
      //   if (indicado->idade > this->idade && filhoDireita != NULL){
      //     this->filhoDireita->buscar(indicado);
      //     return a;
      //   }
      //   else {
      //     if (indicado->idade < this->idade && filhoEsquerda != NULL){
      //       this->filhoEsquerda->buscar(indicado);
      //       return a;
      //     }
      //     else
      //       return "Não Encontrado";
      //   }
      //
      // }
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

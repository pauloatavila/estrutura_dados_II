// Meu primeiro programa em C++
#include <iostream>
#include <typeinfo>
using namespace std;
int main(int argc, char **argv){
     char idade;
     cout << "insira idade" << endl;
     cin >> idade;
     cout << typeid(idade).name() << idade << endl;

     return 0;
}

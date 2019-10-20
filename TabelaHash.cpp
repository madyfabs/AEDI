#include <iostream>


using namespace std;

int Fatorar(int Base, int Expoente){

   int Total = 1,i = 1;

   while (i<=Expoente){
    Total = Total * Base;
    Total = Total %10;
    i++;
   }

  return Total;

}

int FuncaoHash(string Chave){

   unsigned long long int Soma = 0;
   int p;

   p = Chave.length();
   p--;
for (unsigned int i=0; i<Chave.length(); ++i){

    Soma = Soma+ (((unsigned char)Chave[i]) * Fatorar(1000000000+7,p));
    Soma = Soma%10;
    p--;

}



return Soma%10;

}

int main(){

   string Nome;

   string Chave;
   int Posicao;

   cout <<"insira um nome \n";
   cin >> Nome;


   Chave = Nome;

  cout <<" CHave " <<Chave;
  Posicao = FuncaoHash(Chave);

  cout << "POSICAO DO HASH = " <<Posicao;



return 0;
}







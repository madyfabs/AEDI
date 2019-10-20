#include <iostream>
#include <locale>

using namespace std;


class Soldado {

private:

    string Nome;
    int Idade;
    string Raca;

public:

    Soldado (){}

    Soldado (string Nome, string Raca,int Idade){
       this->Nome = Nome;
       this->Idade = Idade;
       this->Raca = Raca;
    }
    void setNome (string Nome);
    string getNome ();
    void setIdade (int Idade);
    int getIdade ();
    void setRaca (string Raca);
    string getRaca ();
    void ImprimeSoldado();

};

void Soldado::setRaca(string Raca){
    this->Raca = Raca;
}

string Soldado::getRaca(){

   return this->Raca;
}
void Soldado::setNome(string Nome){

   this->Nome = Nome;

}


string Soldado::getNome(){
   return this->Nome;
}


void Soldado::setIdade(int Idade){
   this->Idade = Idade;
}


int Soldado::getIdade(){
   return this->Idade;
}


void Soldado::ImprimeSoldado(){

    cout << "Nome = "<<Nome <<" "<<"Raca = "<<Raca<<" "<<"Idade = "<<Idade <<" "<<"\n";

}
//--------------------------------------------------------------------------------------

template <class T>
class No {

private:

    T item;
    No<T>* prox;

public:


    No<T>(){

      this->prox = NULL;
    }

    No<T> (T item){

       this->item = item;
       prox = NULL;

    }

    T getItem();
    No<T>* getProx();
    void setItem(T item);
    void setProx (No<T>* prox);
    void setNULL();
    void setNovoNo();



};

template <class T>
T No<T>::getItem(){

  return this->item;
}

template <class T>
No<T>* No<T>::getProx(){
   return prox;
}

template <class T>
void No<T>::setItem(T item){
   this->item = item;
}

template <class T>
void No<T>::setProx(No<T>* prox){
   this->prox = prox;
}

template <class T>
void No<T>::setNULL (){
  this->prox = NULL;
}

template <class T>
void No<T>::setNovoNo (){
 this->prox = new No<T>();
}


//-------------------------------------------------------------------------------
template <class T>
class Lista {

private:

    No<T> *prim, *ult;
    int TAM;
public:

    Lista<T>(){

      TAM = 0;
      prim = new No<T>();
      prim->setNULL();
      ult = prim;

    }

    void Insere(T item);
    No<T>* BuscaItem(string Nome);
    void Remove (string Nome);
    void ImprimeLista();
    No<T>* Antecessor (No<T> *p);


};

template <class T>
void Lista<T>::Insere(T item){
   ult->setNovoNo();
   ult = ult->getProx();
   ult->setNULL();
   ult->setItem(item);
   TAM++;
}

template <class T>
No<T>* Lista<T>::BuscaItem(string Nome){

    No<T>* aux = prim->getProx();

    while (aux != NULL && aux->getItem().getNome() != Nome){

        aux = aux->getProx();
    }

    return aux;
}

template <class T>
No<T>* Lista<T>::Antecessor (No<T> *p) {
	No<T> *a = prim;
	while (a->getProx() != p) {
		a = a->getProx();
	}
	return a;
}

template <class T>
void Lista<T>::Remove(string Nome){


  No<T>* aux = BuscaItem(Nome);

  if (aux != NULL){


     No<T>* ant = Antecessor (aux);

     ant->setProx(aux->getProx());

     if (ant->getProx() == NULL){

        ult = ant;
     }

      delete aux;

  }
}


template <class T>
void Lista<T>::ImprimeLista(){

  No<T>* p = prim->getProx();

  while (p != NULL){

     p->getItem().ImprimeSoldado();

     p = p->getProx();
  }
}
//--------------------------------------------------------------------------------------

template <class T>
class TabelaHash {

private:

    Lista<T> thash[43];

public:

  void InsereHash(T item);
  int FuncaoHash(string Chave);
  int RecuperaIdade(T item);
  void ImprimeHash(int Pos);
  int Fatorar(int Base, int Expoente);

};

template <class T>
int TabelaHash<T>::FuncaoHash(string Chave){

   unsigned long long int Soma = 0;
   int p;
   locale loc;

   p = Chave.length();
   p--;
for (unsigned int i=0; i<Chave.length(); ++i){
    Chave[i] = tolower(Chave[i],loc);
    Soma = Soma+ (((unsigned char)Chave[i]) * Fatorar(31,p));
    Soma = Soma%43;
    p--;

}

return Soma%43;

}

template <class T>
int TabelaHash<T>::Fatorar(int Base, int Expoente){

   int Total = 1,i = 1;

   while (i<=Expoente){
    Total = Total * Base;
    Total = Total %43;
    i++;
   }

  return Total;

}

template <class T>
void TabelaHash<T>::InsereHash(T item){

    int aux;
    string Chave;


    Chave = item.getNome()+item.getRaca();

    aux = FuncaoHash(Chave);

    thash[aux].Insere(item);

}

template <class T>
int TabelaHash<T>::RecuperaIdade(T item){


    int aux;
    int soma=0;
    No<T>* p;



    aux = FuncaoHash(item.getNome()+item.getRaca());
    p = thash[aux].getPrim()->getProx();


    while (p != NULL){

        soma = soma + p->getItem().getIdade();
        p = p->getProx();

    }

    return soma;


}

template <class T>
void TabelaHash<T>::ImprimeHash(int Pos){

  thash[Pos].ImprimeLista();

}

//--------------------------------------------------------------------------------------------

int main(){

TabelaHash<Soldado> thash;


Soldado a ("Fabricio","AZURI",23);
Soldado b ("Leandro","IANTECO",24);
Soldado c ("Benaia","UMASHI",70);
Soldado d ("Paulo","Azuri",60);

thash.InsereHash(a);
thash.InsereHash(b);
thash.InsereHash(c);
thash.InsereHash(d);

int i=0;

while (i<43){

cout <<"POSICAO: "<<i<<"\n";
    thash.ImprimeHash(i);
    i++;
cout <<"\n";
}

 return 0;
}






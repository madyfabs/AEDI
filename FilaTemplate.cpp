#include <iostream>

using namespace std;


class Soldado {

private:

    string Nome;
    int Idade;

public:

    Soldado (){}

    Soldado (string Nome, int Idade){
       this->Nome = Nome;
       this->Idade = Idade;
    }
    void setNome (string Nome);
    string getNome ();
    void setIdade (int Idade);
    int getIdade ();
    void ImprimeSoldado();

};


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

    cout << "Nome = "<<Nome <<" "<<"Idade = "<<Idade <<" "<<"\n";

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
class Fila{

 private:

    No<T> *tras, *frente;
    int TAM;

public:

    Fila (){
      TAM = 0;
      frente = new No<T>();
      frente->setNULL();
      tras = frente;

    }

    void Enfileira (T item);
    void Desinfileira();
    void ImprimeFila();


};

template <class T>
void Fila<T>::Enfileira(T item){

   tras->setNovoNo();
   tras = tras->getProx();
   tras->setItem(item);
   tras->setNULL();
   TAM++;

}

template <class T>
void Fila<T>::Desinfileira(){


    No<T>* aux = frente;

    if (frente == tras){

        cout <<"Fila Vazia \n";
    }else{

    frente = frente->getProx();

    delete aux;

    }

}

template <class T>
void Fila<T>::ImprimeFila(){

   No<T>* p = frente->getProx();

   while (p != NULL){


    p->getItem().ImprimeSoldado();
    p = p->getProx();

   }
}

//-------------------------------------------------------------------------------

int main(){

Fila <Soldado> f;

Soldado a ("aaaaa",23);
Soldado b ("bbbb",27);
Soldado c ("cccc",500);

f.Enfileira(a);
f.Enfileira(b);
f.Enfileira(c);

f.ImprimeFila();

f.Desinfileira();
cout <<"\n";
f.ImprimeFila();

f.Desinfileira();
cout <<"\n";
f.ImprimeFila();

f.Desinfileira();
cout <<"\n";
f.ImprimeFila();

f.Desinfileira();
cout <<"\n";
f.ImprimeFila();


}










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
    void ordena (No<T>* ini);
    No<T>* getPrim();


};

template <class T>
No<T>* Lista<T>::getPrim(){
   return this->prim;
}

template <class T>
void Lista<T>::ordena (No<T>* ini){

    No<T>* i,*j,*temp;

    i = ini;

    for (i=ini;i!= NULL;i = i->getProx()){

        for (j = i->getProx(); j != NULL; j = j->getProx()){


            if (i->getItem().getIdade > j->getItem().getIdade()){

                   temp = i->getItem();
                   i->setItem(j->getItem());
                   j->setItem(temp);


            }
        }
     }
}

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


int main (){

Lista <Soldado> l;

Soldado a ("Fabricio",2888);
Soldado b ("Leandro",27);
Soldado c ("Benaio",500);

l.Insere(a);
l.Insere(b);
l.Insere(c);



l.ImprimeLista();

l.ordena(l.getPrim());

l.ImprimeLista();


return 0;

}

#include <iostream>

using namespace std;

class Chave{

private:

    int Inteiro;

public:

    Chave (){}
    Chave (int Inteiro){
      this->Inteiro = Inteiro;
    }

    void Imprime();
    int getInteiro();


};

int Chave::getInteiro(){
   return this->Inteiro;
}

void Chave::Imprime(){
  cout <<Inteiro <<" ";
}
//-------------------------------------------------------------------------------------------------
template <class T>
class No {

private:

    No<T>* esq,*dir;
    T item;

public:

        No<T>(T item){
            this->item = item;
            this->esq = NULL;
            this->dir = NULL;
         }

         No<T>* getEsq();
         No<T>* getDir();
         T getChave();
         void setChave(T item);
         void setEsq(No<T>* item);
         void setDir(No<T>* item);

};

template <class T>
 No<T>* No<T>::getEsq(){
    return this->esq;
}

template <class T>
T No<T>::getChave(){
  return this->item;
}

template <class T>
void No<T>::setChave(T item){
  this->item = item;
}

template <class T>
 No<T>* No<T>::getDir(){
    return this->dir;
}

template <class T>
 void No<T>::setEsq(No<T>* no){
    this->esq = no;
}

template <class T>
 void No<T>::setDir(No<T>* no){
    this->dir = no;
}


//-------------------------------------------------------------------------------------------------

template <class T>
class ABB{

private:

    No<T>* raiz;

public:

     ABB(){

       raiz = NULL;
     }

     void Inserir(T Chave);
     void InserirAux (No<T>* Raiz, T Chave);
     No<T>* getRaiz();
     void ImprimePreOrdem (No<T>* Raiz);
     void ImprimeOrdem (No<T>* Raiz);
     void ImprimePosOrdem (No<T>* Raiz);
     int AlturaArvore (No<T>* Raiz);
     No<T>* Busca (No<T>* Raiz, T item);
     void ImprimeNo(No<T>* no); //APENAS PARA TESTAR SE A BUSCA ESTÁ RETORNANDO O PONTEIRO REALMENTE
     No<T>* RemoveItem (No<T>* Raiz, T item);
     No<T>* BuscaMenor(No<T>* Raiz);

};

template <class T>
No<T>* ABB<T>::getRaiz(){
   return raiz;
}

template <class T>
void ABB<T>::Inserir (T Chave){

    if (raiz == NULL){

        raiz = new No<T>(Chave);

    }
    else{

        InserirAux(raiz,Chave);

      }


}

template <class T>
void ABB<T>::InserirAux (No<T>* Raiz,T Chave){


   if (Chave.getInteiro() < Raiz->getChave().getInteiro()){

        if (Raiz->getEsq() == NULL){

            No<T>* aux = new No<T>(Chave);
            Raiz->setEsq(aux);

        }
        else {

            InserirAux (Raiz->getEsq(), Chave);

          }
     }
     else if (Chave.getInteiro() > Raiz->getChave().getInteiro()){

           if (Raiz->getDir() == NULL){

               No<T>* aux = new No<T>(Chave);
               Raiz->setDir(aux);
             }

        else{

          InserirAux(Raiz->getDir(),Chave);
           }


    }
}

template <class T>
int ABB<T>::AlturaArvore (No<T>* Raiz){

     if (Raiz == NULL){

        return -1;
     }
     else {

        int ae = AlturaArvore(Raiz->getEsq());
        int ad = AlturaArvore(Raiz->getDir());
         if (ae < ad){

            return ad+1;
         }
         else {
            return ae+1;
         }
     }
}

template <class T>
No<T>* ABB<T>::Busca(No<T>* Raiz, T item){

    if (Raiz == NULL || Raiz->getChave().getInteiro() == item.getInteiro()){
       return Raiz;
    }

    if (Raiz->getChave().getInteiro() > item.getInteiro()){
       return Busca (Raiz->getEsq(), item);
    }
    else if (Raiz->getChave().getInteiro() < item.getInteiro()){
       return Busca (Raiz->getDir(), item);
    }
    else{
        return NULL;
    }

}

template <class T>
void ABB<T>::ImprimePreOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        Raiz->getChave().Imprime();
        ImprimePreOrdem(Raiz->getEsq());
        ImprimePreOrdem(Raiz->getDir());

    }
}

template <class T>
void ABB<T>::ImprimeOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimeOrdem(Raiz->getEsq());
        Raiz->getChave().Imprime();
        ImprimeOrdem(Raiz->getDir());

    }
}

template <class T>
void ABB<T>::ImprimePosOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimePosOrdem(Raiz->getEsq());
        ImprimePosOrdem(Raiz->getDir());
        Raiz->getChave().Imprime();

    }
}

template <class T>
No<T>* ABB<T>::RemoveItem (No<T>* Raiz, T item){

    if(Raiz == NULL){
        return Raiz;
     }

	else if(item.getInteiro() < Raiz->getChave().getInteiro()){
            Raiz->setEsq(RemoveItem(Raiz->getEsq(),item));
	   }
	else if (item.getInteiro() > Raiz->getChave().getInteiro()){
            Raiz->setDir(RemoveItem(Raiz->getDir(),item));
	  }


	else {
		// SEM FILHOS
		if(Raiz->getEsq() == NULL && Raiz->getDir() == NULL) {
			delete Raiz;
			Raiz = NULL;
		}
		//1 FILHO
		else if(Raiz->getEsq() == NULL) {
			No<T>* temp = Raiz;
			Raiz = Raiz->getDir();
			delete temp;
		}
		else if(Raiz->getDir() == NULL) {
			No<T>* temp = Raiz;
			Raiz = Raiz->getEsq();
			delete temp;
		}
		// 2 FILHOS
		else {
			No<T>* temp = BuscaMenor(Raiz->getDir());
			Raiz->setChave(temp->getChave());
			Raiz->setDir(RemoveItem(Raiz->getDir(),temp->getChave()));
		}
	}
	return Raiz;
}

template <class T>
 No<T>* ABB<T>::BuscaMenor(No<T>* Raiz){

    while(Raiz->getEsq() != NULL){
        Raiz = Raiz->getEsq();
      }

	return Raiz;

}


template <class T>
void ABB<T>::ImprimeNo(No<T>* no){

  if (no == NULL){
    cout <<"ITEM N ENCONTRADO";
  }
  else{
   no->getChave().Imprime();
  }
}
//-------------------------------------------------------------------------------------------------
int main (){

   ABB <Chave> av;
   No<Chave>* ab;

    Chave a(8);
    Chave b(10);
    Chave c(14);
    Chave d(15);
    Chave e(17);
    Chave f(18);
    Chave g(19);
    Chave h(20);
    Chave i(21);;



     av.Inserir(a);
     av.Inserir(b);
     av.Inserir(c);
     av.Inserir(d);
     av.Inserir(e);
     av.Inserir(f);
     av.Inserir(g);
     av.Inserir(h);
     av.Inserir(i);

   //TESTA IMPRESSAO

   cout <<"Imprimindo em Pre-ordem "<<"\n";

    av.ImprimePreOrdem(av.getRaiz());

     cout <<"\nImprimindo em ordem "<<"\n";

    av.ImprimeOrdem(av.getRaiz());

     cout <<"\nImprimindo em Pos-Ordem "<<"\n";

    av.ImprimePosOrdem(av.getRaiz());

    cout <<"\n\n";

    cout <<"TESTANDO REMOCAO: \n";
    ab = av.RemoveItem(av.getRaiz(),a); //REMOVENDO O PRIMEIRO ITEM PRA TESTE


    //REIMPRIMINDO APOS REMOÇÃO

    cout <<"Imprimindo em Pre-ordem "<<"\n";

    av.ImprimePreOrdem(ab);

     cout <<"\nImprimindo em ordem "<<"\n";

    av.ImprimeOrdem(ab);

     cout <<"\nImprimindo em Pos-Ordem "<<"\n";

    av.ImprimePosOrdem(ab);

   //VERIFICA A ALTURA DA ARVORE

    cout <<"\n\n";

    cout <<"ARVORE TEM ALTURA = "<<av.AlturaArvore(av.getRaiz());

    cout <<"\n\n";

   //TESTA A BUSCA
    cout <<"TESTANDO BUSCA: \n";

     av.ImprimeNo(av.Busca(av.getRaiz(),f)); //TESTANDO CASO ENCONTRE O ITEM
     cout <<"\n";
     av.ImprimeNo(av.Busca(av.getRaiz(),a)); //TESTANDO CASO N ENCONTRE O ITEM

    cout <<"\n";



    return 0;

}







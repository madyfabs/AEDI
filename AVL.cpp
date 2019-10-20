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
    int alt;

public:

        No<T>(T item){
            this->item = item;
            this->esq = NULL;
            this->dir = NULL;
            this->alt = 0;
        }

         void setAlt(int alt);
         int getAlt ();
         No<T>* getEsq();
         No<T>* getDir();
         T getChave();
         void setChave(T item);
         void setEsq(No<T>* item);
         void setDir(No<T>* item);


};

template <class T>
void No<T>::setAlt(int alt){
   this->alt = alt;
}

template <class T>
int No<T>::getAlt(){
   return this->alt;
}

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
class AVL{

private:

    No<T>* raiz;

public:

    AVL (){
      raiz = NULL;
    }

    No<T>* getRaiz();
    No<T>* BuscaMenor(No<T>* no);
    No<T>* BuscaMaior(No<T>* no);
    int Maior(int x,int y);
    int Altura(No<T>* no);
    void Insere(T item);
    No<T>* Insere(T item, No<T>* no);
    No<T>* Remove(T item, No<T>* no);
    void Remove(T item);
    No<T>* RSD (No<T>* no);
    No<T>* RSE (No<T>* no);
    No<T>* RDE(No<T>* no);
    No<T>* RDD(No<T>* no);
    void ImprimePreOrdem (No<T>* Raiz);
    void ImprimeOrdem (No<T>* Raiz);
    void ImprimePosOrdem (No<T>* Raiz);
    No<T>* Busca (No<T>* Raiz, T item);
    void ImprimeNo(No<T>* no);


};

template <class T>
No<T>* AVL<T>::getRaiz(){
   return this->raiz;
}

template <class T>
No<T>* AVL<T>::BuscaMenor(No<T>* no){

        if(no == NULL){
            return NULL;
        }
        else if(no->getEsq() == NULL){
            return no;
         }
        else{
            return BuscaMenor(no->getEsq());
        }
}

template <class T>
No<T>* AVL<T>::BuscaMaior(No<T>* no){

        if(no == NULL){
            return NULL;
        }
        else if(no->getDir() == NULL){
            return no;
        }
        else{
            return BuscaMaior(no->getDir());
        }
}

template <class T>
int AVL<T>::Maior(int x,int y){

   if (x > y){
    return x;
   }
   else {
    return y;
   }
}

template <class T>
int AVL<T>::Altura(No<T>* no){

   if (no == NULL){
     return -1;
   }
   else{
     return no->getAlt();
   }
}

template <class T>
void AVL<T>::Insere(T item){

    raiz = Insere(item, raiz);
}

template <class T>
No<T>* AVL<T>::Insere(T item, No<T>* no){

      if(no == NULL){
            no = new No<T>(item);

        }
        else if(item.getInteiro() < no->getChave().getInteiro()){

            no->setEsq(Insere(item, no->getEsq()));

           if(Altura(no->getEsq()) - Altura(no->getDir()) == 2){
                if(item.getInteiro() < no->getEsq()->getChave().getInteiro()){
                    no = RSD(no);
                }
                else{
                    no = RDD(no);
                }
            }
        }

        else if(item.getInteiro() > no->getChave().getInteiro()){

            no->setDir(Insere(item, no->getDir()));

            if(Altura(no->getDir()) - Altura(no->getEsq()) == 2){
                if(item.getInteiro() > no->getDir()->getChave().getInteiro()){
                    no = RSE(no);
                }
                else{
                    no = RDE(no);
                }
            }
        }

        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        return no;
}

template <class T>
void AVL<T>::Remove(T item){

   raiz = Remove(item, raiz);
}

template <class T>
No<T>* AVL<T>::Remove(T item, No<T>* no){

        No<T>* aux;


        if(no == NULL){
            return NULL;
        }


        else if(item.getInteiro() < no->getChave().getInteiro()){
            no->setEsq(Remove(item, no->getEsq()));
        }
        else if(item.getInteiro() > no->getChave().getInteiro()){
            no->setDir(Remove(item, no->getDir()));
        }


        else if(no->getEsq() != NULL && no->getDir() != NULL){

            aux = BuscaMenor(no->getDir());
            no->setChave(aux->getChave());
            no->setDir(Remove(no->getChave(), no->getDir()));
        }

        else{
            aux = no;
            if(no->getEsq() == NULL)
               no = no->getDir();
            else if(no->getDir() == NULL)
                no = no->getEsq();
            delete aux;
        }

        if(no == NULL){
            return no;
        }

        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);


        if(Altura(no->getEsq()) - Altura(no->getDir()) == 2){

            if(Altura(no->getEsq()->getEsq()) - Altura(no->getEsq()->getDir()) == 1){
                  return RSE(no);
            }

            else{
                return RDE(no);
            }
        }


        else if(Altura(no->getDir()) - Altura(no->getEsq()) == 2){

            if(Altura(no->getDir()->getDir()) - Altura(no->getDir()->getEsq()) == 1){
                return RSD(no);

            }
            else{
                return RDD(no);
            }
        }

        return no;
}

template <class T>
No<T>* AVL<T>::RSD(No<T>* no){

        No<T>* aux = no->getEsq();
        no->setEsq(aux->getDir());
        aux->setDir(no);
        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        aux->setAlt(Maior(Altura(aux->getEsq()), no->getAlt())+1);
        cout <<"RSD\n";
        return aux;
}

template <class T>
No<T>* AVL<T>::RSE(No<T>* no){

        No<T>* aux = no->getDir();
        no->setDir(aux->getEsq());
        aux->setEsq(no);
        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        aux->setAlt(Maior(Altura(aux->getDir()), no->getAlt())+1);
        cout <<"RSE\n";
        return aux;
}

template <class T>
No<T>* AVL<T>::RDE(No<T>* no){

        no->setDir(RSD(no->getDir()));
        cout <<"RDE\n";
        return RSE(no);

}

template <class T>
No<T>* AVL<T>::RDD(No<T>* no){

        no->setEsq(RSE(no->getEsq()));
        cout <<"RDD\n";
        return RSD(no);

}

template <class T>
void AVL<T>::ImprimePreOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        Raiz->getChave().Imprime();
        ImprimePreOrdem(Raiz->getEsq());
        ImprimePreOrdem(Raiz->getDir());

    }
}

template <class T>
void AVL<T>::ImprimeOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimeOrdem(Raiz->getEsq());
        Raiz->getChave().Imprime();
        ImprimeOrdem(Raiz->getDir());

    }
}

template <class T>
void AVL<T>::ImprimePosOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimePosOrdem(Raiz->getEsq());
        ImprimePosOrdem(Raiz->getDir());
        Raiz->getChave().Imprime();

    }
}

template <class T>
No<T>* AVL<T>::Busca(No<T>* Raiz, T item){

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
void AVL<T>::ImprimeNo(No<T>* no){

  if (no == NULL){
    cout <<"ITEM N ENCONTRADO";
  }
  else{
   no->getChave().Imprime();
  }
}

//-------------------------------------------------------------------------------------------------
int main(){


   AVL <Chave> av;


    Chave a(56);
    Chave b(62);
    Chave c(103);
    Chave d(24);
    Chave e(16);
    Chave f(50);
    Chave z(84);



     av.Insere(a);
     av.Insere(b);
     av.Insere(c);
     av.Insere(d);
     av.Insere(e);
     av.Insere(f);
     av.Insere(z);
     cout <<"PRE-ORDEM\n";
     av.ImprimePreOrdem(av.getRaiz());
     cout <<"\n";
     cout <<"ORDEM\n";
     av.ImprimeOrdem(av.getRaiz());
     cout <<"\n";
     cout <<"POS-ORDEM\n";
     av.ImprimePosOrdem(av.getRaiz());
     cout <<"\n";

 /*
    //TESTA A BUSCA
    cout <<"TESTANDO BUSCA: \n";

     av.ImprimeNo(av.Busca(av.getRaiz(),f)); //TESTANDO CASO ENCONTRE O ITEM
     cout <<"\n";
     av.ImprimeNo(av.Busca(av.getRaiz(),z)); //TESTANDO CASO N ENCONTRE O ITEM
     cout <<"\n";
     cout <<"Imprimindo a Raiz pra testar se as rotations foram feitas\n";
     av.ImprimeNo(av.getRaiz());
     cout <<"\n";

    cout <<"TESTANDO A REMOCAO \n";
    av.Remove(d);
    cout <<"\n";
    cout <<"PRE-ORDEM\n";
     av.ImprimePreOrdem(av.getRaiz());
     cout <<"\n";  */

return 0;
}









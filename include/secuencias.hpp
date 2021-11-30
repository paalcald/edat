#include <iostream>

using namespace std;

#define FLECHA "↓"

struct par_int{
  int primero ;
  int segundo ;
};

par_int new_par(int p,int s){
    par_int result;
    result.primero = p;
    result.segundo = s;
    return result;
};

bool operator <=(par_int e1,par_int e2){
  return e1.segundo<=e2.segundo;
};

void mostrar(par_int e){
    std::cout << "("<<e.primero<<","<<e.segundo<<")";
};




template <typename T>
struct Nodo_sec{
       T dato;
       Nodo_sec<T> * sig;
};

template <typename T>
struct Secuencia{
  Nodo_sec<T> * primero;
  Nodo_sec<T> * anterior; //puntero al anterior al actual
};

template <typename T>
Secuencia<T> crear(){
  Secuencia<T> s;
  s.primero = new Nodo_sec<T>;
  s.anterior = s.primero;
  return s;
};

template <typename T>
void insertar(Secuencia<T>& s,T e){
  Nodo_sec<T> * new_node = new Nodo_sec<T>;
  new_node->dato = e;
  new_node->sig = s.anterior->sig;
  s.anterior->sig = new_node;
  s.anterior = new_node;
};


template <typename T>
void eliminar(Secuencia<T>& s){
  if(s.anterior->sig != nullptr){
    Nodo_sec<T> * aux = s.anterior->sig;
    s.anterior->sig = aux->sig;
    delete aux;
  }
  else{
    throw runtime_error(" final de la  secuencia");
  }
};

template <typename T>
T actual(const Secuencia<T>& s){
  if(s.anterior->sig != nullptr){
    return s.anterior->sig->dato;
  }
  else{
    throw runtime_error(" final de la  secuencia");
  }
};

template<typename T>
void avanzar(Secuencia<T>& s){
  if(s.anterior->sig != nullptr){
    s.anterior = s.anterior->sig;
  }
  else{
    throw runtime_error("final de la  secuencia");
  }
}


template<typename T>
void reiniciar(Secuencia<T>& s){
  s.anterior = s.primero;
}

template<typename T>
bool fin(Secuencia<T> s){
  return s.anterior->sig == nullptr;
}

template<typename T>  // debe existir una procedimiento void mostrar(T dato) que mande
void mostrar(Secuencia<T> s){
  Nodo_sec<T> * aux = s.primero;
  while(aux->sig != nullptr){
    if(aux == s.anterior){
      std::cout << FLECHA;
    }
    mostrar(aux->sig->dato);
    std::cout <<  " ";
    aux = aux->sig;
  }
  std::cout << std::endl;
}
template <typename T>
void quicksort(Secuencia<T> s, Nodo_sec<T>* primero, Nodo_sec<T>* ultimo)
{
  if (primero == ultimo || s.primero == ultimo) {
  } else {
    T pivote = ultimo->dato;
    Nodo_sec<T>* ultimo_menor = primero;
    Nodo_sec<T>* ultimo_mayor = ultimo;
    colocar_segun(s, pivote, ultimo_menor, ultimo_mayor);
    quicksort(s, primero, ultimo_menor);
    Nodo_sec<T>* ultimo_igual = ultimo_menor->sig;
    while (ultimo_igual != ultimo && ultimo_igual->sig->dato <= ultimo_igual->dato)
      ultimo_igual = ultimo_igual->sig;
    quicksort(s, ultimo_igual, ultimo_mayor);
  }
}

template <typename T>
void colocar_segun(Secuencia<T> s, T p,
		   Nodo_sec<T>*& ultimo_menor,
		   Nodo_sec<T>*& ultimo_mayor)
{
  //Make it so we set actual to the first node we need to order
  Nodo_sec<T>* nodo = s.primero;
  while(nodo->sig != ultimo_menor->sig)
    nodo = nodo->sig;
  
  int pendientes = 0;
  Nodo_sec<T>* to_the_end = nodo;
  while(to_the_end != ultimo_mayor) {
    to_the_end = to_the_end->sig;
    pendientes++;
  }

  while(pendientes != 0) {
    if (!(p <= nodo->sig->dato)) {
      if (nodo->sig != ultimo_menor->sig)
	mover_sig_tras(*nodo, *ultimo_menor);
      else {
	nodo = nodo->sig;
      }
      ultimo_menor = ultimo_menor->sig;
      pendientes--;
    } else if (!(nodo->sig->dato <= p)) {
      mover_sig_tras(*nodo, *ultimo_mayor);
      ultimo_mayor = ultimo_mayor->sig;
      pendientes--;
    } else {
      nodo = nodo->sig;
      pendientes --;
    }
  }
  reiniciar(s);
}

template <typename T>
void mover_sig_tras(Nodo_sec<T>& a, Nodo_sec<T>& b)
{
  Nodo_sec<T>* tmp = a.sig;
  a.sig = a.sig->sig;
  tmp->sig = b.sig;
  b.sig = tmp;
}
template <typename T> 
void ordenar(Secuencia<T> s)
{
  Nodo_sec<par_int>* ultimo_menor = s.primero;
     while(!fin(s)) {
      avanzar(s);
    }
    Nodo_sec<par_int>* ultimo_mayor = s.anterior;
    reiniciar(s);
    quicksort(s, ultimo_menor, ultimo_mayor);
}

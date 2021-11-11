//template <T> // T debe tener definido el operador <=
//void ordenar(Secuencia<T>& s) //ordena la secuencia s,00
#include "secuencias.hpp"

int main(){
  for (int i = 0; i < 10; i++){
    srand(i);
    Secuencia<par_int> s1 = crear<par_int>();
    for (int i = 0; i < 10; i++)
      insertar(s1, new_par(0, rand() % 10 ));
    reiniciar(s1);
    mostrar(s1);
    Nodo_sec<par_int>* ultimo_menor = s1.primero;
     while(!fin(s1)) {
      avanzar(s1);
    }
    Nodo_sec<par_int>* ultimo_mayor = s1.anterior;
    reiniciar(s1);
    quicksort(s1, ultimo_menor, ultimo_mayor);
    mostrar(s1);
    std::cout <<std::endl;
  }
    return 0;
}

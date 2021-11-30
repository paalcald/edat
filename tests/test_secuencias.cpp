#include "secuencias.hpp"

int test()
{
  bool funciona = 1;
  for (int i = 0; i < 10; i++){
    srand(i);
    Secuencia<par_int> s1 = crear<par_int>();
    for (int i = 0; i < 10; i++)
      insertar(s1, new_par(0, rand() % 1000 ));
    reiniciar(s1);
    ordenar(s1);
    bool esta_ordenado = 1;
    par_int este, siguiente;
    for (int i = 0; i < 9; i++) {
      este = actual(s1);
      avanzar(s1);
      siguiente = actual(s1);
      if (!(este <= siguiente))
	esta_ordenado = 0;
    }
    if (!esta_ordenado)
      funciona = 0;
  }
    return !funciona;
}

int main()
{
  std::cout << "Testing Secuencias\n";
  if (test())
    std::cout << "Test fallido, no funciona" << std::endl;
  else
    std::cout << "All tests passed\n";
  return 0;
}

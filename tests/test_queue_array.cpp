#include <iostream>
#include "queue_list.hpp"

using namespace pab;

int main()
{
  Queue<int> p1;
  p1.push(4);
  p1.push(5);
  p1.push(6);
  p1.pop();
  p1.push(7);
  p1.push(8);
  p1.push(10);
  p1.push(11);
  std::cout <<"p1 has size " << p1.size() << "; p1 = " << p1 << ";\n";
  while (!p1.empty()) {
    std::cout << p1.front() << "\n";
    p1.pop();
  }
}

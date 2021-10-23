#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

//forward declaration for friend functions

namespace pab{
  template <typename T> struct Node;
  template <typename T> class Stack;
}

template <typename T> std::ostream &operator<< (std::ostream& out, const pab::Stack<T>& p);

//class declarations

namespace pab{  
  template <typename T>
  struct Node {
    T e;
    Node<T>* n;
  };

  template <typename T>
  class Stack {
  private:
    Node<T>* stack;
    int _size;
    
  public:
    Stack();
    ~Stack();
    void empty_stack(void);
    void push(const T& e);
    void pop(void);
    T& top(void) const;
    bool empty(void) const;
    int size(void) const;
    
    friend std::ostream& ::operator<< <T> (std::ostream& out, const Stack<T>& p);
  };
}

//methods and functions instantiations

template <typename T>
pab::Stack<T>::Stack()
{
  empty_stack();
}

template <typename T>
pab::Stack<T>::~Stack()
{
  if (!empty())
    std::cout << "Stack no vacia liberada.\n";
  while(!empty())
    pop();
}

template <typename T>
void pab::Stack<T>::empty_stack(void)
{
  stack = nullptr;
  _size = 0;
}

template <typename T>
void pab::Stack<T>::push(const T& e)
{
  Node<T>* tmp = new Node<T>;
  tmp->n = stack;
  tmp->e = e;
  stack = tmp;
  _size++;
}

template <typename T>
void pab::Stack<T>::pop(void)
{
  if (empty())
    throw std::invalid_argument("pop() is undefined for an empty stack.");
  Node<T>* tmp = stack;
  stack = stack->n;
  delete tmp;
  _size--;
}

template <typename T>
T& pab::Stack<T>::top(void) const
{
  if (empty())
    throw std::invalid_argument("pop() is undefined for an empty stack.");
  return stack->e;
}

template <typename T>
bool pab::Stack<T>::empty(void) const
{
  return (stack == nullptr);
}

template <typename T>
int pab::Stack<T>::size(void) const
{
  return _size;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const pab::Stack<T>& p)
{
  if (p.empty())
    out << "[]";
  out << "[";
  for (pab::Node<T>* node = p.stack; node != nullptr; node = node->n)
    out << node->e << ", ";
  out << "\033[2D]";
  return out;
}

#endif //STACK_H

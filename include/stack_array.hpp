#ifndef STACK_H
#define STACK_H "Array Implementation"

#include <iostream>
#include <stdexcept>

#define INIT_CAP 4

namespace pab {
  template <typename T> class Stack;
}

template <typename T> std::ostream& operator<< (std::ostream& out, const pab::Stack<T>& p);


namespace pab {
  template <typename T>
  class Stack {
  private:
    T* _stack;
    int _size;
    int _capacity;
    
  public:
    Stack();
    ~Stack();
    void empty_stack(void);
    void push(const T& e);
    void pop(void);
    T& top(void) const;
    bool empty(void) const;
    bool full(void) const;
    int size(void) const;
    friend std::ostream& ::operator<< <T>(std::ostream& out, const pab::Stack<T>& p);
  };
}

template <typename T>
pab::Stack<T>::Stack()
{
  empty_stack();
}

template <typename T>
pab::Stack<T>::~Stack()
{
  if(!empty())
    std::cout << "Non empty queue freed.\n";
  delete[] _stack;
}

template <typename T>
void pab::Stack<T>::empty_stack(void)
{
  _stack = new T[INIT_CAP];
  _size = 0;
  _capacity = INIT_CAP;
}

template <typename T>
void pab::Stack<T>::push(const T& e)
{
  if (!full()) {
    _stack[_size] = e;
    _size++;
  }
  else {
     T* nueva_pila = new T[_capacity*2];
     for (int i = 0; i < _capacity; i++) {
       nueva_pila[i] = _stack[i];
     }
     delete[] _stack;
     _stack = nueva_pila;

     _stack[_size] = e;
     _size++;
     _capacity*=2;
  }
}

template <typename T>
void pab::Stack<T>::pop(void)
{
  if(empty())
    throw std::invalid_argument("pop() is undefined for an empty stack.");

  _size--;
}

template <typename T>
T& pab::Stack<T>::top(void) const
{
  if (empty())
    throw std::invalid_argument("top() is undefined for an empty stack.");

  return _stack[_size - 1];
}

template <typename T>
bool pab::Stack<T>::empty(void) const
{
  return (_size == 0);
}

template <typename T>
int pab::Stack<T>::size(void) const
{
  return _size;
}

template <typename T>
bool pab::Stack<T>::full(void) const
{
  return (_size == _capacity);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const pab::Stack<T>& p)
{
  if (p.empty())
    out << "[]";
  out << "[";
  for (int i = 0; i < p._size; i++)
    out << p._stack[i] << ", ";
  out << "\033[2D]";
  return out;
}

#endif //STACK_H

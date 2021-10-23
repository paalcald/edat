#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

namespace pab {
  
  template <typename T>
  struct Node {
    T e;
    Node<T>* n;
  };
  
  template <typename T>
  class Queue {
  private:
    Node<T>* _front;
    Node<T>* _back;
    int _size;

  public:
    Queue();
    ~Queue();
    void empty_queue(void);
    void push(const T& e);
    void pop(void);
    T& front(void) const;
    T& back(void) const;
    bool empty(void) const;
    int size(void) const;
    friend std::ostream& operator<< (std::ostream& out, const Queue<T>& p)
    {
      if (p.empty())
	out << "[]";
      out << "[";
      for (Node<T>* node = p._front; node != nullptr; node = node->n)
	out << node->e << ", ";
      out << "\033[2D]";
      return out;
    }
  };
}

template <typename T>
std::ostream &operator<< (std::ostream& out, const pab::Queue<T>& p);

template <typename T>
pab::Queue<T>::Queue()
{
  empty_queue();
}

template <typename T>
pab::Queue<T>::~Queue()
{
  if (!empty())
    std::cout << "Not empty queue freed.\n";
  while(!empty())
    pop();
}

template <typename T>
void pab::Queue<T>::empty_queue(void)
{
  _front = nullptr;
  _back = nullptr;
  _size = 0;
}

template <typename T>
void pab::Queue<T>::push(const T& e)
{
  Node<T>* tmp = new Node<T>;
  tmp->n = nullptr;
  tmp->e = e;
  if (empty()) {
    _front = tmp;
    _back = tmp;
    _size++;
  } else {
    _back->n = tmp;
    _back = _back->n;
    _size++;
  }
}

template <typename T>
void pab::Queue<T>::pop(void)
{
  if (empty())
    throw std::invalid_argument("pop() is undefined for an empty queue.");
  Node<T>* tmp = _front;
  if (size() == 1)
    _back = nullptr;
  _front = _front->n;
  delete tmp;
  _size--;
}

template <typename T>
T& pab::Queue<T>::front(void) const
{
  if (empty())
    throw std::invalid_argument("front() is undefined for an empty queue.");
  return _front->e;
}

template <typename T>
T& pab::Queue<T>::back(void) const
{
  if(empty())
    throw std::invalid_argument("back() is undefined for an empty queue.");
  return _back->e;
}

template <typename T>
bool pab::Queue<T>::empty(void) const
{
  return (_size == 0);
}

template <typename T>
int pab::Queue<T>::size(void) const
{
  return _size;
}

#endif //QUEUE_H

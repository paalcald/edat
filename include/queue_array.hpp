#ifndef QUEUE_H
#define QUEUE_H "Array Implementation"

#include <iostream>
#include <stdexcept>

#define INIT_CAP 4

namespace pab {
  template <typename T> class Queue;
}

template <typename T> std::ostream& operator<< (std::ostream& out, const pab::Queue<T>& p);


namespace pab {
  template <typename T>
  class Queue {
  private:
    T* _queue;
    int _top;
    int _size;
    int _capacity;
    
  public:
    Queue();
    ~Queue();
    void empty_queue(void);
    void push(const T& e);
    void pop(void);
    T& front(void) const;
    bool empty(void) const;
    bool full(void) const;
    int size(void) const;
    friend std::ostream& ::operator<< <T>(std::ostream& out, const pab::Queue<T>& p);
  };
}

template <typename T>
pab::Queue<T>::Queue()
{
  empty_queue();
}

template <typename T>
pab::Queue<T>::~Queue()
{
  if(!empty())
    std::cout << "Non empty queue freed.\n";
  delete[] _queue;
}

template <typename T>
void pab::Queue<T>::empty_queue(void)
{
  _queue = new T[INIT_CAP];
  _top = 0;
  _size = 0;
  _capacity = INIT_CAP;
}

template <typename T>
void pab::Queue<T>::push(const T& e)
{
  if (!full()) {
    _queue[(_top + _size) % _capacity] = e;
    _size++;
  }
  else {
     T* aux_queue = new T[_capacity*2];
     for (int i = 0; i < _capacity; i++) {
       aux_queue[i] = _queue[(_top + i) % _capacity];
     }
     delete[] _queue;
     _queue = aux_queue;

     _queue[_size] = e;
     _top = 0;
     _size++;
     _capacity*=2;
  }
}

template <typename T>
void pab::Queue<T>::pop(void)
{
  if(empty())
    throw std::invalid_argument("pop() is undefined for an empty queue.");

  if (_top < _capacity - 1)
    _top++;
  else
    _top = 0;
  
  _size--;
}

template <typename T>
T& pab::Queue<T>::front(void) const
{
  if (empty())
    throw std::invalid_argument("front() is undefined for an empty queue.");

  return _queue[_top];
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

template <typename T>
bool pab::Queue<T>::full(void) const
{
  return (_size == _capacity);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const pab::Queue<T>& p)
{
  if (p.empty())
    out << "[]";
  out << "[";
  for (int i = p._top; i < p._top + p._size; i++)
    out << p._queue[i%p._capacity] << ", ";
  out << "\033[2D]";
  return out;
}

#endif //QUEUE_H

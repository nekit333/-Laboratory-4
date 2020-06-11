#ifndef TWOWAYQUEUE_H_INCLUDED
#define TWOWAYQUEUE_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
class TwoWayQueue
{

private:
    size_t size;
    size_t count;
    T * data;

public:
    TwoWayQueue();
    TwoWayQueue(size_t size);
    TwoWayQueue(const TwoWayQueue &q);
    ~TwoWayQueue();

    TwoWayQueue<T> & operator=(const TwoWayQueue<T> &q);

    bool pushBack(T value);
    bool pushFront(T value);
    void popBack(T value);
    void popFront(T value);
    void topBack(T &value) const;
    void topFront(T &value) const;
    void clear();
    bool isEmpty()const;
    size_t Size()const;
    void print() const;
};

template<typename T>
TwoWayQueue<T>::TwoWayQueue()
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
TwoWayQueue<T>::TwoWayQueue(size_t size)
{
    if(size < 1)
    {
        size = 1;
    }
    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
TwoWayQueue<T>::TwoWayQueue(const TwoWayQueue &q)
{
    this->size = q.size;
    this->count = q.count;
    this->data = new T[q.size];
    for(size_t i=0;i<q.count;i++)
    {
        this->data[i]=q.data[i];
    }
}

template<typename T>
TwoWayQueue<T>::~TwoWayQueue()
{
    if(data) delete [] data;
}

template<typename T>
TwoWayQueue<T> & TwoWayQueue<T>::operator=(const TwoWayQueue<T> &q)
{
    if(data)
        delete [] data;
    this->size = q.size;
    this->count = q.count;
    this->data = new T[q.size];
    for(size_t i=0;i<q.count;i++)
    {
        this->data[i]=q.data[i];
    }
}

template<typename T>
bool TwoWayQueue<T>::pushBack(T value)
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }
    return false;
}

template<typename T>
bool TwoWayQueue<T>::pushFront(T value)
{
    int i;
    for (i=count;i>0; i--)
    {
      data[i]=data[i-1];
    }
    if(count < size)
    {
        data[0] = value;
        ++count;
        return true;
    }
    return false;
}

template<typename T>
void TwoWayQueue<T>::popFront(T value)
{
        data[0] = value;
}

template<typename T>
void TwoWayQueue<T>::popBack( T value)
{
        data[count-1] = value;
}
template<typename T>
void TwoWayQueue<T>::topFront(T &value) const
{
        value = data[0];
}

template<typename T>
void TwoWayQueue<T>::topBack(T &value) const
{
        value = data[count-1];
}

template<typename T>
void TwoWayQueue<T>::clear()
{
    count = 0;
}

template<typename T>
size_t TwoWayQueue<T>::Size()const
{
    return size;
}

template<typename T>
bool TwoWayQueue<T>::isEmpty()const
{
    return count == 0;
}

template<typename T>
void TwoWayQueue<T>::print() const
{
    cout << "Two-way queue size: " << size << ", count: " << count << endl;
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

#endif // TWOWAYQUEUE_H_INCLUDED

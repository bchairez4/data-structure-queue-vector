/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: std::vector implementation of std::queue                          *
*    Advantages:                                                             *
*       -Fast operations: O(1)amortized push(); O(1) front() and back()      *
*       -Built in vector size tracking and functions are helpful             *
*    Limitations:                                                            *
*       -pop() is O(N) everytime due to scooting of internal vector          *
*       -No way to access anything in the middle or end from the queue       *
*****************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

// FIFO. Front of the line corresponds to the beginning of the vector.
template <class T>
class Queue {
    private:
        std::vector<T> queue_;
    public:
        Queue();
        Queue(const int& capacity, const T& data);
        Queue(const Queue<T>& other);
        ~Queue();
        T& operator=(const Queue<T>& other);
        void push(const T& data);
        void pop(); // Pops front
        T& front();
        T& back();
        bool empty() const;
        int size() const;
};

#endif

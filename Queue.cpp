#include "Queue.h"

/*****************************************************************************
    Constructors/ Destructor
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
Queue<T>::Queue() {}

// Fill Constructor
// Time Complexity: O(N), where N is the number of elements to fill.
template <class T>
Queue<T>::Queue(const int& capacity, const T& data) {
    if (capacity <= 0) {
        std::vector<T> temp(1, data);
        queue_.swap(temp);
        return;
    }

    std::vector<T> temp_queue(capacity, data);
    queue_.swap(temp_queue);
}

// Copy Constructor
// Time Complexity: O(N), where N is the number of elements in the other queue.
template <class T>
Queue<T>::Queue(const Queue<T>& other) {
    std::vector<T> temp_queue(other.queue_);
    queue_.swap(temp_queue);
}

// Time Complexity: O(N), where N is the number of elements that are in the queue.
template <class T>
Queue<T>::~Queue() {
    queue_.clear();
}

/*****************************************************************************
    Operator Overloading
*****************************************************************************/
// Time Complexity: O(N), where N is the number of elements in the other queue
template <class T>
T& Queue<T>::operator=(const Queue<T>& other) {
    std::vector<T> temp_queue(other.queue_);
    queue_.swap(temp_queue);
}

/*****************************************************************************
    Data Manipulation
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
void Queue<T>::push(const T& data) {
    queue_.push_back(data);
}

// Time Complexity: O(N), where N is the number of elements left that need to be scooted 
//!!WARNING: UNDEFINED BEHAVIOR IF QUEUE IS EMPTY. 
template <class T>
void Queue<T>::pop() {
    if (!empty()) {
        queue_.erase(queue_.begin());   //Involves scooting   
    }
}

// Time Complexity: O(1)        
//!!WARNING: UNDEFINED BEHAVIOR IF QUEUE IS EMPTY.
template <class T>
T& Queue<T>::front() {
    return queue_.front();
}

// Time Complexity: O(1)        
//!!WARNING: UNDEFINED BEHAVIOR IF QUEUE IS EMPTY.
template <class T>
T& Queue<T>::back() {
    return queue_.back();
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
bool Queue<T>::empty() const {
    return queue_.empty();
}

// Time Complexity: O(1)
template <class T> 
int Queue<T>::size() const {
    return queue_.size();
}

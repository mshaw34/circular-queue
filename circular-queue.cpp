#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    size_ = 0;
    capacity_ = 16;
    head_ = 0;
    tail_ = 0;
    items_= new QueueItem [capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    size_ = 0;
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    items_= new QueueItem [capacity_];
}

CircularQueue::~CircularQueue()
{
    delete [] items_;
}

bool CircularQueue::empty() const
{
    if (size_==0)
        return true;
    return false;
}

bool CircularQueue::full() const
{
    if (size_ == capacity_)
        return true;
    return false;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if (full())
        return false;
    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if (empty())
        return EMPTY_QUEUE;
    QueueItem temp = peek();
    head_ = (head_ + 1) % capacity_;
    size_--;
    return temp;
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if (empty())
        return EMPTY_QUEUE;
    return items_[head_];
}

void CircularQueue::print() const
{

}

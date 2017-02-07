#include <iostream>
#include "a2_circular_queue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	capacity_=16;
	items_ = new QueueItem[16];
	size_=0;
	head_=0;
	tail_=0;
}

CircularQueue::CircularQueue(unsigned int cap)
{
	capacity_=cap;
	items_ = new QueueItem[cap];
	size_=0;
	head_=0;
	tail_=0;
}

CircularQueue::~CircularQueue()
{
	delete items_;
}

bool CircularQueue::empty() const
{    
	return (size_==0);
}

bool CircularQueue::full() const
{
	return (size_==capacity_);
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (full()){
		return false;
	}
	items_[tail_]=value;
	tail_++;
	tail_%=(capacity_);
	size_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if (empty()){
		return EMPTY_QUEUE;
	}
	QueueItem temp= items_[head_];
	head_++;
	head_%=(capacity_);
	size_--;
	return temp;
}

QueueItem CircularQueue::peek() const
{
	if (empty()){
		return EMPTY_QUEUE;
	}
	return items_[head_];
}

void CircularQueue::print() const
{
	for(int i=head_;i<=head_+size_;i++){
		cout<<items_[i%size_]<<" ";
	}
	cout<<endl;
}


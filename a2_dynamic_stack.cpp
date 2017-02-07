#include <iostream>
#include "a2_dynamic_stack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	init_capacity_=16;
	capacity_=16;
	items_ = new StackItem[16];
	size_=0;
}

DynamicStack::DynamicStack(unsigned int cap)
{
	init_capacity_=cap;
	capacity_=cap;
	items_ = new StackItem[cap];
	size_=0;
}

DynamicStack::~DynamicStack()
{
	delete items_;
}

bool DynamicStack::empty() const
{
	return (size_==0);
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_==capacity_){
		StackItem* temp = new StackItem [capacity_*2];
		for(int i=0;i<capacity_;i++){
			temp[i]=items_[i];
		}
		capacity_*=2;
		delete items_;
		items_=temp; 
	}
	items_[size_]=value;
	size_++;
}

StackItem DynamicStack::pop()
{
	if (size_==0){
		return EMPTY_STACK;
	}else if (size_<=capacity_/4 && capacity_/2>=init_capacity_){
		StackItem* temp = new StackItem [capacity_/2];
		for(int i=0;i<size_;i++){
			temp[i]=items_[i];
		}
		capacity_/=2;
		delete items_;
		items_=temp;
	}
	size_--;
	return items_[size_];
}

StackItem DynamicStack::peek() const
{
	if (size_==0){
		return EMPTY_STACK;
	}
	return items_[size_-1];
}

void DynamicStack::print() const
{
	for(int i=size_-1;i>=0;i--){
		cout<<items_[i]<<" ";
	}
	cout<<endl;
}


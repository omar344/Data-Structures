#include <iostream>
#include <cassert>
using namespace std;
class Queue {
private:
	int size{};
	int front{};
	int rear{};
	int add_element{};
	int *array{};
public:
    Queue(int size) :size(size){
		array = new int[size];
	}

	~Queue() {
		delete[] array;
	}

bool isFull() {
	return add_element==size;;
}

bool isEmpty() {
	return add_element==0;
}

int next(int pos) {
		pos++;
	if(pos==size)
		return 0;
	return pos;
}

void enqueue(int val) {
	assert(!isFull());
	array[rear]=val;
	rear=next(rear);
	++add_element;
}

int dequeue() {
	assert(!isEmpty());
	int val=array[front];
	front=next(front);
	--add_element;
	return val;
}

void display() {
	cout<<"Front = "<<front <<", -rear = "<<rear<<"\t";
	if(isFull())
		cout<<"Full"<<endl;
	else if(isEmpty()) {
		cout<<"Empty\n\n"<<endl;
	    return;
}

cout<<"\n\n";
	for(int cur=front,stop=0;stop<add_element;++stop,cur=next(cur))
		cout<<array[cur]<<" ";
	cout<<"\n\n";
}

};
int main()
{
	Queue q(3);
	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(11);
q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
q.display();


  return 0;
}

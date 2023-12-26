#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

struct Node {
    int data {};
    Node *next {};
    Node(int value): data(value){}
};

class LinkedList{
private:
    Node *head {};
    Node *tail {};
    int length=0;
public:

void print(){
for(Node* temp=head;temp;temp=temp->next){
    cout<<temp->data<<" ";
}
cout<<"\n";
}

void insert_end(int value){
    Node *node=new Node(value);length++;

    if(head==nullptr)
        head=tail=node;
    else{
        tail->next=node;
        tail=node;
    }
}

Node* get_nth(int n){
    int cnt=0;
    for(Node* temp=head;temp;temp=temp->next)
        if(++cnt==n)
            return temp;
    return nullptr;
}

int search(int value){
    int idx=0;
    for(Node* temp=head;temp;temp=temp->next,idx++)
        if(temp->data==value)
            return idx;
    return -1;
}

int  improved(int value){ 
    Node *prev=nullptr;
    int idx=0;
    for(Node* temp=head;temp;temp=temp->next,idx++){
        if(temp->data==value){
            if(!prev)
                return idx;
            swap(prev->data,temp->data);
            return idx-1;
        }
        prev=temp;
    }
    return -1;
}

int delete_front(){ 
		assert(length);
		Node* cur=head;
		head=head->next;
		delete cur;
}
int size() {
	return length;
}
};
class Queue {
	LinkedList list;
public:

bool is_empty() {
	return list.size()==0;
}

void enqueue(int value) {
	list.insert_end(value);
}

int dequeue() {
	return list.delete_front();
}

void display() {
	list.print();
}
};
int main()
{

Queue q;
	q.enqueue(3);
	q.enqueue(4);
	q.display();
	q.dequeue();
	q.display();

}

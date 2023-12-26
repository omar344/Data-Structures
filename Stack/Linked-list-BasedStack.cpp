#include<iostream>
#include<cassert>
using namespace std;
class Stack {
private:
    struct Node {
        int data{};
        Node* next{};
        Node(int data) : data(data){}

    };
    Node *head{};
public:
int isEmpty(){
    return !head;
}
void push(int value) {
    Node* item=new Node(value);
    item->next=head;
    head=item;
}
int pop() {
     assert(!isEmpty());
     int data=head->data;
     Node *item =head;
     head=head->next;
     delete item;
     return data;
}
int peek() {
    assert(!isEmpty());
    return head->data;
}
};
int main() {
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
cout<<s.peek();
} 


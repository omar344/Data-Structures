#include <iostream>
#include <cassert>
#include <climits>
using namespace std;
struct Node{
	int data{};
	Node* next{};
	Node* prv{};
	Node(int data):data(data){}
	void set(Node *next,Node *prv){
		this->next=next;
		this->prv=prv;
	}
};
class DoubleLinkedList
{
private:
	Node*head{};
	Node*tail{};
	int length=0;
public:
void print(){
	for(Node *temp=head;temp;temp=temp->next)
		cout<<temp->data<<" ";
	cout<<endl;
}
void link(Node* first,Node* second){
	if(first)
		first->next=second;
	if(second)
		second->prv=first;
}
void insert_end(int value){
	Node* item=new Node(value);
	++length;
	if(!head)
		head=tail=item;
	else{
		link(tail,item);
		tail=item;
	}
}
void insert_front(int value){
	Node* item=new Node(value);
	++length;
	if(!head)
		head=tail=item;
	else{
		link(item,head);
		head=item;
	}
}
void insert_sorted(int value){
	if(!length||head->data>=value)
		insert_front(value);
	else if(tail->data<=value)
		insert_end(value);
	else{
		for(Node* cur=head;cur;cur=cur->next){
			if(cur->data>=value){
				Node* middle=new Node(value);
				Node* before=cur->prv;
				Node* after=cur;
				link(before,middle);
				link(middle,after);
				++length;
			}
		}
	}
}
void delete_front(){
	if(!head)
		return;
	head=head->next;
	delete head->prv;
	--length;
	head->prv=nullptr;

}
void delete_end(){
	if(!head)
		return;
	tail=tail->prv;
	delete tail->next;
	--length;
	tail->next=nullptr;
}
Node* delete_and_link(Node *cur){
	Node *ret=cur->prv;
	link(cur->prv,cur->next);
	delete cur;
	--length;
	return ret;
}
void delete_with_key(int value){
	if(!length)
		return;
	else if(head->data==value)
			delete_front();
	else{
		for(Node* temp=head;temp;temp=temp->next){
			if(temp->data==value){
				temp=delete_and_link(temp);
				if(!temp->next)
					tail=temp;
				break;
			}
		}
	}
}
};



int main() {

DoubleLinkedList l;
l.insert_sorted(5);
l.insert_sorted(3);
l.insert_sorted(8);
l.insert_sorted(0);
l.print();
l.delete_with_key(3);
l.print();

	return 0;
}


#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long int
#define ld long double
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
};

int main()
{

    LinkedList list;
        list.insert_end(6);
        list.insert_end(10);
        list.insert_end(8);
        list.insert_end(15);

    list.improved(8);
    list.print();

}

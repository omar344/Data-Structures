#include<iostream>
#include<cassert>
using namespace std;
class Stack{
private:
int size{};
int top{};
int *array{};
public:
Stack(int size):size(size),top(-1) {
	array = new int[size];
}

~Stack() {
    delete[] array;
}

bool is_full() {
	return top == size-1;
}

bool is_empty() {
	return top == -1;
}

void push(int value) {
	assert(!is_full());
    array[++top] = value;
}

int  pop() {
	assert(!is_empty());
    return array[top--];
}

int peek() {
	assert(!is_empty());
    return array[top];
}
void display() {
	for (int i = top; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
}
};
int main() {
	Stack s(10);
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.display();
		cout << s.pop() << endl;
		s.display();
}
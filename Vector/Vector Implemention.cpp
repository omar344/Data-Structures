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
class Vector
{
private:
    int *arr{nullptr};
    int size{0};    // user size
    int capacity{}; // actual size
    void expand_capacity();

public:
    Vector(int size);
    ~Vector();
    void set(int indx, int val);
    void push_back(int val);
    void insert(int ndx, int val);
    int get_back();
    int get_front();
    bool find(int val);
    int get(int index);
    void print();
    //____________**Home Work**_____________________//
    void left_rotate();
    void right_rotate_n(int times);
    int pop(int indx);
    void right_rotate();
    int find_transPostion(int val);
    //___________________(:____________________//
};
void Vector::expand_capacity()
{
    capacity *= 2;
    cout << "Expand capacity to " << capacity << endl;
    int *arr2 = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = arr[i];
    }
    swap(arr, arr2);
    delete[] arr2;
}
Vector::Vector(int size) : size(size), capacity(size * 2)
{
    arr = new int[size];
}
Vector::~Vector()
{
    delete[] arr;
    arr = nullptr;
}
void Vector::set(int indx, int val)
{
    assert(0 <= indx && indx < size);
    arr[indx] = val;
}
void Vector::push_back(int val)
{
    if (size == capacity)
    {
        expand_capacity();
    }
    else
    {
        arr[size++] = val;
    }
}
void Vector::insert(int ndx, int val)
{
    assert(0 <= ndx && ndx < size);
    if (size == capacity)
        expand_capacity();
    // shift all the data  to right first
    for (int i = size - 1; i >= ndx; --i)
    {
        arr[i + 1] = arr[i];
    }
    // add element to array
    arr[ndx] = val;
    size++;
}
int Vector::get_back()
{
    return arr[size - 1];
}
int Vector::get_front()
{
    return arr[0];
}
bool Vector::find(int val)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == val)
            return true;
    }
    return false;
}

int Vector::get(int index)
{
    assert(0 <= index && index < size); // to check valid input ):

    return arr[index];
}

void Vector::print()
{
    cout << "Array Elements" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//____________________________Home Work_________________________________//
void Vector::right_rotate()
{
    if (size == 0)
        return;
    int temp = arr[size - 1];
    for (int i = size - 2; i >= 0; --i)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}
void Vector::left_rotate()
{
    if (size == 0)
        return;
    int temp = arr[0];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}
int Vector ::pop(int indx)
{
    assert(0 <= indx && indx < size);
    int value = arr[indx];
    for (int i = indx; i < size; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
    return value;
}
void Vector::right_rotate_n(int times)
{
    if (size == 0 || times <= 0)
        return;
    times %= size;
    while (times--)
    {
        right_rotate();
    }
}
int Vector::find_transPostion(int val)
{
    if (size == 0)
        return -1;
    int indx = -1;
    for (int i = 0; i < size; ++i)
    {
        if (val == arr[i])
        {
            indx = i;
        }
    }
    if (indx == -1)
        return -1; // Not Found
    else
    {
        if (indx > 0)
            swap(arr[indx], arr[indx - 1]); // one shift left
        else
            return 0; // Special case
    }
    return indx - 1; // indx After shifting
}
int main()
{
    cout << "Enter size of Array (:" << endl;
    int size;
    cin >> size;
    Vector v(size);
    cout << "Enter array elements" << endl;
    for (int i = 0; i < size; ++i)
    {
        int x;
        cin >> x;
        v.set(i, x);
    }
    print();

} 
#include <iostream>
#include <cassert>
using namespace std;

class Vector {

private:
    int* arr = nullptr;
    int size;

public:
    Vector(int size) :
        size(size) {

        if (size < 0)
            size = 1;

        arr = new int[size] {};
    }

    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }

    int get(int idx) {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    void set(int value, int idx) {
        assert(0 <= idx && idx < size);
        arr[idx] = value;
    }

    void print() {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << "\n";
        }
    }

    int find(int value) {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    int get_front() {
        return arr[0];
    }

    int get_back() {
        return arr[size - 1];
    }

    // add a new item in the last of the array
    void push_back(int value) {
        // create a new array with bigger size
        int* arr2 = new int[size + 1];

        // move the old data into the new bigger array
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];

        // add the new element and increase size 
        arr2[size++] = value;

        // change the pointers 
        swap(arr, arr2);
        
        // remove the useless data
        delete[] arr2;
    }
};


int main()
{
    Vector v(5);
    v.set(1, 0);
    v.set(2, 1);
    v.set(3, 2);
    v.set(4, 3);
    v.set(5, 4);

    v.print();

    cout << v.get(3) << "\n";
    cout << v.find(55) << "\n";
    cout << v.find(5) << "\n";

    int n = 5;
    Vector newArr(n);

    for (int i = 0; i < n; i++)
        newArr.set(i, i);
    newArr.print();

    newArr.push_back(20);
    newArr.print();
}
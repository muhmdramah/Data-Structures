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
}
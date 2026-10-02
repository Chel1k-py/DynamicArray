#include <cstddef>
#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class DynamicArray {
    T* data;
    size_t size;
    size_t capacity;
    
public:
    explicit DynamicArray(size_t n) : 
        data(new T[n]()), size(n), capacity(n) {}
    DynamicArray(initializer_list<T> init) : 
        data(new T[init.size()]), size(init.size()), capacity(init.size())
    {
        size_t i = 0;
        for (const T& it : init) 
            data[i++] = it;
    }
    DynamicArray() : data(nullptr), size(0), capacity(0){}
    ~DynamicArray() {delete[] data; }

    T& operator[](size_t n) {return data[n]; }
    const T& operator[](size_t n) const {return data[n]; }

    size_t getcapacite() const {return capacity; }
    bool empty() const {return size == 0; }
    size_t getsize() const {return size; }
};


int main() {
    DynamicArray<int> p1{3, 5, 1, 5};
    DynamicArray<int> p2(3);
    DynamicArray<int> p3;
    

    for (size_t i = 0; i < p1.getsize(); ++i) 
        {cout << p1[i] << "\n";}
    for (size_t i = 0; i < p2.getsize(); ++i) 
        {cout << p2[i] << "\n";}
    for (size_t i = 0; i < p3.getsize(); ++i) 
        {cout << p3[i] << "\n";}

    cout.flush();


    return 0;
}

#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
    T* data;
    size_t size;
    size_t capacity;
    
public:
    DynamicArray(size_t n) : 
        data(new T[n]), size(n), capacity(n * sizeof(T))
    {}
    ~DynamicArray() {delete[] data; }

    T& operator[](size_t n) {return data[n]; }
    const T& operator[](size_t n) const {return data[n]; }

    size_t getsize() const {return size; }
};


int main() {
    DynamicArray<int> p(6);

    for (size_t i = 0; i < p.getsize(); ++i) {p[i] = i * 10;}
    for (size_t i = 0; i < p.getsize(); ++i) 
        {cout << p[i] << "\n";}

    cout.flush();


    return 0;
}

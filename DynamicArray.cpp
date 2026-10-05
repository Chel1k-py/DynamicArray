#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <algorithm>
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

    size_t getcapacity() const {return capacity; }
    bool empty() const {return size == 0; }
    size_t getsize() const {return size; }

    void push_back(const T& new_elem) {
        if (size == capacity) {
            size_t newCap = (capacity == 0) ? 1 : capacity + capacity / 2 + 1;
            T* newData = new T[newCap];
            if (size) copy(data, data + size, newData);
            delete[] data;
            data = newData;
            capacity = newCap;
        }
        data[size++] = new_elem;
    }

    void pop_back() {
        if (size) data[--size] = T{};
    }

    void clear() {
        while (size) data[--size] = T{};
    }

    const T& front() const {return data[0]; }

    const T& back() const {return data[size - 1]; }


};


void check() {
        DynamicArray<int> p1{3, 5, 1, 5};
    DynamicArray<int> p2(1);
    DynamicArray<int> p3;

    p1.push_back(3);
    p2.push_back(3);
    p3.push_back(3);

    cout << "p1: (";
    for (size_t i = 0; i < p1.getsize(); ++i) 
        cout << p1[i] << " ";
    cout << ")\nsize: " << p1.getsize() << " capasity: " << p1.getcapacity() << "\n";
    cout << "p2: (";
    for (size_t i = 0; i < p2.getsize(); ++i) 
        cout << p2[i] << " ";
    cout << ")\nsize: " << p2.getsize() << " capasity: " << p2.getcapacity() << "\n";
    cout << "p3: (";
    for (size_t i = 0; i < p3.getsize(); ++i) 
        cout << p3[i] << " ";
    cout << ")\nsize: " << p3.getsize() << " capasity: " << p3.getcapacity() << "\n";
    cout.flush();

    DynamicArray<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i * 10);
        cout << "size=" << v.getsize()
            << " cap=" << v.getcapacity() << "\n";
    }
    for (size_t i = 0; i < v.getsize(); ++i) cout << v[i] << " ";

    cout << endl;

    DynamicArray<int> v3;
    for (int i = 0; i < 5; ++i) v3.push_back(i);
    cout << "front=" << v3.front() << " back=" << v3.back() << "\n";
    v3.pop_back();
    cout << "after pop: size=" << v3.getsize() << " back=" << v3.back() << "\n";
    v3.clear();
    cout << "after clear: size=" << v3.getsize() << " cap=" << v3.getcapacity() << "\n";
}



int main() {
    check();
    return 0;


}



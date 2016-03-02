#include <thread>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
const int MAX_N = 1234567;
const int CPU_NUMBER = 4;


template <class T>
class Array {
public:
    typedef T value_type;
    Array(int _size = 0) {
        size = _size;
        data = new T[size];
    }
    T& operator[](int x) {
        return data[x];
    }
    T* operator+(int index) {
        return data + index;
    }
    ~Array() {
        delete[] data;
    }
    int getSize() {return size;}
    Array(Array&& other) : data(nullptr), size(0) {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    Array& operator=(Array&& other) {
        if(this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
private:
    T* data;
    int size;
};

template <class T>
void seg_sort(T& data, int st, int ed) {
    std::sort(data + st, data + ed);
}

template <class T>
int getMin(T& data, int* lim, int* current) {
    int index = -1;
    typename T::value_type minVal = std::numeric_limits<typename T::value_type>::max();
    for(int i = 0; i < CPU_NUMBER; i++) {
        if(current[i] != lim[i] && data[current[i]] < minVal) {
            minVal = data[current[i]];
            index = i;
        }
    }
    return index;
}

template <class T>
void merge(T& data, int* lim, int* current) {
    int index;
    int s = 0;
    Array<typename T::value_type> sorted(data.getSize());
    while((index = getMin(data, lim, current)) != -1) {
        sorted[s++] = data[current[index]++];
    }
    data = std::move(sorted);
}

int main() {
    srand(time(0));
    Array<int> data(MAX_N);
    for(int i = 0; i < MAX_N; i++) {
        data[i] = rand();
    }
    std::cout << std::endl;
    std::thread* th[CPU_NUMBER];
    int part = MAX_N / CPU_NUMBER;
    for(int i = 0; i < CPU_NUMBER; i++) {
        th[i] = new std::thread(seg_sort<Array<int>>, std::ref(data), i * part, i == CPU_NUMBER - 1 ? MAX_N : (i + 1) * part);
    }
    for(int i = 0; i < CPU_NUMBER; i++) th[i]->join();
    int* current = new int[CPU_NUMBER];
    int* lim = new int[CPU_NUMBER];
    for(int i = 0; i < CPU_NUMBER; i++) {
        lim[i] = i == CPU_NUMBER - 1 ? MAX_N : part * (i + 1);
        current[i] = part * i;
    }
    merge(data, lim, current);
    bool isSorted = true;
    for(int i = 1; i < MAX_N; i++) {
        if(data[i] < data[i - 1]) {
            std::cout << i << std::endl;
            isSorted = false;
            break;
        }
    }
    std::cout << (isSorted ? "OK" : "ERROR") << std::endl;
}

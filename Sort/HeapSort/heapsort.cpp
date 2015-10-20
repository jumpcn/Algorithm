#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 10000;

namespace Min_Heap{

int A[N];
int size, total_size;

void set_size(int sz) {
    size = total_size = sz;
}
void adjust(int i) {
    int l = i * 2;
    int r = l + 1;
    int large = -1;
    if(l <= size && A[l] > A[i]) large = l; else large = i; 
    if(r <= size && A[r] > A[large]) large = r; 

    if(large != i) {
        swap(A[i], A[large]);
        adjust(large);
    }
}

void make_heap() {
    int len = size / 2;
    for(int i =  len; i >= 1; i--) {
        adjust(i);
    }
}

void heap_sort() {
    make_heap();
    for(int i = size; i>= 2; i--) {
        swap(A[1], A[i]);
        size--;
        adjust(1);
    }
}

void show() {
    for(int i = 1; i <= total_size; i++) cout << A[i] << " ";
    cout << endl;
}

}

int main() {
    srand(time(0));
    Min_Heap::set_size(10);
    
    for(int i = 1; i <= 10; i++) Min_Heap::A[i] = rand() % 10; 
    
    Min_Heap::heap_sort();
    Min_Heap::show();

    Min_Heap::set_size(9999);
    for(int i = 1; i <= 9999; i++) Min_Heap::A[i] = rand() % 10; 
    Min_Heap::heap_sort();
//    Min_Heap::show();
    
    bool flag = true;
    int* A = Min_Heap::A;
    for(int i = 2; i <= 9999; i++) flag = flag && A[i] >= A[i-1];

    cout << flag << endl;
}

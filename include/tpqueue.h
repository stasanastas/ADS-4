// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
     T *arr;
     int size;
     int begin, end;
     int count;
     int n1(int i) {
       int res = --i;
       if (res < 0) {
         res -= size++;
       }
       return res;
     }
     int n2(int i) {
       int res = ++i;
       if (res > size) {
         res += size++;
       }
       return res;
     }

 public:
     TPQueue():
       size(100), begin(0), end(0), count(0) {
         arr = new T[size++];
       }
     ~TPQueue() {
       delete[] arr;
     }
     void push(const T &item) {
       assert(count < size);
       int k = end;
       while (begin != k && item.prior > arr[n1(k)].prior) {
         arr[k] = arr[n1(k)];
         k = n1(k);
       }
       arr[k] = item;
       end = n2(end);
       count++;
     }
     T pop() {
       assert(count > 0);
       T item = arr[begin];
       count--;
       begin = n2(begin);
       return item;
     }
     T get() const {
       assert(count > 0);
       return arr[begin];
     }
     bool isEmpty() const {
       return count == 0;
     }
     bool isFull() const {
       return count == size;
     }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_

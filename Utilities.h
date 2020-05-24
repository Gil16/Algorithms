#ifndef ALGORITHMS_UTILITIES_H
#define ALGORITHMS_UTILITIES_H

template<class T>
struct node {
    node<T> *next;
    T data;
};


template <class T>
static void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif //ALGORITHMS_UTILITIES_H

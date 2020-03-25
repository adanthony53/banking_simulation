//
// Created by ad on 3/24/20.
//

#ifndef BANKING_SIMULATION_ARRAY_H
#define BANKING_SIMULATION_ARRAY_H

#include <cassert>

template <class T>
class Array {
private:
    T* list;
    int size;

public:
    Array(int sz = 50);
    Array(const Array<T> &a);
    ~Array();
    Array<T> &operator = (const Array<T> &a);
    T &operator [] (int i);
    const T &operator [] (int i) const;
    operator T * ();
    operator const T * () const;
    int getSize() const;
    void resize(int sz);
};

template<class T>
Array<T>::Array(int sz) {
    assert(sz >= 0);
    size = sz;
    list = new T [size];
}

template<class T>
Array<T>::Array(const Array<T> &a) {
    size = a.size;
    list = new T [size];
    for (int i = 0; i < size; i++) {
        list[i] = a.list[i];
    }
}

template<class T>
Array<T>::~Array() {
    delete [] list;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &a) {
    if (&a != this) {
        if (size != a.size) {
            delete [] list;
            size = a.size;
            list = new T[size];
        }

        for (int i = 0; i < size; i++) {
            list[i] = a.list[i];
        }
    }
    return *this;
}

template<class T>
T &Array<T>::operator[](int i) {
    assert(i >= 0 && i < size);
    return list[i];
}

template<class T>
const T &Array<T>::operator[](int i) const {
    assert(i >= 0 && i < size);
    return list[i];
}

template<class T>
Array<T>::operator T *() {
    return list;
}

template<class T>
Array<T>::operator const T *() const {
    return list;
}

template<class T>
int Array<T>::getSize() const {
    return size;
}

template<class T>
void Array<T>::resize(int sz) {
    assert(sz >= 0);
    if (sz == size)
        return;

    T* newList = new T[sz];
    int n = sz < size ? sz : size;
    for (int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete [] list;
    list = newList;
    size = sz;
}

#endif //BANKING_SIMULATION_ARRAY_H

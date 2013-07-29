#include "SmartPointer.h"
#include "Exceptions.h"

template<class T>
SmartPointer<T>::SmartPointer()
    : data(0) {

}

template<class T>
SmartPointer<T>::SmartPointer(T *Ptr)
    : data(Ptr) {

}

template<class T>
T* SmartPointer<T>::operator->() {
    return data;
}

template<class T>
T* SmartPointer<T>::take() {
    T* oldData = data;
    data = nullptr;

    return oldData;
}

template<class T>
void SmartPointer<T>::addPointer(T *Ptr) {
    if (data == nullptr) {
        data = Ptr;
    } else {
        throw IllegalPointerSetException();
    }
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
    delete data;
}

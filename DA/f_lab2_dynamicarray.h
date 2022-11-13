#ifndef F_LAB2_DYNAMICARRAY
#define F_LAB2_DYNAMICARRAY

#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        int length;
        T *pointer;
        //int width;
        //int heigth;

    public:
        DynamicArray(T *items, int count);
        DynamicArray();
        DynamicArray(int size);
        DynamicArray(DynamicArray<T> *dynamicArray);

        T Get(int index);
        T &GetRef(int index);

        int GetLength();
        //int GetHeigth();
        //int GetWidth();

        void Set(int index, T value);
        void Resize(int newSize);

        DynamicArray *Copy();

        ~DynamicArray() {
            //cout << "da free" << endl;
            delete[] pointer;
        }
};

//////////////////////////////////////////////////////////////

template <typename T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    pointer = new T[count];
    for (int i = 0; i < count; i++) {
        pointer[i] = items[i];
    }
    length = count;
    //delete []items;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) {
    pointer = new T[size];
    length = size;
}

template <typename T>
DynamicArray<T>::DynamicArray() {
    length = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> *dynamicArray) {
    pointer = new T[dynamicArray->length];
    length = dynamicArray->length;
    for (int i = 0; i < length; i++) {
        pointer[i] = (dynamicArray->pointer)[i];
    }
}

template <typename T>
T DynamicArray<T>::Get(int index) {
    if (index > length || index < 0) {
        throw out_of_range("index out of range");
    }
    return pointer[index];
}

template <typename T>
T &DynamicArray<T>::GetRef(int index) {
    if (index > length || index < 0) {
        throw out_of_range("index out of range");
    }
    //cout << "GetRef" << endl;
    return pointer[index];
}

template <typename T>
int DynamicArray<T>::GetLength() {
    return length;
}
/*
template <typename T>
int DynamicArray<T>::GetWidth() {
    return width;
}

template <typename T>
int DynamicArray<T>::GetHeigth() {
    return heigth;
}
*/

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index > length) {
        throw out_of_range("index out of range");
    }
    pointer[index] = value;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    T *ptr = new T[newSize];
    int copySize = min(newSize, length);
    for (int i = 0; i < copySize; i++) {
        ptr[i] = pointer[i];
    }
    delete[] pointer;
    pointer = ptr;
    length = newSize;
}

template <typename T>
DynamicArray<T> *DynamicArray<T>::Copy() {
    DynamicArray<T> *newList = new DynamicArray<T>(this);
    return newList;
}


#endif

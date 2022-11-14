#ifndef F_LAB2_ARRAYSequence
#define F_LAB2_ARRAYSequence

#include "../Sequence/f_lab2_sequence.h"
#include "f_lab2_dynamicarray.h"

template <typename T>
class ArraySequence: public Sequence<T> {
    private:
        DynamicArray<T> *items;

    public:

        ArraySequence() { this->items = new DynamicArray<T>(); }
        ArraySequence(int size);
        ArraySequence(T *items, int count);
        ArraySequence(DynamicArray<T> *dynamicArray);
        ArraySequence(ArraySequence<T> *src);

        T Get(int index) const override {
            return this->items->Get(index);
        }

        T &GetRef(int index) const override {
            return this->items->GetRef(index);
        }

        
        void Set(int index, T value) override {
            this->items->Set(index, value);
        }
        //void Resize(int newSize) override {
        //    this->items->Resize(newSize);
        //}
        T GetFirst() const override {
            return this->items->Get(0);
        }
        T GetLast() const override {
            return this->items->Get(this->items->GetLength() - 1);
        }
        int GetLength() const override {
            return this->items->GetLength();
        }

        void Append(const T& item) override {
            this->items->Resize(this->items->GetLength() + 1);
            this->items->Set(this->items->GetLength() - 1, item);
        }
        void Prepend(T item) override {
            int size = this->items->GetLength();
            this->items->Resize(this->items->GetLength() + 1);
            for (int i = size - 1; i >= 0; i--) {
                this->items->Set(i + 1, this->items->Get(i));
            }
            this->items->Set(0, item);
        }
        void InsertAt(T item, int index) override;
        Sequence<T> *Concat(Sequence<T> *list) override;
        Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override;

        Sequence<T> *Copy() const override {
            ArraySequence<T> *res = new ArraySequence<T>(this->items);
            return res;
        }

        ~ArraySequence() { delete items; }
};

template <typename T>
void ArraySequence<T>::InsertAt(T item, int index) {
    this->items->Resize(this->items->GetLength() + 1);
    for (int i = this->items->GetLength() - 1; i > index; i--) {
        this->items->Set(i, this->items->Get(i - 1));
    }
    this->items->Set(index, item);

}

template <typename T>
ArraySequence<T>::ArraySequence(T *items, int count) {
    this->items = new DynamicArray<T>(items, count);
}

template <typename T>
ArraySequence<T>::ArraySequence(int size) {
    this->items = new DynamicArray<T>(size);
}

template <typename T>
ArraySequence<T>::ArraySequence(DynamicArray<T> *dynamicArray) {
    this->items = new DynamicArray<T>(dynamicArray);
}

template <typename T>
ArraySequence<T>::ArraySequence(ArraySequence<T> *src) {
    this->items = new DynamicArray<T>(src->items);
}


template <typename T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *list) {
    int oldSize = this->items->GetLength();
    this->items->Resize(oldSize + list->GetLength());
    for (int i = 0; i < list->GetLength(); i++) {
        this->items->Set(oldSize + i, list->Get(i));
    }
    return this;
}

template <typename T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int startIndex, int endIndex) const {
    T *array = new T[endIndex - startIndex + 1];
    for (int i = 0; i < endIndex - startIndex + 1; i++) {
        array[i] = items->Get(startIndex + i);
    }
    ArraySequence<T> *newArraySequence = new ArraySequence(array, endIndex - startIndex + 1);
    delete[] array;
    return newArraySequence;
}


#endif

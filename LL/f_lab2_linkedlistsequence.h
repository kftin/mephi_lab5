#ifndef F_LAB2_LINKEDLISTSequence
#define F_LAB2_LINKEDLISTSequence

#include "f_lab2_linkedlist.h"
#include "../Sequence/f_lab2_sequence.h"

template <typename T>
class LinkedListSequence : public Sequence<T> {
    private:
        LinkedList<T> *items;

    public:
        LinkedListSequence() {
            this->items = new LinkedList<T>; 
        }
        LinkedListSequence(T *items, int count) {
            this->items = new LinkedList<T>(items, count);
        }
        LinkedListSequence(const LinkedListSequence<T> &src) {
            this->items = new LinkedList<T>(src.items);
        }
        LinkedListSequence(LinkedList<T> *list) {
            this->items = new LinkedList<T>(list);
        }

        void Set(int index, T item) override {
            this->items->Set(index, item);
        }

        int GetLength() const override {
            return this->items->GetLength();
        }
        /*int GetHeigth() const override {
            return this->items->GetHeigth();
        }
        int GetWidth() const override {
            return this->items->GetWidth();
        }
*/
        T GetFirst() const override {
            return this->items->GetFirst();
        }
        T GetLast() const override {
            return this->items->GetLast();
        }
        T Get(int index) const override {
            return this->items->Get(index);
        }
        T &GetRef(int index) const override {
            return this->items->GetRef(index);
        }


        Sequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
            LinkedList<T> *list = this->items->GetSubList(startIndex, endIndex);
            LinkedListSequence<T> *listSequence = new LinkedListSequence<T>(list);
            delete list;
            return listSequence;
        }
        void Append(T item) override {
            this->items->Append(item);
        }
        void Prepend(T item) override {
            this->items->Prepend(item);
        }
        void InsertAt(T item, int index) override {
            this->items->InsertAt(item, index);
        }
        Sequence<T> *Concat(Sequence<T> *list) override {
            for (int i = 0; i < list->GetLength(); i++) {
                this->items->Append(list->Get(i));
            }
            return this;
        }

        Sequence<T> *Copy() const override {
            LinkedListSequence<T> *res = new LinkedListSequence<T>(this->items);
            return res;
        }

        ~LinkedListSequence() {
            delete items;
        }
};



#endif

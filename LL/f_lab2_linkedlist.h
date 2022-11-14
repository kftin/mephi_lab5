#ifndef F_LAB2_LINKEDLIST
#define F_LAB2_LINKEDLIST

#include <stdexcept>

using namespace std;

template <typename T>
class LinkedList {
    private:        
        class Element {
            public:
                T data;
                Element *next;
        };
        Element *head;
        Element *tail;

    public:
        int length;

        LinkedList(T *items, int count);
        LinkedList();
        LinkedList(LinkedList<T> *list);

        void Set(int index, T item);
        T GetFirst();
        T GetLast();
        T Get(int index);
        T &GetRef(int index);

        LinkedList<T> *GetSubList(int startIndex, int endIndex);
        int GetLength();

        void Append(const T& item); 
        void Prepend(T item);
        void InsertAt(T item, int index);
        LinkedList<T> *Concat(LinkedList<T> *list);
        LinkedList<T> *Copy();

        ~LinkedList() {
            if (length) {
                Element *ptr = head;
                Element *ptr_prev = head->next;
                for (int i = 0; i < length; i++) {
                    delete ptr;
                    ptr = ptr_prev;
                    if (ptr_prev) {
                        ptr_prev = ptr_prev->next;
                    }
                }
            }
        }
};

///////////////////////////////////////////////////////////////////////

template <typename T>
void LinkedList<T>::Set(int index, T item) {
    Element *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    ptr->data = item;
    
}

template <typename T>
LinkedList<T>::LinkedList(T *items, int count) {
    head = NULL;
    tail = NULL;
    length = count;
    for (int i = 0; i < count; i++) {
        this->Append(items[i]);
    }
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> *list) {
   int size = list->length;
   head = NULL;
   tail = NULL;
   Element *ptr = list->head;
   for (int i = 0; i < size; i++) {
        this->Append(ptr->data);
        ptr = ptr->next;
   }
   length = size;
}

template <typename T>
T LinkedList<T>::GetFirst() {
    return head->data;
}

template <typename T>
T LinkedList<T>::GetLast() {
    return tail->data;
}

template <typename T>
int LinkedList<T>::GetLength() {
    return length;
}

template <typename T>
T LinkedList<T>::Get(int index) {
    if (index < 0 || index >= length) {
        throw out_of_range("Indexes out of range");
    }
    Element *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

template <typename T>
T &LinkedList<T>::GetRef(int index) {
    if (index < 0 || index >= length) {
        throw out_of_range("Indexes out of range");
    }
    Element *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

template <typename T>
void LinkedList<T>::Append(const T& item) {
    if (!head) {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = NULL;
        head = ptr;
        tail = ptr;
        length = 1;
    } else {
        Element *ptr = new Element;
        ptr->data = T(item);
        ptr->next = NULL;
        tail->next = ptr;
        tail = ptr;
        length++;
    }
    cout << "suka" << endl;
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    if (!head) {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = NULL;
        head = NULL;
        tail = NULL;
        length = 1;
    } else {
        Element *ptr = new Element;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        length++;
    }
}

template <typename T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index < 0 || index > length) {
        throw out_of_range("index out of range");
    }
    if (index == 0) {
        this->Prepend(item);
    } else if (index == length) {
        this->Append(item);
    } else {
        Element *ptr = head;
        Element *ptr_prev = ptr->next;
        Element *tmp = new Element;
        tmp->data = item;
        for (int i = 0; i < index - 1; i++) {
            ptr = ptr_prev;
            ptr_prev = ptr_prev->next;
        }
        ptr->next = tmp;
        tmp->next = ptr_prev;
        length++;
    }

}

template <typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        throw invalid_argument("startIndex should be not bigger than endIndex");
    }
    if (startIndex < 0 || endIndex >= length) {
        throw out_of_range("Indexes out of range");
    }
    LinkedList<T> *subList  = new LinkedList<T>();
    int curIndex = 0;
    Element *ptr  = head;
    while (curIndex <= endIndex) {
        if (curIndex >= startIndex) {
            subList->Append(ptr->data);
        }
        ptr = ptr->next;
        curIndex++;
    }
    return subList;
}

template <typename T>
LinkedList<T> *LinkedList<T>::Copy() {
    LinkedList<T> *newList = new LinkedList<T>(this);
    return newList;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list) {
    Element *cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    cur = cur->next;
    cur->next = list->head;
    length += list->length;
    tail = list->tail;
    return this;

}

#endif

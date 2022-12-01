#include <cstring>
#include <iostream>
#include "DA/f_lab2_arraysequence.h"
#include "LL/f_lab2_linkedlistsequence.h"
#include <stdexcept>

int Equal(char *str1, char *str2) {
    int i = 0;
    if (str1 && str2) {
        while(*(str1 + i) != '\0' && *(str2 + i) != '\0') {
            if (*(str1 + i) != *(str2 + i)) {
                return 0;
            }
            i++;
        }
        return 1;
    } else {
        throw invalid_argument("there is no strs");
        return 0;
    }
}

class Word {
    public:
        ArraySequence<int> *occurrence;
        char *word;
        int length;
        int number;

        Word &operator=(Word other) {
            swap(occurrence, other.occurrence);
            swap(word, other.word);
            swap(length, other.length);
            swap(number, other.number);
            return *this;
        }

        Word() {
            this->length = 0;
            this->number = 0;
            this->word = NULL;
            this->occurrence = NULL;
        }
        Word(const Word &src) {
            this->occurrence = new ArraySequence<int>(src.occurrence);
            this->word = new char[src.length];
            copy(src.word, src.word + src.length, this->word);
            this->length = src.length;
            this->number = src.number;
        }
        Word(char *w, int occurr) {
            if (w) {
                this->length = strlen(w);
                this->word = new char[length];
                copy(w, w + length, this->word);
                this->occurrence = new ArraySequence<int>();
                this->occurrence->Append(occurr);
                number = 1;
            } else {
                throw invalid_argument("there is no word");
            }
        }

        int GetLength() {
            return length;
        }

        int GetNumber() {
            return number;
        }

        char *GetWord() {
            return this->word;
        }
        ArraySequence<int> *GetOccurrence() {
            return this->occurrence;
        }

       ~Word() {
            delete occurrence;
            delete []word;
       }
};

template <typename T>
class FTTS
{
    private:
        ArraySequence<LinkedListSequence<T> *> *table;
        int size;
        int amount;

        void Restruct() {
            ArraySequence<LinkedListSequence<T> *> *tmp = new ArraySequence<LinkedListSequence<T> *>(size * 2);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < table->Get(i)->GetLength(); j++) {
                    T w = this->table->Get(i)->GetRef(j);
                    char *word = w.GetWord();
                    
                    cout << (int)strlen(word) << endl;
                    cout << "table restuct, first word: " << endl;
                    for (int p = 0; p < 3; p++) {
                        cout << *(word + p);
                    }
                    cout << " ****" << endl << endl;

                    //ArraySequence<int> *a = w.GetOccurrence();
                    //for (int k = 0; k < a->GetLength(); k++) {
                    //    this->AddWordInPointer(tmp, word, a->Get(k));
                    //}
                }   
            }
            this->size = this->size * 2;
            delete this->table;
            this->table = tmp;
        }

    public:
        FTTS(int count) {
            this->table = new ArraySequence<LinkedListSequence<T> *>(count);
            for (int i = 0; i < count; i++) {
                this->table->Set(i, new LinkedListSequence<T>());
            }
            size = count;
            amount = 0;
        }

        int Hash(char *str, int size_table) {
            int k = 199; //k > alph, some simle number
            int mod = size_table;//size table, simple
            long long h = 0, degree = 1;
            int length = strlen(str);
            for (int i = 0; i < length; i++) {
                int x = (int) (*(str + i) - 'a' + 1);
                h = (h + degree * x) % mod;
                degree = (degree * k) % mod;
            }
            if (h < 0) {
                h *= -1;
            }
            cout << "hash " << h << endl;
            return h;
        }

        void AddWordInPointer(ArraySequence<LinkedListSequence<T> *> *tmp, char *str, int number) {
            if (!str) {
                throw invalid_argument("there is no str, we can't add word in table, stupid man");
            }
            int h = (int)(this->Hash(str, (this->size) * 2));
            int f = 0, i = 0;
            while (!f && i < tmp->Get(h)->GetLength()) {
                T w = tmp->Get(h)->GetRef(i);
                char *word = w.GetWord();
                f = Equal(str, word);
                i++;
            }
            if (!f) {
                T tmp1(str, number);
                auto mylist = tmp->Get(h);
                mylist->Append(tmp1);
                //this->amount++;
            } else {
                this->table->Get(h)->GetRef(i-1).GetOccurrence()->Append(number);
            }
        }


        void AddWord(char *str, int number) {
            if (!str) {
                throw invalid_argument("there is no str, we can't add word in table, stupid man");
            }
            int h = (int)(this->Hash(str, this->size));
            int f = 0, i = 0;
            while (!f && i < this->table->Get(h)->GetLength()) {
                T w = this->table->Get(h)->GetRef(i);
                char *word = w.GetWord();
                f = Equal(str, word);
                i++;
            }
            if (!f) {
                T tmp(str, number);
                auto mylist = this->table->Get(h);
                mylist->Append(tmp);
                this->amount++;
            } else {
                this->table->Get(h)->GetRef(i-1).GetOccurrence()->Append(number);
            }
            cout << endl << "amount/size " << (float)amount/(float)size << endl << endl;
            if ((float)amount/(float)size > 0.75) {
                cout << "restruct: " << endl << endl;
                this->Restruct();
            }
        }

        ArraySequence<int> *Get(char *str) {
            int h = (int)(this->Hash(str, this->size));
            int f = 0, i = 0;
            while (!f && i < this->table->Get(h)->GetLength()) {
                    T w = this->table->Get(h)->GetRef(i);
                    char *word = w.GetWord();
                    f = Equal(str, word);
                    i++;
            }
            if (f) {
                T w = this->table->Get(h)->GetRef(i-1);
                ArraySequence<int> *res = new ArraySequence<int>(w.GetOccurrence());
                return res;
            } else {
                throw invalid_argument("there is no such word in the text. stupid person");
            }
        }


        ~FTTS() {
            for (int i = 0; i < size; i++) {
                delete this->table->Get(i);
            }
            delete this->table;
        }
};

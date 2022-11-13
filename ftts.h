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

        Word() {
            this->length = 0;
            this->number = 0;
            this->word = NULL;
            this->occurrence = NULL;
        }
        Word(const Word &src) {
            cout << "copy" << endl;
            this->occurrence = new ArraySequence<int>(src.occurrence);
            this->word = new char[src.length];
            memcpy(this->word, src.word, src.length);
            this->length = src.length;
            this->number = src.number;
        }
        Word(char *w, int occurr) {
            if (w) {
                this->length = strlen(w);
                this->word = new char[length];
                memcpy(this->word, w, length);
                int *items = new int[1];
                items[0] = occurr;
                this->occurrence = new ArraySequence<int>(items, 1);
                delete []items;
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
            /*cout << this->GetLength() << endl;
            for (int i = 0; i < this->GetLength(); i++) {
                cout << *(this->GetWord() + i);
            }
            cout << endl;
            cout << "free word" << endl;*/
            delete occurrence;
            cout << "free occurrence" << endl;
            delete []word;
            cout << "free char word" << endl;
       }
};

template <typename T>
class FTTS
{
    private:
        ArraySequence<LinkedListSequence<T> *> *table;
        int size;
        int amount;
    public:
        FTTS(int count) {
            this->table = new ArraySequence<LinkedListSequence<T> *>(count);
            for (int i = 0; i < count; i++) {
                this->table->Set(i, new LinkedListSequence<T>());
            }
            size = count;
            amount = 0;
        }

        int Hash(char *str, int size) {
                int k = 199; //k > alph, some simle number
                int mod = size;//size table, simple
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
                return h;
        }

        void AddWord(char *str, int number) {
            if (!str) {
                throw invalid_argument("there is no str, we can't add word in table, stupid man");
            }
            int h = (int)(this->Hash(str, this->size));
            int f = 0, i = 0;
            //LinkedListSequence<T> list = this->table->GetRef(h);
            while (!f && i < this->table->Get(h)->GetLength()) {
                T w = this->table->Get(h)->GetRef(i);
                char *word = w.GetWord();
                f = Equal(str, word);
                i++;
            }
            if (!f) {
                T *tmp = new T(str, number);
                this->table->Get(h)->Append(*(tmp));
                this->amount++;
            } else {
                this->table->Get(h)->GetRef(i-1).GetOccurrence()->Append(number);
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
                ArraySequence<int> *res = w.GetOccurrence();
                return res;
            } else {
                cout << "There is no word in table, stupid man";
                return NULL;
            }
        }

        ~FTTS() {
            for (int i = 0; i < size; i++) {
                delete this->table->Get(i);
            }
            delete this->table;
        }
};

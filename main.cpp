#include <iostream>
#include <string>
#include "LL/f_lab2_linkedlist.h"
#include "DA/f_lab2_dynamicarray.h"
#include "Sequence/f_lab2_sequence.h"
#include "LL/f_lab2_linkedlistsequence.h"
#include "DA/f_lab2_arraysequence.h"
#include "ftts.h"

using namespace std;

int main() {
    /*int k = 199; //k > alph, some simle number
    int mod = 31;//size table, simple
    string str;
    cin >> str;
    long long h = 0, degree = 1;
    for (char c : str) {
        int x = (int) (c - 'a' + 1);
        cout << "x " << (int) (c - 'a' + 1) << endl;
        h = (h + degree * x) % mod;
        cout << "h " <<  h << endl;
        degree = (degree * k) % mod;
        cout << "degree " << degree << endl;
    }
    if (h < 0) {
        h *= -1;
    }
    cout << h << endl;
    */
    //LinkedListSequence<int> *a = new LinkedListSequence<int>();

    /*ArraySequence<LinkedListSequence<int>> *table = new ArraySequence<LinkedListSequence<int>>(3);
    (table->GetRef(0)).Append(3);
    cout << (table->GetRef(0)).GetRef(0) << endl;
    delete table;*/
    /*
    char *str = new char[5];
    for (int i = 0; i < 4; i++) {
        cin >> *(str + i);
    }
    str[4] = '\0';
    Word *a = new Word(str, 1);
    char *w = a->GetWord();
    for (int i = 0; i < a->GetLength(); i++) {
        cout << *(w + i);
    }
    cout << endl;
    ArraySequence<int> *b = a->GetOccurrence();
    for (int i = 0; i < a->GetNumber(); i++) {
        cout << b->Get(i) << endl;
    }
    delete []str;
    delete a;*/

    char *str = new char[3];
    for (int i = 0; i < 2; i++) {
        cin >> *(str + i);
    }
    str[2] = '\0';
    char *str1 = new char[3];
    for (int i = 0; i < 2; i++) {
        cin >> *(str1 + i);
    }
    str1[2] = '\0';


    FTTS<Word> *table = new FTTS<Word>(2);
    table->AddWord(str, 9);
    table->AddWord(str, 4);
    table->AddWord(str1, 5);

    ArraySequence<int> *occurrence = table->Get(str);
    cout << "length " << occurrence->GetLength() << endl;
    for (int i = 0; i < occurrence->GetLength(); i++) {
        cout << occurrence->Get(i) << ' ';
    }
    cout << endl;

    ArraySequence<int> *occurrence1 = table->Get(str1);
    cout << "length " << occurrence1->GetLength() << endl;
    for (int i = 0; i < occurrence1->GetLength(); i++) {
        cout << occurrence1->Get(i) << ' ';
    }
    cout << endl;

    delete occurrence;
    delete occurrence1;
    delete[] str;
    delete[] str1;
    delete table;
    return 0;
}


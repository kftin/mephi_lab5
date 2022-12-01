#include <iostream>
#include <string>
#include "LL/f_lab2_linkedlist.h"
#include "DA/f_lab2_dynamicarray.h"
#include "Sequence/f_lab2_sequence.h"
#include "LL/f_lab2_linkedlistsequence.h"
#include "DA/f_lab2_arraysequence.h"
#include "ftts.h"

using namespace std;


int CountW(string str) {
    int count = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        //cout << i << endl;
        while (str[i] == ' ' && str[i] != '\0') {
            i++;
            //cout << i << endl;
        }
        count++;
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
            //cout << i << endl;
        }
        //cout << "for" << endl;
    }
    return count;
}

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
//////////////////////////////////////////////////////////////////////////////////
/*
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
*/
////////////////////////////////////////////////////////////////////////////////

    string str1;
    //cin >> str;
    //cout << endl;
    //cout << str << endl;

    FTTS<Word> *table = new FTTS<Word>(4);

    cout << "Enter the text, unfortunate person without Windows:" << endl << '\t';
    getline(cin, str1);
    string str(str1);
    //cout << str1 << endl;
    cout << "How many words per page will we write?" << endl << '\t';
    int N;//количество слов на странице
    cin >> N;


    for (int i = 0; i < (int)str.size(); i++) {
        while (str[i] == ' ' && str[i] != '\0') {
            i++;
        }
        if (str[i] == '\0') {
            break;
        }
        int j = i;
        while (str[j + 1] != ' ' && str[j + 1] != '\0') {
            j++;
        }
        string tmp(str1, i, j - i + 1);

        string end_word(str1, 0, j + 1);
        int current_number_word = CountW(end_word);
        //cout << "our word №: " << current_number_word << endl;
        int occurr = 0;
        if (current_number_word <= (N / 2)) {
            occurr = 1;
        } else if ((current_number_word - (N / 2)) % N == 0) {
            occurr = (current_number_word - (N / 2)) / N + 1;
        } else {
            occurr = (current_number_word - (N / 2)) / N + 2;
        }

        //cout << "occurr" << occurr << endl;

        table->AddWord((char *)tmp.c_str(), occurr);
        cout << "word add " << tmp << endl; 
        i = j + 1;
    }
    
    string res;
    cout << "Enter the word whose occurrences you want to get: " << endl << "\t";
    cin >> res;
    ArraySequence<int> *occurrence = table->Get((char *)res.c_str());
    cout << "length " << occurrence->GetLength() << endl;
    for (int i = 0; i < occurrence->GetLength(); i++) {
        cout << occurrence->Get(i) << ' ';
    }
    cout << endl;

    delete occurrence;
    delete table;
    return 0;
}

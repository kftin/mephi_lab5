#include <iostream>
#include <fstream>
#include <string>
#include "LL/f_lab2_linkedlist.h"
#include "DA/f_lab2_dynamicarray.h"
#include "Sequence/f_lab2_sequence.h"
#include "LL/f_lab2_linkedlistsequence.h"
#include "DA/f_lab2_arraysequence.h"
#include "ftts.h"

using namespace std;

string RemoveExtraSeparators(string str) {
    string tmp(str);
    if (tmp[0] == ' '|| tmp[0] == '\t') {
        int i = 0;
        while (tmp[i] == ' ' || tmp[i] == '\t') {
            tmp.erase(i, 1);
        }
    }
    int i = 0;
    while (i < (int)tmp.size()) {
        if (tmp[i] == '\t' || tmp[i] == ' ') {
            tmp[i] = ' ';
            while (tmp[i + 1] == ' ' || tmp[i + 1] == '\t') {
                tmp.erase(i + 1, 1);
            }
        }
        i++;
    }
    if (str[(int)str.size() - 1] == ' ') {
        str.erase(str.size() - 1, 1);
    }
    return tmp;
}

int main() {

    FTTS<Word> *table = new FTTS<Word>(37);
    int N;
    cout <<"How many words per page will we write?" << endl << '\t';
    cin >> N;
    string line;
    ifstream in("input.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int q = 1;
        while (getline(in, line))
        {
            line = RemoveExtraSeparators(line);
            for (int i = 0; i < (int)line.size(); i++) {
                int j = i;
                while (line[i] != ' ' && i < (int)line.size()) {
                    i++;
                }
                string tmp(line, j, i - j);
                char *str = (char *)tmp.c_str();
                int occurr = 0;
                if (q <= N / 2) {
                    occurr = 1;
                } else {
                    occurr = 2;
                    int k = N / 2 + 1;
                    while (k + N <= q) {
                        if (k % 10 != 0) {
                            occurr++;
                            k += N;
                        } else {
                            occurr++;
                            k += (3 * N) / 4;
                        }
                    }
                }
                table->AddWord(str, occurr);
                q++;
            }
        }
    }
    in.close();

    string res;
    while (true) {
        cout << "Enter the word whose occurrences you want to get: " << endl << "\t";
        cin >> res;
        if (res[0] == '~') {
            break;
        }
        ArraySequence<int> *occurrence = table->Get((char *)res.c_str());
        cout << "length " << occurrence->GetLength() << endl;
        for (int i = 0; i < occurrence->GetLength(); i++) {
            cout << occurrence->Get(i) << ' ';
        }
        cout << endl;
        delete occurrence;
    }

    Sequence<Word> *sorted = table->GetDictionary();
    for (int y = 0; y < sorted->GetLength(); y++) {
        char *str = sorted->GetRef(y).GetWord();
        ArraySequence<int> *strOccurr = sorted->GetRef(y).GetOccurrence(); 
        for (int i = 0; i < sorted->GetRef(y).GetLength(); i++) {
            cout << *(str + i);
        }
        cout << "   ";
        for (int i = 0; i < sorted->GetRef(y).GetNumber(); i++) {
            cout << strOccurr->Get(i) << ' ';
        }
        cout << endl;
    }

    delete sorted;
    delete table;
    return 0;
}

#include <iostream>
#include <string>
#include "LL/f_lab2_linkedlist.h"
#include "DA/f_lab2_dynamicarray.h"
#include "Sequence/f_lab2_sequence.h"
#include "LL/f_lab2_linkedlistsequence.h"
#include "DA/f_lab2_arraysequence.h"

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

    ArraySequence<LinkedListSequence<int>> *table = new ArraySequence<LinkedListSequence<int>>(3);
    (table->GetRef(0)).Append(3);
    cout << (table->GetRef(0)).GetRef(0) << endl;
    delete table;
}

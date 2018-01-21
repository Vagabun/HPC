#include "text_func.h"

int main() {
    ifstream in("input.txt");
    while (true) {
        word w = word(); // constructor
        if (in.eof())
            break;
        in >> w.buffer;
        get_size(w);
        revert(w);
        if (if_number(w)) {
            get_sequence(w);
            if (palindrome(w))
                cout << get_max(w) << " ";
            else if (grows_evenly(w))
                cout << get_mid(w) << " ";
            else
                cout << w.buffer << " ";
        }
        else {
            if (palindrome(w))
                cout << get_max(w, false) << " ";
            else if (grows_evenly(w, false))
                cout << get_mid(w, false) << " ";
            else
                cout << w.buffer << " ";
        }
    }
    in.close();
    return 0;
}
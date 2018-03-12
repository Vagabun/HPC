#include "text_func.h"

int main() {
    ifstream in("input.txt");
    char buffer[100];
    int data_i[100];
    while (true) {
        if (in.eof())
            break;
        in >> buffer;
        get_size(buffer);
        get_sequence(buffer, data_i);
        if (palindrome(buffer)) {
            if (if_number(buffer))
                cout << get_max(data_i) << " ";
            else
                cout << get_max(buffer) << " ";
        }
        else if (grows_evenly(data_i) || grows_evenly(buffer)) {
            if (if_number(buffer))
                cout << get_mid(data_i) << " ";
            else
                cout << get_mid(buffer) << " ";
        }
        else
            cout << buffer << " ";
    }
    in.close();
    return 0;
}
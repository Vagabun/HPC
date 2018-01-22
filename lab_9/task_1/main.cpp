#include "text_func.h"

int main() {
    ifstream in("input.txt");
    char buffer[100], w_c_data[100];
    int w_i_data[100];
    while (true) {
        if (in.eof())
            break;
        in >> buffer;
        get_size(buffer);
        if (if_number(buffer)) {
            get_sequence(buffer, w_i_data);
            if (palindrome(buffer))
                cout << get_max(w_i_data) << " ";
            else if (grows_evenly(w_i_data))
                cout << get_mid(w_i_data) << " ";
            else
                cout << buffer << " ";
        }
        else {
            strcpy(w_c_data, buffer);
            if (palindrome(buffer))
                cout << get_max(w_c_data) << " ";
            else if (grows_evenly(w_c_data))
                cout << get_mid(w_c_data) << " ";
            else
                cout << buffer << " ";
        }
    }
    in.close();
    return 0;
}
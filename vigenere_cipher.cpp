// polyalphabetic or vigenere substitution cipher

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // User input
    char pt[100];
    char key[10];

    cin.getline(pt, 100);
    cin.getline(key, 10);

    // Encryption
    int pt_len = strlen(pt);
    int key_len = strlen(key);

    char ct[100];

    for (int i = 0, j = 0; i < pt_len; ++i) {
        ct[i] = 'a' + (pt[i] - 'a' + (key[j] - 'a')) % 26;
        j = (j + 1) % key_len;
    }

    int ct_len = strlen(ct);

    for (int i = 0; i < ct_len; ++i) {
        cout << ct[i];
    }

    cout << endl;

    // Decryption
    char dt[100];

    for (int i = 0, j = 0; i < ct_len; ++i) {
        dt[i] = 'a' + (ct[i] - 'a' - (key[j] - 'a') + 26) % 26;
        j = (j + 1) % key_len;
    }

    int dt_len = strlen(dt);

    for (int i = 0; i < dt_len; ++i) {
        cout << dt[i];
    }

    cout << endl;

    return 0;
}

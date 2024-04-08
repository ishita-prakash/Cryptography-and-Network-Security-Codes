#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, p, q, e;
    
    cin >> m >> p >> q >> e;
    
    int n = p * q;
    
    int phi = (p - 1) * (q - 1);
    
    int d = 1;
    while(1){
        if((d * e) % phi == 1){
            break;
        }
        d++;
    }
    
    int ct = (int)(pow(m, e)) % n;
    int pt = (int)(pow(ct, d)) % n;
    
    cout << "Cipher text is " << ct << endl;
    cout << "Plain Text is " << pt;
    
    return 0;
}

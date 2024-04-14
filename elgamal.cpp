#include <bits/stdc++.h>

using namespace std;

int main(){
    int q, r, m, a, b;
    
    //user input
    cin >> q >> r >> m >> a >> b;
    
    int public_a, public_b, ct, pt;
    
    //public key of Alice
    public_a = (int)(pow(r, a)) % q;
    
    //public key of Bob
    public_b = (int)(pow(r, b)) % q;
    
    //encryption
    ct = m * (int)(pow(public_a, b)) % q;
    
    //decryption
    int x = 1;
    while(1){
        if(public_b * x % q == 1){
            break;
        }
        x++;
    }
    
    pt = ct * (int)(pow(x, a)) % q;
    
    cout << "Public key of Alice:" << public_a << endl;
    cout << "Public key of Bob: " << public_b << endl;
    cout << "Cipher text is " << ct << endl;
    cout << "Plain Text is " << pt << endl;
    
    return 0;
}

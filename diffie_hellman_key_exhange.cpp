#include <bits/stdc++.h>

using namespace std;

int main(){
    /* q->prime no., r->primitive root of q
    a->private key of Alice, b->private key of Bob */
    int q, r, a, b;
    
    //user input
    cin >> q >> r >> a >> b;
    
    /* public_a->public key of Alice, public_b->public key of Bob
    secret_a->secret key calculated by Alice
    secret_b->secret key calculated by Bob */
    int public_a, public_b, secret_a, secret_b;
    
    //calculating public key of Alice
    public_a = (int)(pow(r, a)) % q;
    
    //calculating public key of Bob
    public_b = (int)(pow(r, b)) % q;
    
    //secret key calculated by Alice
    secret_a = (int)(pow(public_b, a)) % q;
    
    //secret key calculated by Bob
    secret_b = (int)(pow(public_a, b)) % q;
    
    cout << "Public key of Alice:" << public_a << endl;
    cout << "Public key of Bob:" << public_b << endl;
    cout << "Secret key calculated by Alice:" << secret_a << endl;
    cout << "Secret key calculated by Bob:" << secret_b << endl;
    
    return 0;
}

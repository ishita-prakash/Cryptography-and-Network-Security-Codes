#include <bits/stdc++.h>

using namespace std;

string DecimalToBinary(int num) 
{ 
    string res;
    
    if (num == 0)
        return "0";
    
    while (num > 0) {
        char bit = (num % 2) + '0';
        res = bit + res;
        num /= 2;
    }
    
    return res;
} 

int fast_mod_expo(int b, int p, int m){
    
    //power in binary
    string p_bin = DecimalToBinary(p);
    
    int tmp = b;
    
    //i = 1 calculation
    if(p_bin[1] == '0'){
        tmp = (b * b) % m;
    }
    else if(p_bin[1] == '1'){
        tmp = (b * b) % m;
        tmp = (tmp * b) % m;
    }
    
    for(int i=2; i<(int)(p_bin.size()); i++){
        if(p_bin[i] == '0'){
            tmp = (tmp * tmp) % m;
        }
        
        else if(p_bin[i] == '1'){
            tmp = (tmp * tmp) % m;
            tmp = (tmp * b) % m;
        }
    }
    
    return tmp;
    
}

int main(){
    int p, q, hm, h, x, k;
    
    cin >> p >> q >> hm >> h >> x >> k;
    
    int g = fast_mod_expo(h, (p-1)/q, p);
    
    int y = fast_mod_expo(g, x, p);
    
    int r = fast_mod_expo(g, k, p) % q;
    
    int k_inv = 1;
    
    while(1){
        if(k_inv * k % q == 1){
            break;
        }
        else{
            k_inv++;
        }
    }
    
    int s = k_inv * (hm + x * r) % q;
    
    int s_inv = 1;
    
    while(1){
        if(s_inv * s % q == 1){
            break;
        }
        else{
            s_inv++;
        }
    }
    
    int w = s_inv % q;
    
    int u1 = hm * w % q;
    
    int u2 = r * w % q;
    
    int v = ( fast_mod_expo(g, u1, p) * fast_mod_expo(y, u2, p) % p ) % q;
    
    cout << "r=" << r << endl;
    cout << "s=" << s << endl;
    
    cout << "w=" << w << endl;
    cout << "u1=" << u1 << endl;
    cout << "u2=" << u2 << endl;
    cout << "v=" << v << endl;
    
    
    return 0;
}

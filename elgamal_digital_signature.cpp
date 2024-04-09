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
    int q, alpha, xa, k, hash;
    
    cin >> q >> alpha >> xa >> k >> hash;
    
    int s1 = fast_mod_expo(alpha, k, q);
    
    int k_inv = 1;
    
    while(1){
        if(k_inv * k % (q - 1) == 1){
            break;
        }
        else{
            k_inv++;
        }
    }
    
    int s2 = k_inv * (hash - xa * s1) % (q - 1);
    
    if(s2 < 0){
        s2 = (q - 1) - (abs(s2) % (q - 1));
    }
    
    int ya = fast_mod_expo(alpha, xa, q);
    
    int v1 = fast_mod_expo(alpha, hash, q);
  


  int v2 = fast_mod_expo(ya, s1, q) * fast_mod_expo(s1, s2, q) % q;
    
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    
    cout << "v1=" << v1 << endl;
    cout << "v2=" << v2 << endl;
    
    return 0;
}

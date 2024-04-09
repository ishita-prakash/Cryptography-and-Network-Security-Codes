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
    int p, q, e, w;
    
    cin >> p >> q >> e >> w;
    
    int n = p * q;

    
    int phi = (p - 1) * (q - 1);
    
    int d = 1;
    while(1){
        if( (d * e) % phi == 1 ){
            break;
        }
        d++;
    }
    
    //int s = (int)pow(w, d) % n;
    int s = fast_mod_expo(w, d, n);
    
    //int w2 = (int)pow(s, e) % n;
    int w2 = fast_mod_expo(s, e, n);
    
    cout << "s=" << s << endl;
    cout << "w calculated from s =" << w2;
    
    return 0;
}

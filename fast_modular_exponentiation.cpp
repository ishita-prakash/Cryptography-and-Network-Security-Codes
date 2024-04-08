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

int main(){
    int b=0, p=0, m=0;
    
    //user input
    cin >> b >> p >> m;
    
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
    
    cout << tmp;
    
    return 0;
}

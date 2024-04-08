#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, m;
    
    cin >> a >> m;
    
    //q->quotient, r->remainder
    int q, r, x1, x2, x, y1, y2, y;
    
    x1 = 1;
    x2 = 0;
    y1 = 0;
    y2 = 1;
    
    //continue the process till m becomes 0
    while(m != 0){
        q = a / m;
        r = a % m;
        x = x1 - q*x2;
        y = y1 - q*y2;
        
        a = m;
        m = r;
        x1 = x2;
        x2 = x;
        y1 = y2;
        y2 = y;
    }
    
    //print the modular multiplicative inverse
    cout << x1;
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int p, a, b, x, y;
    
    cin >> p >> a >> b >> x >> y;
    
    int z = 1;
    while(1){
        if(2*y*z % p == 1){
            break;
        }
        else{
            z++;
        }
    }
    
    int lambda = ( ((3 * (int)pow(x, 2)) + a ) * z) % p;
    
    int x3 = ( (int)pow(lambda, 2) - x- x) % p;
    
    if(x3 < 0){
        x3 = p - (abs(x3) % p) % p;
    }
    
    int y3 = ( lambda * (x - x3) - y ) % p;
    
    if(y3 < 0){
        y3 = p - (abs(y3) % p) % p;
    }

    cout << x3 << " " << y3;
    
    return 0;
}

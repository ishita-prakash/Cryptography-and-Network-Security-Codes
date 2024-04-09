#include <bits/stdc++.h>

using namespace std;

int main(){
    int p, a, b, x1, y1, x2, y2;
    
    cin >> p >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    int z = 1;
    while(1){
        if((x2 - x1) * z % p == 1){
            break;
        }
        else{
            z++;
        }
    }
    
    int lambda = ( (y2 - y1) * z ) % p;
    
    int x3 = ( (int)pow(lambda, 2) - x1 - x2 ) % p;
    
    if(x3 < 0){
        x3 = p - (abs(x3) % p) % p;
    }
    
    int y3 = ( lambda * (x1 - x3) - y1 ) % p;
    
    if(y3 < 0){
        y3 = p - (abs(y3) % p) % p;
    }
    
    cout << x3 << " " << y3;
    
    return 0;
}

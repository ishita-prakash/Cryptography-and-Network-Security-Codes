#include <bits/stdc++.h>

using namespace std;

int main(){
    int a1, a2, a3, k1, k2, k3;
    
    cin >> a1 >> k1 >> a2 >> k2 >> a3 >> k3;
    
    int d = k1 * k2 * k3;
    
    int m1 = d / k1;
    int m2 = d / k2;
    int m3 = d / k3;
    
    int y1 = 1, y2 = 1, y3 = 1;
    
    while(true){
        if((m1*y1) % k1 == 1){
            break;
        }
        else{
            y1++;
        }
    }
    
    while(true){
        if((m2*y2) % k2 == 1){
            break;
        }
        else{
            y2++;
        }
    }
    
    while(true){
        if((m3*y3) % k3 == 1){
            break;
        }
        else{
            y3++;
        }
    }
    
    int x = ((a1*m1*y1) + (a2*m2*y2) + (a3*m3*y3)) % d;
    
    cout<<x;
    
    return 0;
}

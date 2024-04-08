#include <bits/stdc++.h>

using namespace std;

int main(){
    string key_input;
    cin>>key_input;
    
    vector<int> key(10);
    
    for(int i=0; i<10; i++){
        key[i] = key_input[i] - 48; // or key_input[i] - '0'
    }
    
    vector<int> temp(10);
    
    //P10 in temp
    temp[0] = key[2];
    temp[1] = key[4];
    temp[2] = key[1];
    temp[3] = key[6];
    temp[4] = key[3];
    temp[5] = key[9];
    temp[6] = key[0];
    temp[7] = key[8];
    temp[8] = key[7];
    temp[9] = key[5];
    
    vector<int> left(5), right(5);
    
    //divide temp into left and right
    for(int i=0; i<5; i++){
        left[i] = temp[i];
    }
    
    for(int i=5; i<10; i++){
        right[i-5] = temp[i];
    }
    
    //1-bit left shift
    left.push_back(left[0]);
    left.erase(left.begin());
    
    right.push_back(right[0]);
    right.erase(right.begin());
    
    //combine left and right in temp1
    vector<int> temp1(10);
    
    for(int i=0; i<5; i++){
        temp1[i] = left[i];
    }
    
    for(int i=5; i<10; i++){
        temp1[i] = right[i-5];
    }
    
    //P8
    vector<int> key1(8);
    
    key1[0] = temp1[5];
    key1[1] = temp1[2];
    key1[2] = temp1[6];
    key1[3] = temp1[3];
    key1[4] = temp1[7];
    key1[5] = temp1[4];
    key1[6] = temp1[9];
    key1[7] = temp1[8];
    
    //key1
    for(int x: key1){
        cout<<x;
    }
    
    cout<<endl;
    
    //key2 generation process
    
    //2-bit left shift
    left.push_back(left[0]);
    left.erase(left.begin());
    left.push_back(left[0]);
    left.erase(left.begin());
    
    right.push_back(right[0]);
    right.erase(right.begin());
    right.push_back(right[0]);
    right.erase(right.begin());
    
    //combine left and right in temp2
    vector<int> temp2(10);
       
    for(int i=0; i<5; i++){
        temp2[i] = left[i];
    }

    for(int i=5; i<10; i++){
        temp2[i] = right[i-5];
    }
    
    //P8
    vector<int> key2(8);
    key2[0] = temp2[5];
    key2[1] = temp2[2];
    key2[2] = temp2[6];
    key2[3] = temp2[3];
    key2[4] = temp2[7];
    key2[5] = temp2[4];
    key2[6] = temp2[9];
    key2[7] = temp2[8];
    
    //key2
    for(int x: key2){
        cout<<x;
    }
    
    return 0;
}

//SDES

#include <bits/stdc++.h>

using namespace std;

//P10 function
vector<int> P10(vector<int> key){
    vector<int> res(10);

    res[0] = key[2];
    res[1] = key[4];
    res[2] = key[1];
    res[3] = key[6];
    res[4] = key[3];
    res[5] = key[9];
    res[6] = key[0];
    res[7] = key[8];
    res[8] = key[7];
    res[9] = key[5];
    
    return res;
}

//P8 function
vector<int> P8(vector<int> key){
    vector<int> res(8);
    
    res[0] = key[5];
    res[1] = key[2];
    res[2] = key[6];
    res[3] = key[3];
    res[4] = key[7];
    res[5] = key[4];
    res[6] = key[9];
    res[7] = key[8];
    
    return res;
}

//Circular Left Shift function
vector<int> left_shift(vector<int> res){
    
    res.push_back(res[0]);
    res.erase(res.begin());
    
    return res;
}

int main(){
    //user input
    string key_input;
    getline(cin, key_input);
    
    //mapping user input from string to vector<int>
    vector<int> key(10);

    for(int i=0; i<10; i++){
        key[i] = key_input[i] - '0';
    }
    
    //P10
    vector<int> temp(10);
    temp = P10(key);
    
    //--------key1 generation--------
    
    //left and right
    vector<int> left(5), right(5);

    for(int i=0; i<5; i++){
        left[i] = temp[i];
        right[i] = temp[i+5];
    }
    
    //1-bit CLS
    left = left_shift(left);
    right = left_shift(right);
    
    //combine in temp
    for(int i=0; i<5; i++){
        temp[i] = left[i];
        temp[i+5] = right[i];
    }
    
    //P8
    vector<int> key1(8);
    key1 = P8(temp);
    
    //key1 output
    for(int x : key1){
        cout << x;
    }
    
    cout << endl;
    
    //--------key2 generation--------
    
    //2-bit CLS
    left = left_shift(left);
    left = left_shift(left);
    
    right = left_shift(right);
    right = left_shift(right);
    
    //combine in temp
    for(int i=0; i<5; i++){
        temp[i] = left[i];
        temp[i+5] = right[i];
    }
    
    //P8
    vector<int> key2(8);
    key2 = P8(temp);
    
    //key2 output
    for(int x : key2){
        cout << x;
    }
    
    cout << endl;
    
    return 0;
}

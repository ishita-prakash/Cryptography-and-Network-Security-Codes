//AES to find third round key, given second round key
//works for a particular input
//took references from other code

//aes

#include <bits/stdc++.h>

using namespace std;

map<int, int> s_box = {{0x3A, 0x80},{0xF7, 0x68},{0xFA, 0x2D},{0xA0, 0xE0}};

vector<vector<int>> third_round_key(vector<vector<int>> second_round_key){
    vector<int> temp;
    
    vector<vector<int>> res(4, vector<int>(4,0));
    
    for(int i=0; i<4; i++){
        temp.push_back(second_round_key[i][3]);
    }
    
    //rotword
    temp.push_back(temp[0]);
    temp.erase(temp.begin());
    
    //subword
    for(int i=0; i<4; i++){
        temp[i] = s_box[temp[i]];
    }
    
    //subword xor rc
    temp[0] ^= 0x04;
    
    //w12
    for(int i=0; i<4; i++){
        res[i][0] = temp[i] ^ second_round_key[i][0];
    }
    
    //w12
    for(int i=0; i<4; i++){
        res[i][1] = res[i][0] ^ second_round_key[i][1];
    }
    
    //w12
    for(int i=0; i<4; i++){
        res[i][2] = res[i][1] ^ second_round_key[i][2];
    }
    
    //w12
    for(int i=0; i<4; i++){
        res[i][3] = res[i][2] ^ second_round_key[i][3];
    }
    
    return res;
}

int main(){
    
    vector<vector<int>> second_round_key(4, vector<int>(4,0));
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> hex >> second_round_key[i][j];
        }
    }
    
    vector<vector<int>> res(4, vector<int>(4,0));
    
    res = third_round_key(second_round_key);
    
    cout << setfill('0');
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << "0x" << uppercase << setw(2) << hex << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
    
}

//AES to find third round key, given second round key
//works for a particular input
//took references from other code

#include <bits/stdc++.h>

using namespace std;

//S-Box values
map<int, int> s_box = {{0x3A, 0x80}, {0xF7, 0x68}, {0xFA, 0x2D}, {0xA0, 0xE0}};

//Key function
vector<vector<int>> third_round_key(vector<vector<int>> second_round_key){
    
    //rotword
    vector<int> temp = {second_round_key[1][3], second_round_key[2][3], second_round_key[3][3], second_round_key[0][3]};
    
    int a = temp.size();
    
    //subword
    for(int i=0; i<a; i++){
        temp[i] = s_box[temp[i]];
    }
    
    //subword XOR third round constant
    temp[0] = temp[0] ^ 0x04;
    
    //finding the required keys
    vector<vector<int>> res(4, vector<int>(4, 0));
    
    //w12 - first column
    for(int i=0; i<a; i++){
        res[i][0] = temp[i] ^ second_round_key[i][0];
    }
    
    //w13 - second column
    for(int i=0; i<a; i++){
        res[i][1] = res[i][0] ^ second_round_key[i][1];
    }
    
    //w14 - third column
    for(int i=0; i<a; i++){
        res[i][2] = res[i][1] ^ second_round_key[i][2];
    }
    
    //w15 - fourth column
    for(int i=0; i<a; i++){
        res[i][3] = res[i][2] ^ second_round_key[i][3];
    }
    
    return res;
}

int main()
{
    vector<vector<int>> second_round_key(4, vector<int>(4, 0));
    
    //user input
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> hex >> second_round_key[i][j];
        }
    }
    
    vector<vector<int>> res = third_round_key(second_round_key);
    
    cout << setfill('0');
    
    //Output
    for(size_t i=0; i<4; i++){
        const auto& row = res[i];
        for(size_t j=0; j<4; j++){
            const auto& e = row[j];
            
            cout << "0x" << uppercase << setw(2) << hex << e << " ";
        }
        cout << endl;
    }

    return 0;
}

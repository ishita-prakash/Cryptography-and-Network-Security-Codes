#include <bits/stdc++.h>

using namespace std;

//IP function
vector<int> initialPermutation(vector<int> input) {
    vector<int> temp(8);

    temp[0] = input[1];
    temp[1] = input[5];
    temp[2] = input[2];
    temp[3] = input[0];
    temp[4] = input[3];
    temp[5] = input[7];
    temp[6] = input[4];
    temp[7] = input[6];

    return temp;
}

//Inverse IP function
vector<int> inverseInitialPermutation(vector<int> input) {
    vector<int> output(8);

    output[0] = input[3];
    output[1] = input[0];
    output[2] = input[2];
    output[3] = input[4];
    output[4] = input[6];
    output[5] = input[1];
    output[6] = input[7];
    output[7] = input[5];

    return output;
}

//EP function
vector<int> EP(vector<int> arr){
    vector<int> res(8);
    
    res[0] = arr[3];
    res[1] = arr[0];
    res[2] = arr[1];
    res[3] = arr[2];
    res[4] = arr[1];
    res[5] = arr[2];
    res[6] = arr[3];
    res[7] = arr[0];
    
    return res;
}

//Decimal to Binary function
string decimalToBinary(int num){
    //string str;
    
    if(num == 0){
        return "00";
    }
    else if(num == 1){
        return "01";
    }
    else if(num == 2){
        return "10";
    }
    else if(num == 3){
        return "11";
    }
    
    return "00";
}

//XOR function
vector<int> XOR(vector<int> arr1, vector<int> arr2){
    vector<int> res(8);
    
    for(int i=0; i<8; i++){
        res[i] = arr1[i] ^ arr2[i];
    }
    
    return res;
}

int main(){
    //user input
    string input_pt, input_key1, input_key2;
    cin >> input_pt >> input_key1 >> input_key2;
    
    vector<int> pt(8), key1(8), key2(8);
    
    for(int i=0; i<8; i++){
        pt[i] = input_pt[i] - 48;
    }
    
    for(int i=0; i<8; i++){
        key1[i] = input_key1[i] - 48;
    }
    
    for(int i=0; i<8; i++){
        key2[i] = input_key2[i] - 48;
    }
    
    //IP in temp
    vector<int> temp = initialPermutation(pt);
    
    //divide into left and right
    vector<int> left(8), right(8);
    
    for(int i=0; i<4; i++){
        left[i] = temp[i];
    }

    for(int i=4; i<8; i++){
        right[i-4] = temp[i];
    }
    
    //EP on right half
    vector<int> ep_temp = EP(right);
    
    //XOR key2 and EP
    vector<int> xor_temp = XOR(key2, ep_temp);
   
    //divide XOR output into left and right
    vector<int> xor_left(4), xor_right(4);
    
    for(int i=0; i<4; i++){
        xor_left[i] = xor_temp[i];
    }

    for(int i=4; i<8; i++){
        xor_right[i-4] = xor_temp[i];
    }
    
    //S0 and S1 initialization
    int S0[4][4] = {
                                {1, 0, 3, 2},
                                {3, 2, 1, 0},
                                {0, 2, 1, 3},
                                {3, 1, 3, 2}
                             };
    
    int S1[4][4] = {
                                {0, 1, 2, 3},
                                {2, 0, 1, 3},
                                {3, 0, 1, 0},
                                {2, 1, 0, 3}
                             };
    
    
    //left's row and col idx (for S0)
    string l_row, l_col;
    l_row = to_string(xor_left[0]) + to_string(xor_left[3]);
    l_col = to_string(xor_left[1]) + to_string(xor_left[2]);
  
    //binary to decimal
    int l_row_idx = stoi(l_row, 0, 2);
    int l_col_idx = stoi(l_col, 0, 2);
    
    //right's row and col idx (for S1)
    string r_row, r_col;
    r_row = to_string(xor_right[0]) + to_string(xor_right[3]);
    r_col = to_string(xor_right[1]) + to_string(xor_right[2]);
    
    
    //binary to decimal
    int r_row_idx = stoi(r_row, 0, 2);
    int r_col_idx = stoi(r_col, 0, 2);
    
    //S0's index
    int temp_S0 = S0[l_row_idx][l_col_idx];
    
    //decimal to binary
    string str_S0 = decimalToBinary(temp_S0);
    
    //S1's index
    int temp_S1 = S1[r_row_idx][r_col_idx];
    
    //decimal to binary
    string str_S1 = decimalToBinary(temp_S1);
    
    //combine S0 and S1
    vector<int> S0S1;
    
    for(int i=0; i<2; i++){
        S0S1.push_back(str_S0[i] - '0');
    }
    
    for(int i=0; i<2; i++){
        S0S1.push_back(str_S1[i] - '0');
    }
    
    //P4
    vector<int> p4_S0S1(4);
    
    p4_S0S1[0] = S0S1[1];
    p4_S0S1[1] = S0S1[3];
    p4_S0S1[2] = S0S1[2];
    p4_S0S1[3] = S0S1[0];
    
    //XOR P4 and left of IP 
    
    vector<int> xor_p4left = XOR(p4_S0S1, left);
    
    //combine output of above XOR and right of IP
    vector<int> xor_n_right(8);
    
    for(int i=0; i<4; i++){
        xor_n_right[i] = xor_p4left[i];
    }
    for(int i=4; i<8; i++){
        xor_n_right[i] = right[i - 4];
    }
    
    //swap left and right halves
    int swap_int;
    
    for(int i=0; i<4; i++){
        swap_int = xor_n_right[i];
        xor_n_right[i] = xor_n_right[i+4];
        xor_n_right[i+4] = swap_int;
    }

    ///////////////////////////////////////////////////
    //Round 2
    ///////////////////////////////////////////////////
    
    //EP on right half of round 1 output
    
    vector<int> r_xor_n_right(4);
    
    for(int i=4; i<8; i++){
        r_xor_n_right[i-4] = xor_n_right[i];
    }
    
    ep_temp = EP(r_xor_n_right);
    
    //XOR key1 and EP
    //vector<int> xor_temp(8);
    xor_temp = XOR(key1, ep_temp);
    
    //divide XOR output into left and right
    
    for(int i=0; i<4; i++){
        xor_left[i] = xor_temp[i];
    }

    for(int i=4; i<8; i++){
        xor_right[i-4] = xor_temp[i];
    }
    
    //left's row and col idx (for S0)
    l_row = to_string(xor_left[0]) + to_string(xor_left[3]);
    l_col = to_string(xor_left[1]) + to_string(xor_left[2]);
    
    //binary to decimal
    l_row_idx = stoi(l_row, 0, 2);
    l_col_idx = stoi(l_col, 0, 2);
    
    //right's row and col idx (for S1)
    r_row = to_string(xor_right[0]) + to_string(xor_right[3]);
    r_col = to_string(xor_right[1]) + to_string(xor_right[2]);
    
    //binary to decimal
    r_row_idx = stoi(r_row, 0, 2);
    r_col_idx = stoi(r_col, 0, 2);
    
    //S0's index
    temp_S0 = S0[l_row_idx][l_col_idx];
    
    //decimal to binary
    str_S0 = decimalToBinary(temp_S0);
    
    //S1's index
    temp_S1 = S1[r_row_idx][r_col_idx];
    
    //decimal to binary
    str_S1 = decimalToBinary(temp_S1);
    
    //combine S0 and S1
    S0S1.clear();
    for(int i=0; i<2; i++){
        S0S1.push_back(str_S0[i] - '0');
    }
    
    for(int i=0; i<2; i++){
        S0S1.push_back(str_S1[i] - '0');
    }
    
    //P4
    p4_S0S1[0] = S0S1[1];
    p4_S0S1[1] = S0S1[3];
    p4_S0S1[2] = S0S1[2];
    p4_S0S1[3] = S0S1[0];
    
    vector<int> l_xor_n_right(4);
    
    for(int i=0; i<4; i++){
        l_xor_n_right[i] = xor_n_right[i];
    }
    
    //XOR P4 and left of Round 1 output
    xor_p4left = XOR(p4_S0S1, l_xor_n_right);
    
    //combine output of above XOR and right of Round 1 output
    vector<int> r2_xor_n_right(8);
    
    for(int i=0; i<4; i++){
        r2_xor_n_right[i] = xor_p4left[i];
    }
    for(int i=4; i<8; i++){
        r2_xor_n_right[i] = r_xor_n_right[i-4];
    }
    
    //Inverse IP
    vector<int> ct = inverseInitialPermutation(r2_xor_n_right);
    
    for(int i=0; i<8; i++){
        cout<<ct[i];
    }
    
    return 0;
}

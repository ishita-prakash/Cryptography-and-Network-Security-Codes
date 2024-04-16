// hill cipher

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string pt;
    cin >> pt;
    
    int pt_matrix[3];
    
    for(int i=0; i<3; i++){
        pt_matrix[i] = (pt[i] - 65) % 26;
    }
    
    for(int i=0; i<3; i++){
        cout << pt_matrix[i] << " ";
    }
    
    cout<<endl;
    
    int encrypt_key[3][3];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> encrypt_key[i][j];
        }
    }
    
    int decrypt_key[3][3];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> decrypt_key[i][j];
        }
    }
    
    // encryption
    int sum1[3];
    int sum;
    
    for(int i=0; i<3; i++){
        sum = 0;
        for(int j=0; j<3; j++){
            sum += (encrypt_key[i][j] * pt_matrix[j]);
        }
        sum1[i] = sum % 26;
    }
    
    for(int i=0; i<3; i++){
        sum1[i] += 65;
        cout << (char)sum1[i];
    }
    
    cout<<endl;
    
    int ct_matrix[3];
    
    for(int i=0; i<3; i++){
        ct_matrix[i] = sum1[i] - 65;
    }
    
    // decryption
    int sum2[3];
    for(int i=0; i<3; i++){
        sum = 0;
        for(int j=0; j<3; j++){
            sum += (decrypt_key[i][j] * ct_matrix[j]);
        }
        sum2[i] = sum % 26;
    }
    
    for(int i=0; i<3; i++){
        sum2[i] += 65;
        cout << (char)sum2[i];
    }
    
    cout<<endl;
    
    return 0;
}

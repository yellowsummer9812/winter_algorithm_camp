#include <iostream>
#include <string>
using namespace std;

int n, m, i, j, result;
string a[50], b[50];

void toggle(){
    for(int k = i; k < i+3; k++){
        for(int l = j; l < j+3; l++){
            if(a[k][l] == '0'){
                a[k][l] = '1';
            }else{
                a[k][l] = '0';
            }
        }
    }
    result++;
}

bool isSame(){
    for(int k = 0; k < n; k++){
        for(int l = 0; l < m; l++){
            if(a[k][l] != b[k][l]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    for(i = 0; i < n; i++){
        cin>> a[i];
    }
    for(i = 0; i < n; i++){
        cin>> b[i];
    }

    for(i = 0; i < n - 2; i++){
        for(j = 0; j < m - 2; j++){
            if(a[i][j] != b[i][j]){
                toggle();
            }
        }
    }
    if(isSame()){
        cout<< result;
    }else{
        cout<< -1;
    }
    
}
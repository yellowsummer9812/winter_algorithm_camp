#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ans = 99999999;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    cin.ignore();

    vector<string> chess;
    string tmp;
    for(int i = 0; i < n; i++){
        getline(cin, tmp);
        chess.push_back(tmp);
    }

    int c1 = 0; // B가 짝수인 경우
    int c2 = 0; // B가 홀수인 경우
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            c1 = 0;
            c2 = 0;
            for(int k = i; k < i + 8; k++){
                for(int l = j; l < j + 8; l++){
                    if(chess[k][l] == 'B'){
                        if((k + l) % 2 == 0){
                            c2++;
                        }
                        else
                        {
                            c1++;    
                        }
                    }
                    else{
                        if((k + l) % 2 == 0){
                            c1++;
                        }
                        else
                        {
                            c2++;    
                        }
                    }

                }
            }
            ans = min(ans, min(c1, c2));
        }
    }
    cout<< ans;
}
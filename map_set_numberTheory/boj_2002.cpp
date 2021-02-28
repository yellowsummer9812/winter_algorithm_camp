#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
int ans;
int check[10001];
map<string,int> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin.ignore();

    string tmp;
    for(int i = 1; i <= n; i++){
        getline(cin, tmp, '\n');
        mp.insert({tmp, i});
    }

    check[0] = 1;
    for(int i = 1; i <= n; i++){
        getline(cin, tmp, '\n');
        auto iter = mp.find(tmp);
        for(int j = iter -> second - 1;  0 < j; j--){
            if(!check[j]){
                ans++;
                break;
            }
        }
        check[iter -> second] = 1;
    }

    cout<< ans;
}
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
using namespace std;

int n, m;
map<int, string> mp1;
map<string, int> mp2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n>> m;
    cin.ignore();

    string s;
    for(int i = 1; i <= n; i++){
        getline(cin, s, '\n');

        mp1.insert({i, s});
        mp2.insert({s, i});
    }

    for(int i = 1; i <= m; i++){
        getline(cin, s, '\n');

        auto iter1 = mp2.find(s);
        if(iter1 != mp2.end()){
            cout<< iter1 -> second<< '\n';
        }else{
            int a = atoi(s.c_str());
            auto iter2 = mp1.find(a);
            cout<< iter2 -> second<< '\n';
        }
    }
}   
#include <iostream>
#include <map>
#include <string>
using namespace std;

string s;
map<string, double> mp;
int cnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(getline(cin, s)){
        auto iter = mp.find(s);
        if(iter != mp.end()){
            iter -> second++;
        }else{
            mp.insert({s, 1});
        }
        cnt++;
    }

    cout<< fixed;
    cout.precision(4);
    for(auto iter = mp.begin(); iter != mp.end(); iter++){
        cout<< iter -> first<< " "<< (double)(iter -> second / cnt) * 100<< '\n';
    }
}
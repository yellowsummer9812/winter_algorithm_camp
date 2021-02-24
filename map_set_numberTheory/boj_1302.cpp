#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int N;
int m = 0;
map<string, int> book;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> N;
    cin.ignore();

    while(N--){
        string tmp;
        getline(cin, tmp, '\n');
        if(book.find(tmp) == book.end()){
            book.insert({tmp, 1});
        }else{
            book[tmp]++;
        }
        m = max(book[tmp], m);
    }

    for(auto i = book.begin(); i != book.end(); i++){
        if(i->second == m){
            cout<< i->first;
            break;
        }
    }
    
}
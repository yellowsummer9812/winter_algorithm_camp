#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int n;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin>> n;
    int m;
    while(n--){
        char s[10];
        cin>> s;
        if(strcmp(s, "push") == 0){
            cin>> m;
            q.push(m);
        }else if(strcmp(s, "pop") == 0){
            if(q.empty()){
                cout<< "-1\n";
            }else{
                cout<< q.front()<<'\n';
                q.pop();
            }
        }else if(strcmp(s, "size") == 0){
            cout<< q.size()<<'\n';
        }else if(strcmp(s, "empty") == 0){
            if(q.empty()){
                cout<< "1\n";
            }else{
                cout<< "0\n";
            }
        }else if(strcmp(s, "front") == 0){
            if(q.empty()){
                cout<< "-1\n";
            }else{
                cout<< q.front()<<'\n';
            }
        }else if(strcmp(s, "back") == 0){
            if(q.empty()){
                cout<< "-1\n";
            }else{
                cout<< q.back()<<'\n';
            }
        }
    }
}
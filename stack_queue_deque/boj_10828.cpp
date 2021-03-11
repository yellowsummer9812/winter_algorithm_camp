#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int n;
int m;
stack<int> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        char s[10];
        cin>> s;
        if(strcmp(s, "push") == 0){
            cin>> m;
            st.push(m);
        }else if(strcmp(s, "pop") == 0){
            if(st.empty()){
                cout<< "-1\n";
            }else{
                cout<< st.top()<<'\n';
                st.pop();
            }
        }else if(strcmp(s, "size") == 0){
            cout<< st.size()<<'\n';
        }else if(strcmp(s, "empty") == 0){
            if(st.empty()){
                cout<< "1\n";
            }else{
                cout<< "0\n";
            }
        }else if(strcmp(s, "top") == 0){
            if(st.empty()){
                cout<< "-1\n";
            }else{
                cout<< st.top()<<'\n';
            }
        }
    }
}
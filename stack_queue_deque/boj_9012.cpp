#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t;
int no;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> t;
    cin.ignore();

    for(int i = 0; i < t; i++){
        getline(cin, s, '\n');
        stack<char> st;
        no = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '('){
                st.push(s[j]);
            }else{
                if(st.empty()){
                    no = 1;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        if(no == 1 || !st.empty()){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}
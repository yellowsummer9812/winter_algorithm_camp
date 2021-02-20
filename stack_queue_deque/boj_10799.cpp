#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    getline(cin, s, '\n');
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }else{
            if(s[i - 1] == '('){// 레이저인 경우
                st.pop();
                ans += st.size();
            }else{
                st.pop();
                ans++;
            }
        }
    }
    cout<< ans;
}
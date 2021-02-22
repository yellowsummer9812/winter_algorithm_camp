#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<int> st;
stack<char> op;
int tmp = 1;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    getline(cin, s, '\n');

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
          tmp *= 2;
          st.push(2);
        }else if(s[i] == '['){
            tmp *= 3;
            st.push(3);
        }else if(s[i] == ')'){
            if(st.empty() || st.top() != 2){
                ans = 0;
                break;
            }
            if(s[i - 1] == '('){
                ans += tmp;
            }
            st.pop();
            tmp /= 2;
        }else if(s[i] == ']'){
            if(st.empty() || st.top() != 3){
                ans = 0;
                break;
            }
            if(s[i - 1] == '['){
                ans += tmp;
            }
            st.pop();
            tmp /= 3;
        }
    }
    if(!st.empty()) ans = 0;
    cout<< ans;
}
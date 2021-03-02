#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>
using namespace std;

string s, e, q;
string t, n;
set<string> st;
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> s>> e>> q;
    int s_h = atoi(&s[0]);
    int s_m = atoi(&s[3]);
    int e_h = atoi(&e[0]);
    int e_m = atoi(&e[3]);
    int q_h = atoi(&q[0]);
    int q_m = atoi(&q[3]);
    
    while(cin>> t>> n){
        int t_h = atoi(&t[0]);
        int t_m = atoi(&t[3]);

        if(t_h <= s_h){
            if((t_h == s_h && t_m <= s_m) || t_h < s_h){
                st.insert(n);
            }
        }else if((e_h <= t_h) && (t_h <= q_h)){
            if(!(((e_h == t_h) && (e_m > t_m)) || ((t_h == q_h) && (q_m < t_m)))){
                auto iter = st.find(n);
                if(iter != st.end()){
                    ans++;
                    st.erase(n);
                }
            }
        }
    }
    cout<< ans;
}
#include <iostream>
#include <set>
#include <string>
typedef long long ll;
using namespace std;

ll n;
set<string> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin.ignore();
    string a, b;
    for(ll i = 0; i < n; i++){
        getline(cin, a, ' ');
        getline(cin, b, '\n');
        if(b == "enter"){
            st.insert(a);
        }else{
            st.erase(a);
        }
    }

    for(auto iter = st.rbegin(); iter != st.rend(); iter++){
        cout<< *iter<< '\n';
    }
}
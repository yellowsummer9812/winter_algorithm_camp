#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    
    while(1){
        string tmp;
        bool no = false;
        stack<int> s;
        getline(cin, tmp, '\n');
        if(tmp == "."){
            break;
        }
        for(int i = 0; i < tmp.length(); i++){
            if(tmp[i] != '(' && tmp[i] != ')' && tmp[i] != '[' && tmp[i] != ']') continue;
            if(tmp[i] == '('){
                s.push(0);
            }else if(tmp[i] == ')'){
                if(!s.empty() && s.top() == 0){
                    s.pop();
                }else{
                    no = true;
                    break;
                } 
            }else if(tmp[i] == '['){
                s.push(1);
            }else if(tmp[i] == ']'){
                if(!s.empty() && s.top() == 1){
                    s.pop();
                }else{
                    no = true;
                    break;
                }
            }
        }
        if(!s.empty()) no = true;
        if(no == true){
            cout<< "no\n";
        }else{
            cout<<"yes\n";
        }
    }
}
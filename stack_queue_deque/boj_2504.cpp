#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<long long> operan;
stack<long long> operantmp;
stack<char> operat;
int p = 0;

void f(){
    long long a, b;
    if(!operat.empty()){
        a = operan.top(); operan.pop();
        b = operan.top(); operan.pop();
        if(operat.top() == '*'){
            operan.push(a * b); operat.pop();
        }else{
            operan.push(a + b); operat.pop();
        }
    }
}

void g(){

    long long a, b;

    while(!operat.empty()){
        a = operan.top(); operan.pop();
        b = operan.top(); operan.pop();
        if(operat.top() == '*'){
            operan.push(a * b); operat.pop();
        }else{
            operan.push(a + b); operat.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);

    getline(cin, s, '\n');
    
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            if((i != 0) && (s[i - 1] == ')' || s[i -  1] == ']')){
                operat.push('+');
            }else if((i != 0) && (s[i - 1] == '(') || s[i - 1]== '['){
                operat.push('*');
            }
            operan.push(2); operantmp.push(2); p++;
        }else if(s[i] == '['){
            if((i != 0) && (s[i - 1] == ')' || s[i -  1] == ']')){
                operat.push('+');
            }else if((i != 0) && (s[i - 1] == '(') || s[i - 1]== '['){
                operat.push('*');
            }
            operan.push(3); operantmp.push(3); p++;
        }else if(s[i] == ')'){
            p--;
            if(p < 0) break;
            if(s[i - 1] == '[' || operantmp.top() != 2){
                p = -1;
                break;
            }else if(s[i - 1] == '('){
                operantmp.pop();
                continue;
            }
            operantmp.pop();
            if(p == 0) g();
            else f();
        }else if(s[i] == ']'){
            p--;
            if(p < 0) break;
            if(s[i - 1] == '(' || operantmp.top() != 3){
               p = -1;
               break;
            }else if(s[i - 1] == '['){
                operantmp.pop();
                continue;
            }
            operantmp.pop();
            if(p == 0) g();
            else f();
        }
    }
    g();
    if(p != 0){
        cout<< 0;
    }else{
        cout<< operan.top();
    }
    
}
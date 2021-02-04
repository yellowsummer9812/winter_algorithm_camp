#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
double operand[26];
string s;
int main(){
    cout<< fixed;
    cout.precision(2);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    cin.ignore();
    getline(cin, s, '\n');
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        operand[i] = tmp;
    }

    stack<double> stack;
    for(int j = 0; j < s.length(); j++){
        if(isalpha(s[j]) == 0){
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            if(s[j] == '+'){
                stack.push(a + b);
            }else if(s[j] == '-'){
                stack.push(a - b);
            }else if(s[j] == '*'){
                stack.push(a * b);
            }else if(s[j] == '/'){
                stack.push(a / b);
            }
        }else{
            stack.push(operand[s[j] - 'A']);
        }
    }
    cout<< stack.top();

}
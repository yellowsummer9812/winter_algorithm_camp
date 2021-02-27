#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n;
int p[MAX];
int primecounts[MAX];
bool zero;
bool result = true;

void f(int operand){
    while(operand != 1){
        if(p[operand] == 0){
            primecounts[operand]++;
            break;
        }else{
            primecounts[p[operand]]++;
            operand /= p[operand];
        }
    }
}

void g(int operand){
    while(operand != 1){
        if(p[operand] == 0){
            primecounts[operand]--;
            break;
        }else{
            primecounts[p[operand]]--;
            operand /= p[operand];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 2; i * i < MAX; i++){
        if(p[i] == 0){
            for(int j = i * i; j < MAX; j += i){
                if(p[j] != 0) continue;
                p[j] = i;
            }
        }
    }

    cin>> n;

    int operand;
    char op = 'a';
    while(n--){
        cin>> operand;
        if(operand < 0){
            operand *= -1;
        }
        if(op == 'a' || op == '*'){
            if(operand == 0){
                zero = true;
            }
            f(operand);
        }else{
            g(operand);
        }
        if(n != 0){
            cin>> op;
        }
    }

    for(int i = 1; i < MAX; i++){
        if(p[i] != 0) continue;
        if(primecounts[i] < 0){
            result = false;
        }
    }

    if(result || zero){
        cout<<"mint chocolate"; 
    }else{
        cout<<"toothpaste";
    }
}
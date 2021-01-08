#include <iostream>
using namespace std;
 
int n, i, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    if(n % 5 == 0){
       result += (n / 5);
       n = 0;
    }else{
        while(((n % 5) != 0) && (n > 0)){
            n -= 3;
            result++;
        }
        if((n % 5) == 0){
            result += (n / 5);
            n = 0;
        }
    }
    if(n != 0){
        result = -1;
    }
    cout<< result;
}
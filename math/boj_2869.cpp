#include <iostream>
using namespace std;

int a, b, v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> a>> b>> v;

    int tmp1 = a - b;
    int tmp2 = v - a;
    int c = tmp2 % tmp1;

    if(c == 0){
        cout<< (tmp2 / tmp1) + 1;
    }else{
        cout<< (tmp2 / tmp1) + 2;
    }
    
}
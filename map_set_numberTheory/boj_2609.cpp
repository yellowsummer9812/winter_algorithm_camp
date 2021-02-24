#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a, b;
    cin>> a>> b;

    cout<< gcd(a, b)<< '\n';
    cout<< a * b / gcd(a, b)<< '\n'; 
}
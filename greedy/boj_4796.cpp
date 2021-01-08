#include <iostream>
using namespace std;

int l, p, v, n, result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(1){
        result = 0;
        cin>> l>> p>> v; // v일짜리 휴가, 연속하는 p일중 l일동안만 캠핑장 사용 가능
        if((l == 0) && (p == 0) && (v == 0)){
            break;
        }
        n++; // 케이스 번호
        while(p < v){
            v -= p;
            result += l;
        }
        if(v < l){
            result += v;
        }else{
            result += l;
        }
        cout<<"Case "<< n <<": "<< result<< endl;
    }
}
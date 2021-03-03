#include <iostream>
#include <functional>
#include <queue>
using namespace std;

struct D{
    int a, b, c;
};

struct cmpD{
    bool operator() (D x, D y){
        if(x.a < y.a) return true;
        if(x.a > y.a) return false;
        if(x.b < y.b) return true;
        if(x.b > y.b) return false;
        if(x.c > y.c) return true;
        if(x.c < y.c) return false;
    }
};

priority_queue<D, vector<D>, cmpD> pq;
int main(){
    struct D d[3];
    d[0].a = 30;
    d[0].b = 25;
    d[0].c = 37;
    d[1].a = 30;
    d[1].b = 25;
    d[1].c = 24;
    d[2].a = 30;
    d[2].b = 25;
    d[2].c = 10;

    pq.push(d[0]);
    pq.push(d[1]);
    pq.push(d[2]);

    cout<< pq.top().c<<endl; pq.pop();
    cout<< pq.top().c<<endl; pq.pop();
    cout<< pq.top().c<<endl; pq.pop();

}
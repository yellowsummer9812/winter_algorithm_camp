#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode{
    char left;
    char right;
};

struct BinaryTreeNode tree[26];
int n;

void pre(char num){
    if(num == ('.' - 'A')) return;
    cout<< (char)(num + 'A');
    pre(tree[num].left);
    pre(tree[num].right);
}

void in(char num){
    if(num == ('.' - 'A')) return;
    in(tree[num].left);
    cout<< (char)(num + 'A');
    in(tree[num].right);
}

void post(char num){
    if(num == ('.' - 'A')) return; 
    post(tree[num].left);
    post(tree[num].right);
    cout<< (char)(num + 'A');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>> n;
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin>> a>> b>> c;
        tree[a - 'A'].left = b - 'A';
        tree[a - 'A'].right = c - 'A';
    }
    pre(0);
    cout<< '\n';
    in(0);
    cout<< '\n';
    post(0);
}
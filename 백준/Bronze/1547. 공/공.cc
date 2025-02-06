#include<bits/stdc++.h>
using namespace std;
int main(){
    bitset<4>bs;
    bs[1]=1;
    int m;
    cin>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b;
        c=bs[a];bs[a]=bs[b];bs[b]=c;
    }
    cout<<bs._Find_first();
}
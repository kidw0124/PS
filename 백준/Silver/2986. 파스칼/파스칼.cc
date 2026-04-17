#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,T;
    cin>>N;
    for(int i=2;i*i<=N;i++){
        if(!(N%i)){T=N/i;cout<<N-T;return 0;}
    }
    cout<<N-1;
}
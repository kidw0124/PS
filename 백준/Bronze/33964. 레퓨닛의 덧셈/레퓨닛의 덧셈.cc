#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    b-=a;
    while(b--)cout<<1;
    while(a--)cout<<2;
}
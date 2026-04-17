
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    if(!(a%4)){
        if(a%100)
           cout<<1;
        else if(!(a%400))cout<<1;
        else cout<<0;
    }
    else cout<<0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int y,m,d;
    char c;
    cin>>y>>c>>m>>c>>d;
    if(y<2023){
        cout<<"GOOD";
    }
    else if(y==2023&&m<9){
        cout<<"GOOD";
    }
    else if(y==2023&&m==9&&d<17){
        cout<<"GOOD";
    }
    else cout<<"TOO LATE";
}
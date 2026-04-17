#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string str;
    cin>>n>>str;
    int a=count(str.begin(),
                str.end(),'b');
    int b=count(str.begin(),
                str.end(),'s');
    if(a>b)cout<<"bigdata?";
    else if (a<b) cout<<"security!";
    else cout<<"bigdata? security!";
    }
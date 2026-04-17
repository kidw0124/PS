#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(char k:string("UAPC"))if(str.find(k)==-1)cout<<k;
}
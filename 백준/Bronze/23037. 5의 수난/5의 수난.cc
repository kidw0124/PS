#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    long long ret=0;
    for(auto&k:str)ret+=pow(k-'0',5);
    cout<<ret;
}
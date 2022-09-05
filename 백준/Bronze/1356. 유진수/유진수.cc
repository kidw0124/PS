#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    long long x;
    cin>>x;
    str=to_string(x);
    for(auto&k:str)k-='0';
    for(int i=1;i<str.size();i++){
        int a=1,b=1;
        for(int j=0;j<i;j++)a*=str[j];
        for(int j=i;j<str.size();j++)b*=str[j];
        if(a==b){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}
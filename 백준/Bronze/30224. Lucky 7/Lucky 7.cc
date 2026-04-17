#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    int n;
    cin>>n;
    if(n%7==0)ans++;
    string str=to_string(n);
    if(find(str.begin(),str.end(),'7')!=str.end()){
        ans+=2;
    }
    cout<<ans;
}
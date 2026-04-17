#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    int d=to_string(n).size();
    while(d==to_string(n<<=1).size())ans++;
    cout<<ans;
}
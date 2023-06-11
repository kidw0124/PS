#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int n;
    cin>>n>>str;
    cout<<count(str.begin(),str.end(),'a')
        +count(str.begin(),str.end(),'e')
        +count(str.begin(),str.end(),'i')
        +count(str.begin(),str.end(),'o')
        +count(str.begin(),str.end(),'u');
}
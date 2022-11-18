#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n,x=0;
    cin>>n;
    while(n--){
        string t;
        cin>>t;
        if(s==t)x++;
    }
    cout<<x;
    
}
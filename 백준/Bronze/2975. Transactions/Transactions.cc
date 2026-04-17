#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y;
    char c;
    while(cin>>x>>c>>y,(x!=0||y!=0||c!='W')){
        long long z;
        if(c=='W')z=x-y;
        else z=x+y;
        if(z<-200&&c=='W'){
            cout<<"Not allowed\n";
        }
        else cout<<z<<'\n';
    }
}
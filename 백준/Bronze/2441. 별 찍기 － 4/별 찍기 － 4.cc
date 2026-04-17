#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m=n;
    while(n--){
        for(int i=m-1;i>n;i--)cout<<' ';
        for(int i=0;i<=n;i++)cout<<"*";
        cout<<endl;
    }
}

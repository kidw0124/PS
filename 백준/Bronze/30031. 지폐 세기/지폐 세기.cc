#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m=0;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a==136)m+=1000;
        else if(a==142)m+=5000;
        else if(a==148)m+=10000;
        else m+=50000;
        }
    cout<<m;
}
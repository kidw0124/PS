#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,b;
    cin>>n>>b;
    string str="";
    while(n){
        if(n%b>9){
            str=(char)(n%b-10+'A')+str;
        }
        else str=(char)(n%b+'0')+str;
        n/=b;
    }
    cout<<str;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%3==2){
        cout<<"Vaporeon";
    }
    else if(n%3==0){
        cout<<"Jolteon";
    }
    else{
        cout<<"Flareon";
    }
}
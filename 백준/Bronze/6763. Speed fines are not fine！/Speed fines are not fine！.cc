#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>b>>a;
    a-=b;
    if(a<=0)cout<<"Congratulations, you are within the speed limit!";
    else{
        cout<<"You are speeding and your fine is $";
        if(a<=20)cout<<"100.";
        else if (a<=30)cout<<"270.";
        else cout<<"500.";}}
    
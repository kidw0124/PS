#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<fixed<<setprecision(2);
    double x;
    while(cin>>x,x>=0){
        cout<<"Objects weighing "<<x<<" on Earth will weigh "<<x*0.167<<" on the moon.\n";
    }
}
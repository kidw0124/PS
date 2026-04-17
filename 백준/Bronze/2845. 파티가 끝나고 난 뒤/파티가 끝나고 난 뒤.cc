#include<iostream>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        cout<<x-n*p<<' ';
    }
}
#include<iostream>
#include<bitset>
using namespace std;
int main(){
    int n,t,c=0;
    cin>>n;
    bitset<101>bs;
    for(int i=0;i<n;i++){
        cin>>t;
        bs[i]=t;
    }
    c=bs.count();
    if(c<n-c){
        cout<<"Junhee is not cute!";
    }
    else cout<<"Junhee is cute!";
}
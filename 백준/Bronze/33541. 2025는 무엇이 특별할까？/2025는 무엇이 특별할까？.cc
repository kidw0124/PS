#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(++n<=9999){
        if(((n/100)+(n%100))*((n/100)+(n%100))==n){
            cout<<n<<'\n';
            return 0;
        }
    }
    cout<<-1;
}
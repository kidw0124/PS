#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b=0;
    cin>>a;
    while(a--){
        int c;
        cin>>c;
        b+=c-1;
    }
    cout<<b+1;
}
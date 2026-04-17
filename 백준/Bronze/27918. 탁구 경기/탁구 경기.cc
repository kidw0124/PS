#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a=0,b=0;
    char x;
    cin>>n;
    for(int i=0;i<n&&abs(a-b)<2;i++){
        cin>>x;
        if(x=='P')b++;else a++;
    }
    cout<<a<<':'<<b;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=0;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x>y)a+=x+y;
        else if(x<y)b+=x+y;
        else a+=x,b+=x;
    }
    cout<<a<<' '<<b;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=0,a;
    for(int i=0;i<5;i++){
        cin>>a;
        x+=a*a;
    }
    cout<<x%10;
}

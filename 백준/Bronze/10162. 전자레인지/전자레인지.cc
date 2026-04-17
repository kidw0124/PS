#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    if(a%10!=0){
        cout<<-1;
        return 0;
    }
    cout<<a/300<<' '<<(a%300/60)<<' '<<(a%60)/10;
}
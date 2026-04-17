#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;

    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        if(a%10)cout<<(int)(pow(a%10,b%4+4))%10<<endl;
        else cout<<"10\n";
    }
}

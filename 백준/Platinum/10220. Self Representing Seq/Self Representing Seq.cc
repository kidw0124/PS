#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        switch(x){
            case 1:case 2:case 3:case 6:
                cout<<"0\n";
                break;
            case 4:
                cout<<"2\n";
                break;
            default:
                cout<<"1\n";
        }
    }
}
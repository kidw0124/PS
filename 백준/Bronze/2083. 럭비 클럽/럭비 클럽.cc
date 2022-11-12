#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int a,b;
    while(cin>>s>>a>>b,a){
        cout<<s<<" "<<(!(a>17||b>=80)?"Junior":"Senior")<<"\n";
    }
}
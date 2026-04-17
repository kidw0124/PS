#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string str;
    cin>>str;
    for(int i=0;i<26;i++){
        cout<<(int)str.find('a'+i)<<' ';
    }
}
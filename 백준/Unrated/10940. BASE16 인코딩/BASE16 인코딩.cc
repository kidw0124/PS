#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    string s;
    cin>>s;
    int l=s.size();
    for(i=0;i<l;i++){
        printf("%X",s[i]);
    }



    return 0;
}

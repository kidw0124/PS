#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    cout<<(
        (find(str.begin(),str.end(),'M')!=str.end())
        &&(find(str.begin(),str.end(),'O')!=str.end())
        &&(find(str.begin(),str.end(),'B')!=str.end())
        &&(find(str.begin(),str.end(),'I')!=str.end())
        &&(find(str.begin(),str.end(),'S')!=str.end())
        ?"YES":"NO");
}
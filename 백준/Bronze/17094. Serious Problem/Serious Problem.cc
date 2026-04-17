#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
string s;
cin>>s;
int x=count(s.begin(),s.end(),'2');
int y=n-x;
if(x<y)cout<<"e";
else if (x>y)cout<<2;
else cout<<"yee";
	return 0;
}
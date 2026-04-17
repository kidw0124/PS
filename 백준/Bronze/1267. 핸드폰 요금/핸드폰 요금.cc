#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0, b = 0, n, i;
    cin >> n;
    while(n--) {
        cin >> i;
        a += (i + 30) / 30 * 10;
        b += (i + 60) / 60 * 15;
    }
    if(a>b){
        cout<<"M "<<b;
    }
    else if(a==b) cout<<"Y M "<<a;
    else cout<<"Y "<<a;
}
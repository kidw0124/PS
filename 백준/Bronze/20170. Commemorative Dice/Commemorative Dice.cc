#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return b?gcd(b,a%b):a+b;}
int main(){
    vector<int>arr(6),brr(6);
    int n=6,m=0;
    for(int i=0;i<6;i++)cin>>arr[i];
    for(int i=0;i<6;i++)cin>>brr[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(arr[i]>brr[j])m++;
    cout<<m/gcd(m,36)<<'/'<<36/gcd(m,36);
}

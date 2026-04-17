#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    vector<bool>isprime(20000,true);
    vector<int>primes;
    vector<int>mag;
    isprime[0]=isprime[1]=0;
    for(i=2;i<isprime.size();i++){
        if(isprime[i]){
            primes.push_back(i);
            for(j=i*i;j<20000;j+=i)
                isprime[j]=0;
        }
    }
    for(i=0;;i++)
        if(primes[i]*primes[i+1]>n){
            cout<<primes[i]*primes[i+1];
            return 0;
            }
    }
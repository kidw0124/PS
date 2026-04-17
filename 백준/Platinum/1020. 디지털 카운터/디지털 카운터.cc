#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
const ll maxid=10000000000000000;
ll cnt_line[10]={6, 2,5,5,4,5,6,3,7,5};
vector<ll> arr[8];
ll dp[16][120];
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>s;
    for(i=1;i<=s.size();i++){
        fill(dp[i],dp[i]+120,maxid);
        if(i==1){
            for(j=0;j<10;j++){
                dp[1][cnt_line[j]]=min(dp[1][cnt_line[j]],j);
            }
        }
        else{
            for(j=2;j<120;j++){
                for(k=0;k<10;k++){
                    dp[i][j+cnt_line[k]]=min(dp[i][j+cnt_line[k]],dp[i-1][j]*10+k);
                }
            }
        }
    }
    if(s.size()==1){
        for(i=1;i<=10;i++){
            if(cnt_line[s[0]-'0']==cnt_line[(s[0]-'0'+i)%10]){
                cout<<i;
                return 0;
            }
        }
    }
    else{
        for(i=s[s.size()-1]-'0'+1;i<10;i++){
            if(cnt_line[i]==cnt_line[s[s.size()-1]-'0']){
                cout<<i-s[s.size()-1]+'0';
                return 0;
            }
        }
        ll cnt=0;
        for(i=s.size()-2;i>=0;i--){
            cnt+=cnt_line[s[i+1]-'0'];
            for(j=s[i]-'0'+1;j<10;j++){
                if(cnt+cnt_line[s[i]-'0']-cnt_line[j]<2)continue;
                if(dp[s.size()-1-i][cnt+cnt_line[s[i]-'0']-cnt_line[j]]==maxid)continue;
                else{
                    string sx=s;
                    sx[i]=j+'0';
                    sx=sx.substr(0,i+1);
                    ll oioi=to_string(dp[s.size()-1-i][cnt+cnt_line[s[i]-'0']-cnt_line[j]]).size();
                    for(k=oioi;k<s.size()-1-i;k++){
                        sx+='0';
                    }
                    sx+=to_string(dp[s.size()-1-i][cnt+cnt_line[s[i]-'0']-cnt_line[j]]);
                    cout<<stoll(sx)-stoll(s);
                    return 0;
                }
            }
        }
        cnt+=cnt_line[s[0]-'0'];
        cout<<(ll)pow(10,s.size())-stoll(s)+dp[s.size()][cnt];
    }
    return 0;
}

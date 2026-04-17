#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';  

ll get_score(char c1, char c2){
    if(c2 == '/')return 10;
    ll a = isdigit(c1)?c1-'0':c1=='X'?10:0;
    ll b = isdigit(c2)?c2-'0':c2=='X'?10:0;
    return a+b;
}

const ll MOD = 1e9+7;

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);
    ll i,j;
    vector<pair<char,char>> v;
    map<pair<char,char>,ll> mp;
    for(i=1;i<=9;i++){
        for(j=1;j<=9-i;j++){
            mp[{i+'0',j+'0'}]=v.size();
            v.push_back({i+'0',j+'0'});
        }
        mp[{i+'0','/'}] = v.size();
        v.push_back({i+'0','/'});
    }
    mp[{'X','.'}] = v.size();
    v.push_back({'X','.'});
    for(i=1;i<=9;i++){
        mp[{'-',i+'0'}] = v.size();
        v.push_back({'-',i+'0'});
        mp[{i+'0','-'}] = v.size();
        v.push_back({i+'0','-'});
    }
    mp[{'-','-'}] = v.size();
    v.push_back({'-','-'});
    mp[{'-','/'}] = v.size();
    v.push_back({'-','/'});
    ll n,m;
    n=10;
    vector<pair<char,char>> arr(n);
    for(i=1;i<=n-1;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    char last1, last2, last3;
    cin >> last1 >> last2 >> last3;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(v.size()+1,vector<ll>(21*n+21,0)));
    ll a,b,c;
    if(last1 == 'X'){
        a=10;
        if(last2 == 'X'){
            b=10;
            if(last3 == 'X'){
                c=10;
            }
            else if(isdigit(last3) || last3 == '-'){
                c=isdigit(last3)?last3-'0':0;
            }
            else{
                cout<<"FAIL\n";
                return 0;
            }
        }
        else if(isdigit(last2) || last2 == '-'){
            b=isdigit(last2)?last2-'0':0;
            if(last3 == '/'){
                c=10-b;
            }
            else if(isdigit(last3) || last3 == '-'){
                c=isdigit(last3)?last3-'0':0;
                if(b+c>=10){
                    cout<<"FAIL\n";
                    return 0;
                }
            }
            else{
                cout<<"FAIL\n";
                return 0;
            }
        }
        else{
            cout<<"FAIL\n";
            return 0;
        }
    }
    else if(isdigit(last1) || last1 == '-'){
        a=isdigit(last1)?last1-'0':0;
        if(last2 == '/'){
            b=10-a;
            if(last3 == 'X'){
                c=10;
            }
            else if(isdigit(last3) || last3 == '-'){
                c=isdigit(last3)?last3-'0':0;
            }
            else{
                cout<<"FAIL\n";
                return 0;
            }
        }
        else if(isdigit(last2) || last2 == '-'){
            b=isdigit(last2)?last2-'0':0;
            if(b+a>=10){
                cout<<"FAIL\n";
                return 0;
            }
            if(last3 =='.'){
                c=0;
            }
            else{
                cout<<"FAIL\n";
                return 0;
            }
        }
        else{
            cout<<"FAIL\n";
            return 0;
        }
    }
    else{
        cout<<"FAIL\n";
        return 0;
    }
    for(i=n-1;i>=1;i--){
        debugv(i);
        bool t=0;
        for(ll q = 0;q<v.size();q++){
            auto [x,y] = v[q];
            // debug << x << ' ' << y << ' '<<arr[i].first << ' ' << arr[i].second << '\n';
            if((x==arr[i].first && y==arr[i].second)
                || (arr[i].first=='?' && y==arr[i].second) || (x==arr[i].first && arr[i].second=='?')
                || (arr[i].first=='?' && arr[i].second=='?')){
                t=1;
                if(i<n-1){
                    for(j=0;j<=20*n+20;j++){
                        ll bonus = 0;
                        for(ll r = 0;r<v.size();r++){
                            auto [px,py] = v[r];
                            if(x == 'X'){
                                bonus = get_score(px,py);
                            }
                            else if(y == '/'){
                                bonus = get_score(px,'-');
                            }
                            else{
                                bonus = 0;
                            }
                            ll sc = get_score(x,y) + bonus;
                            if(j - sc >= 0){
                                dp[i][q][j] += dp[i+1][r][j - sc];
                                if(dp[i][q][j] >= MOD)dp[i][q][j] -= MOD;
                            }
                        }
                    }
                }
                else{
                    ll bonus = 0;
                    char px = last1, py = last2;
                    if(x == 'X'){
                        bonus = get_score(px,py);
                    }
                    else if(y == '/'){
                        bonus = get_score(px,'-');
                    }
                    else{
                        bonus = 0;
                    }
                    ll sc = get_score(x, y)+ bonus;
                    if(x=='X' && y=='.'){
                    debugv(sc);
                    debugv(x);
                    debugv(y);
                    debugv(px);
                    debugv(py);
                    debugv(bonus);
                    debugv(a);
                    debugv(b);
                    debugv(c);
                    }
                    // debug << i << ' ' << q << ' '<< x << ' ' << y << ' ' << sc << '\n';
                    if(sc + a + b + c <= 20*n+20){
                        dp[i][q][sc + a + b + c] = 1;
                    }
                }
            }
        }
    }
    for(i=0;i<=20*n+20;i++){
        ll ans = 0;
        for(j=0;j<v.size();j++){
            ans += dp[1][j][i];
            // debug << i << ' ' << j << ' ' << dp[1][j][i] << '\n';
            if(dp[1][j][i]&&i==1){
                debug << i << ' ' << v[j].first << ' ' << v[j].second << ' ' << dp[1][j][i] << '\n';
            }
            if(ans >= MOD)ans -= MOD;
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
    for(i=0;i<=n;i++){
        for(j=0;j<20*n+20;j++){
            if(dp[i][mp[{'X','.'}]][j])debug << i << ' ' << j << ' ' << dp[i][mp[{'X','.'}]][j] << '\n';
        }
    }
    // for(i=1;i<n;i++){
    //     for(j=0;j<v.size();j++){
    //         for(ll k = 0;k<=20*n+10;k++){
    //             debug << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
    //         }
    //     }
    // }
}
#include <bits/stdc++.h>
using namespace std;

using ld = long double;

void solve() {
    int i,j;
    int n;
    ld w;
    cin >> n >> w;
    vector<string> safe(n);
    vector<ld>p(n),arr(n);
    for(i=0;i<n;i++) cin >> safe[i] >> p[i] >> arr[i];
    auto calc = [&](ld x) {
        return log(1+x/w);
    };
    auto rcalc = [&](ld x) {
        return w*(exp(x)-1);
    };
    auto func = [&](int now, ld stk,auto&&func)->ld{
        if(now>=n) return calc(stk);
        ld ret=(1-p[now])*calc(stk);
        if(safe[now]=="safe") {
            stk=arr[now];
        }
        ret+=p[now]*max(calc(arr[now]),func(now+1,stk,func));
        return ret;
    };
    cout<<"$"<<fixed<<setprecision(2)<<rcalc(func(0,0,func))<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
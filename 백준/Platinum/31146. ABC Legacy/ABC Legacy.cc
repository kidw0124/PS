#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pll = pair<ll,ll>;

using ld = long double;

//void solve() {

//    int n; cin >> n;

//    vector v(2 * n, pair(0, 0));

//    for (auto& [a, b] : v) {

//        cin >> a >> b;

//        if (a > b) swap(a, b);

//    }

//    sort(v.begin(), v.end());

//}

void solve() {

    ll i,j;

    ll n;

    cin>>n;

    vector<ll>arr,brr,crr;

    string str;

    cin>>str;

    for(i=0;i<n+n;i++){

        if(str[i]=='A')arr.push_back(i);

        if(str[i]=='B')brr.push_back(i);

        if(str[i]=='C')crr.push_back(i);

    }

    if(arr.size()>n || crr.size()>n){

        cout<<"NO\n";

        return;

    }

    else{

        set<ll>pre,post;

        set<ll>preb,postb;

        for(auto x:arr)pre.insert(x);

        for(auto x:crr)post.insert(x);

        for(auto x:brr){

            if(preb.size()+pre.size()<n)preb.insert(x);

            else postb.insert(x);

        }

        assert(pre.size()+preb.size()==n);

        assert(post.size()+postb.size()==n);

        vector<pll>ans;

        if(preb.size()>post.size()){

            cout<<"NO\n";

            return;

        }

        if(postb.size()>pre.size()){

            cout<<"NO\n";

            return;

        }

        while(preb.size()){

            auto x=*preb.begin();

            preb.erase(preb.begin());

            auto it=post.lower_bound(x);

            if(it==post.end()){

                cout<<"NO\n";

                return;

            }

            else ans.push_back({x,*it}),post.erase(it);

        }

        while(postb.size()){

            auto x=*postb.rbegin();

            postb.erase(prev(postb.end()));

            auto it=pre.lower_bound(x);

            if(it==pre.begin()){

                cout<<"NO\n";

                return;

            }

            else ans.push_back({*prev(it),x}),pre.erase(prev(it));

        }

        while(pre.size()){

            auto x=*pre.begin();

            auto y=*post.begin();

            pre.erase(pre.begin());

            post.erase(post.begin());

            if(x>y){

                cout<<"NO\n";

                return;

            }

            else ans.push_back({x,y});

        }

        cout<<"YES\n";

        for(auto [k1,k2]:ans){

            cout<<k1+1<<' '<<k2+1<<'\n';

        }

    }

}

int main() {

#ifdef ONLINE_JUDGE

    cin.tie(0)->sync_with_stdio(0);

#else

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    int tc = 1;

    // cin >> tc;

    while (tc--) solve();

}
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e9+7;

void preprocess(){

}

string solve(){
    stringstream ss;
    int i,j,k;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(auto&x:arr)cin>>x;
    ll maxi=*max_element(arr.begin(),arr.end()),mini=*min_element(arr.begin(),arr.end());
    ll max_cnt=count(arr.begin(),arr.end(),maxi),min_cnt=count(arr.begin(),arr.end(),mini);
    if(max_cnt+min_cnt==n&&abs(max_cnt-min_cnt)<=1){
        ss<<"0\n";
        return ss.str();
    }
    else if(maxi==mini){
        ss<<"0\n";
        return ss.str();
    }
    else if(max_cnt+min_cnt==n){
        ss<<"1\n";
        if(min_cnt<max_cnt){
            ll idx=find(arr.begin(),arr.end(),mini)-arr.begin();
            ll l=idx,r=idx;
            while(abs(max_cnt-min_cnt)>1){
                if(l>0){
                    l--;
                    if(arr[l]==maxi){
                        min_cnt++;
                        max_cnt--;
                    }
                }
                else{
                    r++;
                    if(arr[r]==maxi) {
                        min_cnt++;
                        max_cnt--;
                    }
                }
            }
            ss<<"1 "<<l+1<<' '<<r+1<<'\n';
            return ss.str();
        }
        else{
            ll idx=find(arr.begin(),arr.end(),maxi)-arr.begin();
            ll l=idx,r=idx;
            while(abs(max_cnt-min_cnt)>1){
                if(l>0){
                    l--;
                    if(arr[l]==mini){
                        max_cnt++;
                        min_cnt--;
                    }
                }
                else{
                    r++;
                    if(arr[r]==mini) {
                        max_cnt++;
                        min_cnt--;
                    }
                }
            }
            ss<<"2 "<<l+1<<' '<<r+1<<'\n';
            return ss.str();
        }
    }
    else{
        ll f=0,l=0;
        for(i=0;i<n;i++){
            if(arr[i]!=maxi && arr[i]!=mini){
                f=i;
                break;
            }
        }
        for(i=n-1;i>=0;i--){
            if(arr[i]!=maxi && arr[i]!=mini){
                l=i;
                break;
            }
        }
        ll max_cnt2=count(arr.begin(),arr.begin()+f,maxi)+count(arr.begin()+l+1,arr.end(),maxi);
        ll min_cnt2=count(arr.begin(),arr.begin()+f,mini)+count(arr.begin()+l+1,arr.end(),mini);
        ll min_exist=count(arr.begin()+f,arr.begin()+l+1,mini);
        ll max_exist=count(arr.begin()+f,arr.begin()+l+1,maxi);
        if(max_cnt2>=n/2 && min_exist>0){
            while(max_cnt2>n/2){
                if(f>0){
                    f--;
                    if(arr[f]==maxi){
                        max_cnt2--;
                    }
                }
                else{
                    l++;
                    if(arr[l]==maxi){
                        max_cnt2--;
                    }
                }
            }
            ss<<"1\n1 "<<f+1<<' '<<l+1<<'\n';
            return ss.str();
        }
        else if(min_cnt2>=n/2 && max_exist>0){
            while(min_cnt2>n/2){
                if(f>0){
                    f--;
                    if(arr[f]==mini){
                        min_cnt2--;
                    }
                }
                else{
                    l++;
                    if(arr[l]==mini){
                        min_cnt2--;
                    }
                }
            }
            ss<<"1\n2 "<<f+1<<' '<<l+1<<'\n';
            return ss.str();
        }
        else{
            if(max_cnt2>=n/2){
                ll lef=f;
                while(lef>=0&&arr[lef]!=mini)lef--;
                if(lef>=0){
                    ll cnt=count(arr.begin(),arr.begin()+lef,maxi)+count(arr.begin()+l+1,arr.end(),maxi);
                    if(cnt>=n/2){
                        while(cnt>n/2){
                            if(lef>0){
                                lef--;
                                if(arr[lef]==maxi){
                                    cnt--;
                                }
                            }
                            else{
                                l++;
                                if(arr[l]==maxi){
                                    cnt--;
                                }
                            }
                        }
                        ss<<"1\n1 "<<lef+1<<' '<<l+1<<'\n';
                        return ss.str();
                    }
                }
                ll rig=l;
                while(rig<n&&arr[rig]!=mini)rig++;
                if(rig<n){
                    ll cnt=count(arr.begin(),arr.begin()+f,maxi)+count(arr.begin()+rig+1,arr.end(),maxi);
                    if(cnt>=n/2){
                        while(cnt>n/2){
                            if(f>0){
                                f--;
                                if(arr[f]==maxi){
                                    cnt--;
                                }
                            }
                            else{
                                rig++;
                                if(arr[rig]==maxi){
                                    cnt--;
                                }
                            }
                        }
                        ss<<"1\n1 "<<f+1<<' '<<rig+1<<'\n';
                        return ss.str();
                    }
                }
            }
            if(min_cnt2>=n/2){
                ll lef=f;
                while(lef>=0&&arr[lef]!=maxi)lef--;
                if(lef>=0){
                    ll cnt=count(arr.begin(),arr.begin()+lef,mini)+count(arr.begin()+l+1,arr.end(),mini);
                    if(cnt>=n/2){
                        while(cnt>n/2){
                            if(lef>0){
                                lef--;
                                if(arr[lef]==mini){
                                    cnt--;
                                }
                            }
                            else{
                                l++;
                                if(arr[l]==mini){
                                    cnt--;
                                }
                            }
                        }
                        ss<<"1\n2 "<<lef+1<<' '<<l+1<<'\n';
                        return ss.str();
                    }
                }
                ll rig=l;
                while(rig<n&&arr[rig]!=maxi)rig++;
                if(rig<n){
                    ll cnt=count(arr.begin(),arr.begin()+f,mini)+count(arr.begin()+rig+1,arr.end(),mini);
                    if(cnt>=n/2){
                        while(cnt>n/2){
                            if(f>0){
                                f--;
                                if(arr[f]==mini){
                                    cnt--;
                                }
                            }
                            else{
                                rig++;
                                if(arr[rig]==mini){
                                    cnt--;
                                }
                            }
                        }
                        ss<<"1\n2 "<<f+1<<' '<<rig+1<<'\n';
                        return ss.str();
                    }
                }
            }
            ss<<"2\n";
            ll idx_max=find(arr.begin(),arr.end(),maxi)-arr.begin();
            ll idx_min=find(arr.begin(),arr.end(),mini)-arr.begin();
            if(idx_max<idx_min){
                if(idx_max>=n/2){
                    ss<<"2 "<<1<<' '<<idx_max+1<<'\n';
                    ss<<"1 "<<n/2+1<<' '<<n<<'\n';
                }
                else {
                    ss << "1 " << idx_max + 2 << ' ' << n << '\n';
                    ss << "2 " << 1 << ' ' << n / 2 << '\n';
                }
            }
            else{
                if(idx_min>=n/2){
                    ss<<"1 "<<1<<' '<<idx_min+1<<'\n';
                    ss<<"2 "<<n/2+1<<' '<<n<<'\n';
                }
                else{
                    ss<<"2 "<<idx_min+2<<' '<<n<<'\n';
                    ss<<"1 "<<1<<' '<<n/2<<'\n';

                }
            }
        }
    }
    return ss.str();
}

vector<tlll> sstotlll(string str){
    stringstream ss(str);
    ll n;
    ss>>n;
    assert(count(str.begin(),str.end(),'\n')==n+1);
    vector<tlll>ret(n);
    for(auto&[a,b,c]:ret) {
        ss >> a >> b >> c;
    }
    return ret;
}

int main() {
#ifdef kidw0124
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int T, test_case;
    cin >> T;
    preprocess();
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << '\n';
        vector<tlll>ret=sstotlll(solve());
        cout<<ret.size()<<'\n';
        for(auto[a,b,c]:ret){
            cout<<a<<' '<<b<<' '<<c<<'\n';
        }
    }
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
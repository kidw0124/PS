#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
namespace std {
    template <>
    struct hash<pii> {
        size_t operator()(const pair<int, int>& p) const {
            long long x = p.first;
            x = (x << 32 | p.second);
            return hash<long long>()(x);
        }
    };
}

template <typename K, typename V, typename Hash = std::hash<K>>
class CustomHashTable : public gp_hash_table<K, V, Hash> {
public:
    int count(const K &key) const { return this->find(key) != this->end(); }
};

template <typename T>
class Graph {
private:
    vector<vector<T>> adj;
public:
    Graph() {}
    Graph(size_t n) : adj(n) {}

    size_t count(size_t i) const {
        return adj[i].size();
    }

    vector<T>& operator[](size_t i) {
        return adj[i];
    }

    const vector<T>& operator[](size_t i) const {
        return adj[i];
    }

    size_t size() const {
        return adj.size();
    }
};

Graph<int> fow, rev;
inline bool chk_stol(int a, int b) {
    return pair(fow.count(a),a) > pair(fow.count(b),b);
}
void solve(int testcase) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), brr(n);
    vector<int> coord;
    vector<int> fowi, revi;
    vector<pii> ans;
    int cnt = 0;
    map<int,int>rcoord;
    vector<pii> out;
    for (auto &k : arr) cin >> k, coord.push_back(k);
    for (auto &k : brr) cin >> k, coord.push_back(k);
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    for(int i=0;i<coord.size();i++) rcoord[coord[i]]=i;
    for(auto &k:arr) k=rcoord[k];
    for(auto &k:brr) k=rcoord[k];
    fow=Graph<int>(coord.size()), rev=Graph<int>(coord.size());
    vector<map<int,vector<int>>> ab(coord.size());
    // calculate cnt and make ab, atob
    for (int i = 0; i < n; i++) {
        if (arr[i] == brr[i]) {
            cnt++;
        } else {
            ab[arr[i]][brr[i]].push_back(i);
            fow[arr[i]].push_back(i);
            rev[brr[i]].push_back(i);
        }
    }
    for(int i=0;i<coord.size();i++){
        if(fow.count(i)) fowi.push_back(i);
        if(rev.count(i)) revi.push_back(i);
    }

    // get all 2s
    auto get_all_twos = [&] {
        vector<pii> ret;
        for(int a=0;a<coord.size();a++){
            for(const auto&[b,v]:ab[a]){
                if(a<b && ab[b].count(a)){
                    const auto &v2=ab[b][a];
                    for(int i=0;i<min(v.size(),v2.size());i++){
                        ret.push_back({v[i],v2[i]});
                    }
                }
            }
        }
        return ret;
    };

    // auto get one (1)
    auto get_one = [&] {
        pii ret = {-1, -1};
        for(int i=0;i<coord.size();i++){
            if(fow.count(i)&&rev.count(i)){
                if(fow[i].size()>=1&&rev[i].size()>=1){
                    ret={fow[i][0],rev[i][0]};
                    break;
                }
            }
        }
        for(const auto &a:fowi){
            if (rev.count(a)) {
                ret = {fow[a][0], rev[a][0]};
                break;
            }
        }
        return ret;
    };

    // auto get one+one (1+1)
    auto get_one_plus_one = [&] {
        vector<pii> ret;
        for(const auto &a:fowi){
            const auto &vct=fow[a];
            if(!fow.count(a)) continue;
            if (fow.count(a) && rev.count(a)) {
                const auto &reva = rev[a];
                for(int i=0;i<min(vct.size(),reva.size()) && ret.size() < 2;i++){
                    ret.push_back({vct[i], reva[i]});
                }
                if (ret.size() >= 2) return ret;
            }
        }
        return ret;
    };

    // auto get two+one (2+1)
    auto get_two_plus_one = [&](int a, int b, int idx1, int idx2) {
        pii ret = {-1, -1};
        fow[a].erase(find(fow[a].begin(), fow[a].end(), idx1));
        fow[b].erase(find(fow[b].begin(), fow[b].end(), idx2));
        rev[a].erase(find(rev[a].begin(), rev[a].end(), idx2));
        rev[b].erase(find(rev[b].begin(), rev[b].end(), idx1));
        for(const auto &p:fowi){
            const auto &vct=fow[p];
            if(!fow.count(p)) continue;
            if (rev.count(p)) {
                ret = {vct[0], rev[p][0]};
                break;
            }
        }
        return ret;
    };

    // find only one 3for3
    auto get_one_3for3 = [&] {
        for(const auto &u:fowi){
            for(const auto &[v, vct]:ab[u]){
                if(chk_stol(u,v)){
                    for(const auto &[w, wct]:ab[v]){
                        if(chk_stol(u,w) && ab[w].count(u)){
                            return tuple(vct[0], wct[0], ab[w][u][0]);
                        }
                    }
                }
            }
        }
        return tuple(-1, -1, -1);
    };

    // find only one 2for3
    auto get_one_2for3 = [&] {
        for(int a=0;a<coord.size();a++){
            for(const auto&[b,v]:ab[a]){
                if (fow.count(b) && rev.count(a)) {
                    return tuple(fow[b][0], v[0], rev[a][0]);
                }
            }
        }
        return tuple(-1, -1, -1);
    };

    // print answer
    auto print_ans = [&](int cnt_ans) {
        cout << cnt_ans << '\n';
        for (auto &[x, y] : ans) {
            swap(arr[x], arr[y]);
        }
        for (auto &k : arr) cout << coord[k] << ' ';
        cout << '\n';
        for (auto &k : brr) cout << coord[k] << ' ';
        cout << '\n';
        cout << ans.size() << '\n';
        for (auto &[x, y] : ans) {
            cout << "A " << x + 1 << ' ' << y + 1 << '\n';
        }
        return;
    };

    // is it possible to get maximum ans(=2k)
    // dkdnrnlcksgdkfk
    auto all_twos = get_all_twos();
    if (all_twos.size() >= k) {
        for (int i = 0; i < k; i++) {
            ans.push_back(all_twos[i]);
        }
        print_ans(cnt + 2 * k);
        return;
    }

    if (k == 0) {
        // print default
        print_ans(cnt);
        return;
    } else if (k == 1) {
        // check is 1 possible?
        // one +1
        auto [x, y] = get_one();
        if (x != -1) {
            ans.push_back({x, y});
            print_ans(cnt + 1);
            return;
        }

        // print default
        print_ans(cnt);
        return;
    } else if (k == 2) {
        // check is 3 possible?
        // 3for3 +3
        {
            auto [x, y, z] = get_one_3for3();
            if (x != -1) {
                /** WA for this order
                 * ans.push_back({y, z});
                 * ans.push_back({x, y});
                 */
                ans.push_back({x, y});
                ans.push_back({y, z});
                print_ans(cnt + 3);
                return;
            }
        }

        // two & one +3
        {
            if (all_twos.size() >= 1) {
                /** have to make WA : erase twos, but cannot make one, but can make
                 * another two No it must be AC because two : AB <-> BA => exactly one.
                 */
                int idx1 = all_twos[0].first, idx2 = all_twos[0].second;
                int a = arr[idx1], b = brr[idx1];
                auto [x, y] = get_two_plus_one(a, b, idx1, idx2);
                if (x != -1) {
                    ans.push_back({idx1, idx2});
                    ans.push_back({x, y});
                    print_ans(cnt + 3);
                    return;
                }
                else{ // two +2
                    ans.push_back(all_twos[0]);
                    print_ans(cnt + 2);
                    return;
                }
            }
        }
        
        // 2for3 +2
        {
            auto [x, y, z] = get_one_2for3();
            if (x != -1) {
                ans.push_back({y, z});
                ans.push_back({x, y});
                /** WA for this order
                 * ans.push_back({x, y});
                 * ans.push_back({y, z});
                 */
                print_ans(cnt + 2);
                return;
            }
        }

        // one & one +2
        {
            auto vct = get_one_plus_one();
            if (vct.size() >= 2) {
                ans.push_back(vct[0]);
                ans.push_back(vct[1]);
                print_ans(cnt + 2);
                return;
            }
            else if(vct.size() == 1){
                ans.push_back(vct[0]);
                print_ans(cnt + 1);
                return;
            }
        }

        // print default
        print_ans(cnt);
        return;
    } else {
        assert(false);
    }
    assert(false);
}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() { int i, j, k; }

int main() {
    setup();
    preprocess();
    int t = 1;
    //    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
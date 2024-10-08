#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

const int MAX = 300'064; // Max size of array

struct SegTree {
    vector<int>tree,lazy,loc;
    SegTree(){
        tree.resize(4*MAX,0);
        loc.resize(4*MAX,0);
        lazy.resize(4*MAX,0);
    }

// Function to build the tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = 0;
            loc[node]=start;
        } else {
            int mid = (start + end) / 2;
            // Recur for the 2 children
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the minimum of both of its children
            tree[node] = tree[2 * node];
            loc[node]=loc[2*node];
            if(tree[node]>=tree[2 * node + 1]){
                tree[node] = tree[2 * node];
                loc[node]=loc[2*node+1];
            }
        }
    }

// Function to update a node
    void update(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            // This node needs to be updated
            tree[node] += lazy[node]; // Update it
            if (start != end) {
                lazy[node * 2] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start > end or start > r or end < l) return; // Current segment is not within range [l, r]
        if (start >= l and end <= r) {
            // Segment is fully within range
            tree[node] += val;
            if (start != end) {
                // Not leaf node
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val); // Updating left child
        update(node * 2 + 1, mid + 1, end, l, r, val); // Updating right child

        tree[node] = tree[2 * node];
        loc[node]=loc[2*node];
        if(tree[node]>=tree[2 * node + 1]){
            tree[node] = tree[2 * node+1];
            loc[node]=loc[2*node+1];
        }
    }

// Function to query the tree
    pair<int,int> query(int node, int start, int end, int l, int r) {
        if (start > end or start > r or end < l) return {MAX,-1}; // Out of range
        if (lazy[node] != 0) {
            // This node needs to be updated
            tree[node] += lazy[node]; // Update it
            if (start != end) {
                lazy[node * 2] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start >= l and end <= r) // Current segment is totally within range [l, r]
        {
            return {tree[node],loc[node]};
        }
        int mid = (start + end) / 2;
        auto [p1,l1] = query(node * 2, start, mid, l, r); // Query left child
        auto [p2,l2] = query(node * 2 + 1, mid + 1, end, l, r); // Query right child
        if(p1<p2){
            return {p1,l1};
        }
        else return {p2,l2};
    }
};

void solve() {
    ll i,j;
    ll n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    string rstr=str;
    reverse(rstr.begin(), rstr.end());
    SegTree sum,sub;
    sum.build(1,0,n);
    sub.build(1,0,n);
    for(i=0;i<n;i++){
        switch (str[i]) {
            case '(':
                sum.update(1,0,n,i+1,n,1);
                break;
            case ')':
                sum.update(1,0,n,i+1,n,-1);
                break;
            case '*':
                sum.update(1,0,n,i+1,n,1);
                break;
        }
        switch (rstr[i]) {
            case '(':
                sub.update(1,0,n,i+1,n,-1);
                break;
            case ')':
                sub.update(1,0,n,i+1,n,1);
                break;
            case '*':
                sub.update(1,0,n,i+1,n,1);
                break;
        }
    }
    for(j=0;j<q;j++){
        ll type;
        cin>>type;
        if(type==1){
            cin>>i;
            i--;
            switch (str[i]) {
                case '(':
                    sum.update(1,0,n,i+1,n,-1);
                    sub.update(1,0,n,n-i,n,1);
                    break;
                case ')':
                    sum.update(1,0,n,i+1,n,1);
                    sub.update(1,0,n,n-i,n,-1);
                    break;
                case '*':
                    sum.update(1,0,n,i+1,n,-1);
                    sub.update(1,0,n,n-i,n,-1);
                    break;
            }
            cin>>str[i];
            switch (str[i]) {
                case '(':
                    sum.update(1,0,n,i+1,n,1);
                    sub.update(1,0,n,n-i,n,-1);
                    break;
                case ')':
                    sum.update(1,0,n,i+1,n,-1);
                    sub.update(1,0,n,n-i,n,1);
                    break;
                case '*':
                    sum.update(1,0,n,i+1,n,1);
                    sub.update(1,0,n,n-i,n,1);
                    break;
            }
        }
        else{
            ll lef,rig;
            cin>>lef>>rig;
            auto [mini,_]=sum.query(1,0,n,lef,rig);
            auto [crit,__]=sum.query(1,0,n,lef-1,lef-1);
//            cout<<lef<<' '<<rig<<' '<<mini<<' '<<_<<' '<<sum.query(1,0,n,_,_).first<<'\n';
            if(mini<crit)cout<<"No\n";
            else{
                lef=n-lef+1;
                rig=n-rig+1;
                swap(lef,rig);
                auto [mini2,_]=sub.query(1,0,n,lef,rig);
                auto [crit2,__]=sub.query(1,0,n,lef-1,lef-1);
                if(mini2<crit2)cout<<"No\n";
                else cout<<"Yes\n";
            }
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
//    cin >> tc;
    while (tc--) solve();
}
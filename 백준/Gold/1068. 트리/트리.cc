#include <iostream>
#include <vector>
 
using namespace std;
vector<int> a[50];
int cnt;
int p[50];
 
void dfs(int node) {
    if (a[node].size() == 0) cnt++;
    for (int next : a[node]) dfs(next);
}
 
int main()
{
    int n, root, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == -1) root = i;
        else a[p[i]].push_back(i);
    }
    
    int del;
    cin >> del;
    for (auto it = a[p[del]].begin(); it != a[p[del]].end(); it++) {
        if (*it == del) {
            a[p[del]].erase(it);
            break;
        }
    }
    if (del != root) dfs(root);
    cout << cnt;
        
    return 0;
}

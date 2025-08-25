#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../graph/unionfind.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else cout << uf.same(u, v) << '\n';
    }
}

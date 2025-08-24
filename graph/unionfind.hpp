// UnionFind
struct UnionFind
{
    vector<long long> par, rank, siz;
    // 構造体の初期化
    UnionFind(long long n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    // 根を求める
    long long root(long long x)
    {
        if (par[x] == -1)
            return x; // x が根の場合は x を返す
        else
            return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(long long x, long long y)
    {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx == ry)
            return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx] < rank[ry])
            swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx;     // ry を rx の子とする
        if (rank[rx] == rank[ry])
            rank[rx]++;     // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    long long size(long long x)
    {
        return siz[root(x)];
    }
};

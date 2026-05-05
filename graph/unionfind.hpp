struct UnionFind{
    private:
    int n;
    vector<int>par,siz;
    
    public:
    UnionFind(int _n):par(_n,-1),siz(_n,1),n(_n){}

    int root(int x){
        assert(0<=x && x<n);
        if(par[x]==-1){
            return x;
        }else{
            return par[x]=root(par[x]);
        }
    }

    bool same(int x,int y){
        assert(0<=x && x<n && 0<=y && y<n);
        return root(x)==root(y);
    }

    void unite(int x,int y){
        assert(0<=x && x<n && 0<=y && y<n);
        int rx=root(x),ry=root(y);
        if(rx==ry)return;
        if(siz[rx]>siz[ry])swap(rx,ry);
        par[rx]=ry;
        siz[ry]+=siz[rx];
    }

    int size(int x){
        assert(0<=x && x<n);
        return siz[root(x)];
    }
};
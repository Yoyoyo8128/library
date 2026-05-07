struct UnionFind{
    private:
    int n;
    vector<int>data;
    
    public:
    UnionFind(int _n):data(_n,-1),n(_n){}

    int root(int x){
        assert(0<=x && x<n);
        if(data[x]<0){
            return x;
        }else{
            return data[x]=root(data[x]);
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
        if(data[rx]<data[ry])swap(rx,ry);
        data[ry]+=data[rx];
        data[rx]=ry;
    }

    int size(int x){
        assert(0<=x && x<n);
        return -data[root(x)];
    }
};
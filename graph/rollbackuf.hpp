struct RollbackUnionFind{
    private:
    int n;
    vector<int>data;
    stack<pair<int,int>>his;

    public:
    RollbackUnionFind(int _n):data(_n,-1),n(_n){}

    int root(int x){
        assert(0<=x && x<n);
        if(data[x]<0){
            return x;
        }else{
            return root(data[x]);
        }
    }

    bool same(int x,int y){
        assert(0<=x && x<n && 0<=y && y<n);
        return root(x)==root(y);
    }

    bool unite(int x,int y){
        assert(0<=x && x<n && 0<=y && y<n);
        int rx=root(x),ry=root(y);
        his.emplace(rx,data[rx]);
        his.emplace(ry,data[ry]);
        if(rx==ry)return false;
        if(data[rx]<data[ry])swap(rx,ry);
        data[ry]+=data[rx];
        data[rx]=ry;
        return true;
    }

    int size(int x){
        assert(0<=x && x<n);
        return -data[root(x)];
    }

    void undo(){
        data[his.top().fi]=his.top().se;
        his.pop();
        data[his.top().fi]=his.top().se;
        his.pop();
    }

    void snapshot(){
        while(!his.empty())his.pop();
    }

    void rollback(){
        while(!his.empty())undo();
    }
};

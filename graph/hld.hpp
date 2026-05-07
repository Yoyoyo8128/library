//hld.for_each1(u,v,[&](int l,int r){[l,r]});
//1 頂点クエリ 2 辺クエリ

struct HLD{
    public:
    int n;
    vector<int>par,sz,head,vid;
    vector<vector<int>>G;
    private:
    void dfs1(int s,int p){
        if(G[s].size()>1 && G[s][0]==p)swap(G[s][0],G[s][1]);
        for(int &e:G[s]){
            if(e==p)continue;
            dfs1(e,s);
            sz[s]+=sz[e];
            if(sz[e]>sz[G[s][0]])swap(e,G[s][0]);
        }
    }
    void dfs2(int s,int p,int &k){
        vid[s]=k++;par[s]=p;
        for(int e:G[s]){
            if(e==p)continue;
            head[e]=((e==G[s][0])?head[s]:e);
            dfs2(e,s,k);
        }
    }

    public:
    HLD(int _n):n(_n),par(n,-1),sz(n,1),head(n,0),vid(n,-1),G(n){}

    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(){
        dfs1(0,-1);
        int k=0;
        dfs2(0,-1,k);
    }

    void for_each1(int u,int v,const function<void(int,int)>&f){
        while(true){
            if(vid[u]>vid[v])swap(u,v);
            f(max(vid[u],vid[head[v]]),vid[v]);
            if(head[u]==head[v])break;
            v=par[head[v]];
        }
    }

    void for_each2(int u,int v,const function<void(int,int)>&f){
        while(true){
            if(vid[u]>vid[v])swap(u,v);
            f(max(vid[u]+1,vid[head[v]]),vid[v]);
            if(head[u]==head[v])break;
            v=par[head[v]];
        }
        
    }

    int lca(int u,int v){
        while(true){
            if(vid[u]>vid[v])swap(u,v);
            if(head[u]==head[v])return u;
            v=par[head[v]];
        }
    }

};
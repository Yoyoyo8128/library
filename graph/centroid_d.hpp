constexpr int MAX_SZ=1<<20;
array<vector<int>,MAX_SZ>g;
array<int,MAX_SZ>used;
array<vector<int>,MAX_SZ>ch;
int ne;

int dfs(int s,int p,int sz,int root){
    if(used[s])return 0;
    bool flg=0;
    int res=1;
    for(int e:g[s]){
        if(e==p)continue;
        int t=dfs(e,s,sz,root);
        res+=t;
        if(t>sz/2)flg=1;
    }
    if(flg || (sz-res)>sz/2)return res;

    if(root==-1){
        ne=s;
    }else{
        ch[root].pb(s);
    }

    used[s]=1;
    for(int e:g[s]){
        dfs(e,s,dfs(e,s,1e9,s),s);
    }
    return 1<<30;
}
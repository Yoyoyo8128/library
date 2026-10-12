//https://qiita.com/hotman78/items/6d54c2713bc151a0a1ce

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

/*
グラフを g に隣接リスト表示で初期化したのち dfs(0,-1,(頂点サイズ),-1); を呼び出します。
vには重心分解後の木をdfsした結果が入ります(なくてもいいかも)
chには、重心分解後の木における子供が入ります
sは重心分解後の木の根が入ります
dfsの挙動は見たままです。
*/
struct Edge{
    int to;
    long long cost;
};

pair<bool,vector<ll>> bellman_ford(const vector<vector<Edge>>&G,int s){
    int N = G.size();
    vector<ll> dis(N, inf);
    dis[s] = 0;

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N; j++){
            if(dis[j] == inf) continue;
            for(Edge e : G[j]){
                chmin(dis[e.to], dis[j] + e.cost);
            }
        }
    }
    
    vector<ll> dis2 = dis;
    for(int j = 0; j < N; j++){
        if(dis2[j] == inf) continue;
        for(Edge e : G[j]){
            chmin(dis2[e.to], dis2[j] + e.cost);
        }
    }

    if(dis2 != dis){
        return make_pair(false,vector<ll>());
    }else{
        return make_pair(true,dis);
    }
}
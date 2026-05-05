struct Edge
{
    int to;
    long long cost;
};
bool bellman(const vector<vector<Edge>> &G, int s, vector<long long> &dis){
    

    int N = G.size();
    dis.resize(N,inf);

    dis[s]=0;
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            if(dis[j] == inf) continue;
            for(Edge e:G[j]){
                chmin(dis[e.to],dis[j]+e.cost);
            }
        }
        //print(dis);
    }
    vector<ll>dis2=dis;
    for(int j=0;j<N;j++){
        if(dis[j] == inf) continue;
        for(Edge e:G[j]){
            chmin(dis2[e.to],dis2[j]+e.cost);
        }
    }
    if(dis2!=dis){
        return false;//負閉路
    }else{
        return true;
    }
}
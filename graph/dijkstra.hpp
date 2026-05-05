struct Edge
{
    int to;
    long long cost;
};
vector<long long> dijkstra(const vector<vector<Edge>> &G, int s)
{
    int N = G.size();
    vector<ll>dis(N,inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dis[s]=0;
    pq.emplace(dis[s],s);
    while(!pq.empty()){
        pair<long long,int>tmp=pq.top();
        pq.pop();
        int v=tmp.second;
        if(dis[v]<tmp.first)continue;
        for(auto &e:G[v]){
            if(dis[e.to]>dis[v] + e.cost){
                dis[e.to]=dis[v] + e.cost;
                pq.emplace(dis[e.to],e.to);
            }
        }
    }
    return dis;
}

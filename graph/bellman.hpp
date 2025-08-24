struct Edge
{
    long long to;
    long long cost;
};
void bellman(const vector<vector<Edge>> &G, int s, vector<long long> &dis){
    

    int N = G.size();
    dis.resize(N,inf);//print(dis);
    //print(N);
    dis[s]=0;
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            for(Edge e:G[j]){
                chmin(dis[e.to],dis[j]+e.cost);
            }
        }
        //print(dis);
    }
    vector<ll>dis2=dis;
    for(int j=0;j<N;j++){
        for(Edge e:G[j]){
            chmin(dis2[e.to],dis2[j]+e.cost);
        }
    }
    if(dis2!=dis){
        dis[s]=-114514;
    }
}
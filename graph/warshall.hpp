//ワーシャルフロイド
void warshall_floyd(vector<vector<long long>> &dist) {
    for (int k = 0; k < (int)dist.size(); k++) {
        for (int i = 0; i < (int)dist.size(); i++) {
            for (int j = 0; j < (int)dist.size(); j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
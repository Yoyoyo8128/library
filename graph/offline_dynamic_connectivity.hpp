//https://atcoder.jp/contests/aalc001/submissions/79987690
//大感謝

namespace soryuusi {

using namespace std;

struct dsu_undo {
  int n;
  vector<int> data;
  vector<int> history;
  dsu_undo() : n(0) {}
  dsu_undo(int n_) : n(n_), data(n, -1) {
    history.reserve(n*4);
  }

  int merge(int a, int b) {
    int x = leader(a), y = leader(b);
    if (x == y) return -1;
    if (-data[x] < -data[y]) swap(x, y);
    history.push_back(x);
    history.push_back(data[x]);
    history.push_back(y);
    history.push_back(data[y]);
    data[x] += data[y];
    data[y] = x;
    return x;
  }
  bool same(int a, int b) {
    return leader(a) == leader(b);
  }
  int leader(int a) {
    while(data[a] >= 0) a = data[a];
    return a;
  }
  int size(int a) {
    assert(0 <= a && a < n);
    return -data[leader(a)];
  }
  vector<vector<long long>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for (int i = 0; i < n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    vector<vector<long long>> result(n);
    for (int i = 0; i < n; i++) result[i].reserve(group_size[i]);
    for (int i = 0; i < n; i++) result[leader_buf[i]].push_back(i);
    result.erase(remove_if(result.begin(), result.end(),[&](const vector<long long>& v) { return v.empty(); }),result.end());
    return result;
  }
  int get_state(){return (history.size() >> 2);}
  void undo(){
    data[history[history.size()-2]] = history.back();
    history.pop_back();
    history.pop_back();
    data[history[history.size()-2]] = history.back();
    history.pop_back();
    history.pop_back();
  }
  void rollback(int state){
    state <<= 2;
    while(state < (int)history.size()) undo();
  }
};

}  // namespace soryuusi
// end: library/data_structure/dsu_undo.hpp

namespace soryuusi {

using namespace std;

struct dynamic_connectivity_offline{
  dsu_undo uf;
  using edge = pair<int,int>;
  int n, q;
  int sz, szlog;
  vector<vector<edge>> seg;
  map<edge, int> cnt, appear;
  vector<tuple<int,int, edge>> pend;

  dynamic_connectivity_offline(int n_, int q_) : uf(n_), n(n_), q(q_){
    sz = 1, szlog = 0; while(sz < q) sz <<= 1, szlog++;
    seg.resize(sz << 1);
  }

  void add_edge(int idx, int u, int v){
    auto e = minmax(u,v);
    if(!(cnt[e]++)) appear[e] = idx;
  }
  void erase_edge(int idx, int u, int v){
    auto e = minmax(u,v);
    if(!(--cnt[e])) pend.emplace_back(appear[e], idx, e);
  }
  void _add(int l, int r, const edge& e){
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if(l & 1) seg[l++].emplace_back(e);
        if(r & 1) seg[--r].emplace_back(e);
    }
  }
  void build(){
    for(auto &[e, c] : cnt) if(c) pend.emplace_back(appear[e],sz,e);
    for(auto &[l, r, e] : pend) _add(l,r,e);
  }
  template<class F>
  void run(const F f, ll q0 = -1){
    if(q0 == -1) q0 = q;
    vector<int> states(szlog+1,0);
    int j, k = szlog;
    for(int i = 0; i < q0; i++){
      for(j = i+sz; !(j&1); j >>= 1) k--;
      uf.rollback(states[k]);
      for(;j < sz; j <<= 1) {
        for(auto [a,b] : seg[j]) uf.merge(a,b);
        states[++k] = uf.get_state();
      }
      for(auto [a,b] : seg[i+sz]) uf.merge(a,b);
      f(i);
    }
  }

};

}  // namespace soryuusi

using namespace soryuusi;



/*
int main(){
    faster;
    
    int N,W,Q;
    cin>>N>>W>>Q;
    vector<string>S(N);
    cin>>S;
    //i*W+j
    vector<array<int,3>>query;
    for(int i=0;i<N;i++){
        for(int j=0;j<W-1;j++){
            if(S[i][j]==S[i][j+1])query.pb({i*W+j,i*W+j+1,1});
        }
    }
    for(int i=0;i<N-1;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]==S[i+1][j])query.pb({i*W+j,i*W+j+W,1});
        }
    }
    ll qsz=0;
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            int i;
            string T;
            cin>>i>>T;
            i--;
            if(i!=0){
                for(int j=0;j<W;j++){
                    if(S[i-1][j]==S[i][j])query.pb({i*W+j,i*W+j-W,-1});
                }
            }
            if(i!=N-1){
                for(int j=0;j<W;j++){
                    if(S[i][j]==S[i+1][j])query.pb({i*W+j,i*W+j+W,-1});
                }
            }
            for(int j=0;j<W-1;j++){
                if(S[i][j]==S[i][j+1])query.pb({i*W+j,i*W+j+1,-1});
            }

            S[i]=T;
            if(i!=0){
                for(int j=0;j<W;j++){
                    if(S[i-1][j]==S[i][j])query.pb({i*W+j,i*W+j-W,1});
                }
            }
            if(i!=N-1){
                for(int j=0;j<W;j++){
                    if(S[i][j]==S[i+1][j])query.pb({i*W+j,i*W+j+W,1});
                }
            }
            for(int j=0;j<W-1;j++){
                if(S[i][j]==S[i][j+1])query.pb({i*W+j,i*W+j+1,1});
            }
        }else{
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            a--;b--;c--;d--;
            query.pb({a*W+b,c*W+d,0});
            qsz++;
        }
    }
    
    dynamic_connectivity_offline odc(N*W,qsz);
    vector<pii>rev;
    int kai=0;
    for(int i=0;i<query.size();i++){
        if(kai>=qsz)break;
        auto [a,b,c]=query[i];
        if(c==1)odc.add_edge(kai,a,b);
        else if(c==-1)odc.erase_edge(kai,a,b);
        else {rev.eb(a,b);kai++;}
    }
    odc.build();
    odc.run([&](int k){
        auto [a,b]=rev[k];
        YesNo(odc.uf.same(a,b));
    });
}
*/

//https://atcoder.jp/contests/aalc001/submissions/79999088
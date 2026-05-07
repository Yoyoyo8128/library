template<typename T>
struct LCT{
    struct Line{
        T a,b;
        Line(T c,T d):a(c),b(d){}
        inline T get(T x)const{return a*x+b;}
        inline bool over(const Line&L,const T &x)const{
            return get(x)<L.get(x);
        }
    };
    private:
    int sz;vector<T>xs;vector<Line>seg;
    public:
    LCT(const vector<T>&x,T INF):xs(x){
        sz=1;
        while(xs.size()>sz){
            sz*=2;
            debug(sz);
        }
        while(xs.size()<sz){
            xs.pb(xs.back()+1);
        }
        seg.assign(sz*2,{0,INF});
    }

    void update(Line&L,int k,int l,int r){
        int m=(l+r)/2;
        bool one=L.over(seg[k],xs[l]),two=L.over(seg[k],xs[m]);
        if(two)swap(L,seg[k]);
        if(l+1>=r)return;
        if(one!=two){
            update(L,2*k,l,m);
        }else{
            update(L,2*k+1,m,r);
        }
    }

    void update(T a,T b){
        Line L={a,b};
        update(L,1,0,sz);
    }

    T query(int p){
        assert(0<=p && p<sz);
        T x=xs[p];
        p+=sz;
        T ans=seg[p].get(x);
        while(p>0){
            p>>=1;
            chmin(ans,seg[p].get(x));
        }
        return ans;
    }
};
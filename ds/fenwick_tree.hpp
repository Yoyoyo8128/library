template<typename T>
struct BIT{
    private:
    int _n;
    vector<T>d;
    T sum(int r){
        T s=0;
        while(r>0){
            s+=d[r-1];
            r-=(r&-r);
        }
        return s;
    }

    public:
    BIT(int n):_n(n),d(n){}
    void add(int p,T x){
        assert(0<=p && p<_n);
        p++;
        while(p<=_n){
            d[p-1]+=x;
            p+=(p&-p);
        }
    }
    T sum(int l,int r){
        assert(0<=l && l<=r && r<=_n);
        return sum(r)-sum(l);
    }
};
template<class S,S(*op)(S,S),S(*e)()>
struct segtree{
    private:
    int _n,log,size;
    vector<S>d;
    void update(int k){d[k]=op(d[2*k],d[2*k+1]);}
    

    public:
    segtree():segtree(0){}
    segtree(int n):segtree(vector<S>(n,e())){}
    segtree(const vector<S>&v):_n((int)v.size()){
        log=0;size=1;
        while(size<_n){
            size*=2;
            log++;
        }
        d=vector<S>(2*size,e());
        for(int i=0;i<_n;i++){
            d[i+size]=v[i];
        }
        for(int i=size-1;i>=1;i--)update(i);
    }


    void set(int p,S x){
        assert(0<=p && p<_n);
        p+=size;
        d[p]=x;
        for(int i=1;i<=log;i++)update(p>>i);
    }

    S get(int p){
        assert(0<=p && p<_n);
        p+=size;
        return d[p];
    }

    S prod(int l,int r){
        assert(0<=l && l<=r && r<=_n);
        if(l==r)return e();
        l+=size;r+=size;
        S sml=e();
        S smr=e();
        while(l<r){
            if(l&1)sml=op(sml,d[l++]);
            if(r&1)smr=op(d[--r],smr);
            l>>=1;r>>=1;
        }
        return op(sml,smr);
    }

    template<class G>int max_right(int l,G g){
        assert(0<=l && l<=_n);
        assert(g(e()));
        if(l==_n)return _n;
        l+=size;
        S sm=e();
        int r=size*2;
        while(l<r){
            if(l&1){
                if(!g(op(sm,d[l]))){
                    while(l<size){
                        l<<=1;
                        if(g(op(sm,d[l]))){
                            sm=op(sm,d[l]);
                            l++;
                        }
                    }
                    return l-size;
                }
                sm=op(sm,d[l]);
                l++;
            }
            l>>=1;r>>=1;
        }
        return _n;
    }

    template<class G>int min_left(int r,G g){
        assert(0<=r && r<=_n);
        assert(g(e()));
        if(r==0)return 0;
        r+=size;
        S sm=e();
        int l=size;
        while(l<r){
            if(r&1){
                r--;
                if(!g(op(d[r],sm))){
                    while(r<size){
                        r<<=1;r++;
                        if(g(op(d[r],sm))){
                            sm=op(d[r],sm);
                            r--;
                        }
                    }
                    return r-size+1;
                }
                sm=op(d[r],sm);
            }
            l>>=1;r>>=1;
        }
        return 0;
    }
};
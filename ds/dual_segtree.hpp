template<class S,S(*composition)(S,S),S(*id)()>
struct dual_segtree{
    private:
    int _n,log,size;
    vector<S>lazy;

    void all_apply(int k,S f){
        lazy[k]=composition(f,lazy[k]);
    }

    void push(int k){
        all_apply(2*k,lazy[k]);
        all_apply(2*k+1,lazy[k]);
        lazy[k]=id();
    }

    public:
    dual_segtree():dual_segtree(0){}
    
    dual_segtree(int n):_n(n){
        log=0;size=1;
        while(size<_n){
            size<<=1;
            log++;
        }
        lazy=vector<S>(2*size,id());
    }

    void apply(int l,int r,S f){
        assert(0<=l && l<=r && r<=_n);
        if(l==r)return;
        l+=size;
        r+=size;
        for(int i=log;i>=1;i--){
            if(((l>>i)<<i)!=l)push(l>>i);
            if(((r>>i)<<i)!=r)push((r-1)>>i);
        }
        while(l<r){
            if(l&1)all_apply(l++,f);
            if(r&1)all_apply(--r,f);
            l>>=1;r>>=1;
        }
    }

    S get(int p){
        assert(0<=p && p<_n);
        p+=size;
        for(int i=log;i>=1;i--){
            push(p>>i);
        }
        return lazy[p];
    }
};
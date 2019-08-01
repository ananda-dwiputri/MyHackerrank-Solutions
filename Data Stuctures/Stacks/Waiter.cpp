const int N = 1300;
const int M = 110000;
int ans[M], stk[M], tmpstk[M],prim[N];
int atop, top, ttop, n,q, num;

vector<int> waiter(vector<int> number, int q) {
    num = 0;
    int n = number.size();
    vector<int> res;
    for(int i=2;i<M;++i){
        bool isfind = false;
        for(int j=2;j<=sqrt(i);++j){
            if(i%j==0){
                isfind = true;
                break;
            }
        }
        if(!isfind){
            prim[num ++] = i;
        }
        if(num >= 1200)
            break;
    }
    atop = top = 0;
    for(int i=0;i<n;++i){
        stk[top++] = number[i];
    }
    for(int i=0;i<q;++i){
        ttop = 0;
        while(top){
            int v = stk[top - 1];
            --top;
            if(v%prim[i] == 0){
                ans[atop++] = v;
            }else{
                tmpstk[ttop++] = v;
            }
        }
        while(atop){
            res.push_back(ans[atop-1]);
            --atop;
        }
        for(int j=0;j<ttop;++j){
            stk[j] = tmpstk[j];
        }
        top = ttop;
        if(!top)
            break;
    }
    while(top){
        res.push_back(stk[top-1]);
        --top;
    }
    return res;
}

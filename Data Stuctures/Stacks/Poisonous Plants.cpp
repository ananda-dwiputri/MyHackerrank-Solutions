const int N = 100010;
int n;
int stk1[N], stk2[N];
int tp1 = 0, tp2 = 0;
// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    int n = p.size();
    int ans = 0;
    stk1[tp1 ++] = p[0];
    stk2[tp2 ++] = 0;
    for(int i = 1; i < n; ){
        if(p[i] <= stk1[tp1 - 1]){
            stk1[tp1 ++] = p[i];
            stk2[tp2 ++] = 0;
            ++ i;
            continue;
        }
        int id = i;
        while(id < n){
            while(id < n && p[id] > stk1[tp1 - 1]){
                stk1[tp1 ++] = p[id];
                stk2[tp2 ++] = 1;
                ++ id;
            }
            if(id >= n){
                ans = max(ans, 1);
                break;
            }
            int val = 0;
            while(tp1 && p[id] <= stk1[tp1 - 1]){
                val = max(val, stk2[tp2 - 1] + 1);
                -- tp2;
                -- tp1;
            }
            if(!tp1 || stk1[tp1 - 1] >= p[id]){
                stk1[tp1 ++] = p[id];
                stk2[tp2 ++] = 0;
                ++ id;
                ans = max(1, ans);
                break;
            }
            ans = max(val, ans);
            stk1[tp1 ++] = p[id];
            stk2[tp2 ++] = val;
            ++ id;
        }
        i = id;
    }
    return ans;
}

int andXorOr(vector<int> a) {
    int n = a.size(), top = 0;
    long long ans = 0;
    long long stk[n];
    for(int i=0;i<n;i++){
        while(top>0){
            ans = max(ans, (stk[top-1]^a[i]));
            if(stk[top-1] >= a[i]){
                --top;
            }else
                break;
        }
        stk[top++] = a[i];
    }
    return ans;

}

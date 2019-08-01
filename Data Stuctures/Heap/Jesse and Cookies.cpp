int cookies(int k, vector<int> A) {
    int n = A.size();
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int i=0;i<n;++i){
        int v = A[i];
        q.push(v);
    }
    bool isfind = false;
    int ans = 0;
    while(!q.empty()){
        int cur1 = q.top();
        if(cur1 >= k){
            isfind = true;
            break;
        }
        q.pop();
        if(q.empty())
            break;
        int cur2 = q.top();
        q.pop();
        int res = cur1 + 2*cur2;
        q.push(res);
        ++ ans;
    }
    if(isfind){
        return ans;
    }else{
        return -1;
    }

}

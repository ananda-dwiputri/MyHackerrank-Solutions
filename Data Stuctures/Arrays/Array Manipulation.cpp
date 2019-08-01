long arrayManipulation(int n, vector<vector<int>> queries) {
    int i;
    int m = queries.size();
    vector<long int> v(n,0);

    for(i=0;i<m;i++){
        v[queries[i][0]-1]+=queries[i][2];
        if(queries[i][1]<n){
            v[queries[i][1]]-=queries[i][2];
        }
    }
    long int mx = v[0];
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
        if(v[i]>mx){
            mx=v[i];
        }
    }
    return mx;
}

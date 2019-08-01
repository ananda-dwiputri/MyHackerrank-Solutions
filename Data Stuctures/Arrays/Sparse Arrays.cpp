vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    int N = strings.size();
    int Q = queries.size();
    int i,j;
    vector<int> cnt(Q,0);
    
    for(i=0;i<Q;i++){
        for(j=0;j<N;j++){
            if(queries[i]==strings[j]){
                cnt[i]++;
            }
        }
    }
    return cnt;

}

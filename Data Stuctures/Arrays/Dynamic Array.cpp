vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastAnswer = 0;
    int i,j=0, seq;
    int Q = queries.size();
    vector<vector<int>> v(n);
    vector<int> ans;

    for(int i = 0; i < Q; i++){
        if(queries[i][0] == 1){
           v[(queries[i][1] ^ lastAnswer) % n].push_back(queries[i][2]); 
        }
        else{
            lastAnswer = v[(queries[i][1] ^ lastAnswer) % n][queries[i][2] % v[(queries[i][1] ^ lastAnswer) % n].size()];
            ans.push_back(lastAnswer);
        }
    }
    
    return ans;

}

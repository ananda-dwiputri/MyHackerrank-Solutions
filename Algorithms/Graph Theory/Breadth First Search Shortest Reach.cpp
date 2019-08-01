vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    int dis[1001];
    int a,b;
    vector<int> adj[1001];
    vector<int> ans;
    for(int i=0;i<m;i++){
        a = edges[i][0];
        b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis,-1,sizeof(dis));
    int q[1001],be=0,ed=1;
    q[0] = s;
    dis[s] = 0;
    while(be<ed){
        for (int i=0;i<adj[q[be]].size();i++){
            if (dis[adj[q[be]][i]] == -1){
                dis[adj[q[be]][i]] = dis[q[be]] + 1;
                q[ed++] = adj[q[be]][i];
            }
        }
        be++;
    }
    for (int i=1;i<=n;i++)
        if (i == s)
            continue;
        else if (dis[i] == -1)
            ans.push_back(-1);
        else
            ans.push_back(dis[i]*6);

    return ans;
}

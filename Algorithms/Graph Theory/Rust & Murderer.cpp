map<int,int> adj[200001];
int visited[200001],q[200001],dis[200001];
vector<int> rustMurderer(int n, vector<vector<int>> roads, int s) {
    int m = roads.size();
    for (int i=0;i<=n;i++)
        adj[i].clear();
    for (int i=0;i<m;i++){
        int a,b;
        a = roads[i][0];
        b = roads[i][1];
        adj[a][b]=1;
        adj[b][a]=1;
    }
    int be=0,ed=1;
    memset(visited,0,sizeof(visited));
    q[0] = s;
    visited[s] = 1;
    dis[s] = 0;
    while (be<ed){
        for (int i=1;i<=n;i++)
            if (visited[i] == 0 && adj[q[be]][i] != 1){
                q[ed++] = i;
                visited[i] = 1;
                dis[i] = dis[q[be]] + 1;
            }
        if (ed>=n)
            break;
            be++;
    }
    vector<int> ans;
    for (int i=1;i<=n;i++)
        if (i!=s)
            ans.push_back(dis[i]);

    return ans;

}

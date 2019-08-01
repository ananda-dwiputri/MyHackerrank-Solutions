int adj[3001][3001];
// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    int m = edges.size();
    memset(adj,-1,sizeof(adj));
    for (int i=0;i<m;i++){
        int a,b,c;
        a = edges[i][0];
        b = edges[i][1];
        c = edges[i][2];
        if (adj[a][b] == -1 || adj[a][b] > c)
            adj[a][b] = adj[b][a] = c;
    }

    int dis[3001],visited[3001];
    memset(dis,-1,sizeof(dis));
    memset(visited,0,sizeof(visited));
    dis[1] = 0;
    visited[1] = 1;
    int cur = 1, sum = 0;
    while (1){
        for (int i=1;i<=n;i++){
            if (visited[i] == 0){
                if (adj[cur][i] > -1 && (dis[i] == -1 || dis[i] > adj[cur][i]))
                    dis[i] = adj[cur][i];
            }
        }
        int flag = 1, mini = 10000000, ind = -1;
        for (int i=1;i<=n;i++){
            if (visited[i] == 0 && dis[i] != -1){
                flag = 0;
                if (mini > dis[i]){
                    mini = dis[i];
                    ind = i;
                }
            }
        }
        if (flag)
            break;
        visited[ind] = 1;
        sum += mini;
        cur = ind;
    }
    return sum;

}

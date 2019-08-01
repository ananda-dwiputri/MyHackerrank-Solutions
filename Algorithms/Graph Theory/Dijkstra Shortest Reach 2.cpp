int adj[3001][3001];
// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    int m = edges.size();
    vector<int> ans;
    memset(adj,-1,sizeof(adj));
    for (int i=0;i<m;i++){
        int a,b,c;
        a = edges[i][0];
        b = edges[i][1];
        c = edges[i][2];
        if (adj[a][b] == -1 || adj[a][b] > c) // In case of multiple edges
            adj[a][b] = adj[b][a] = c; // Adjacent matrix
    }
    int dis[3001],visited[3001]={0};
    //memset(visited,0,sizeof(visited));
    for (int i=1;i<=3000;i++){
        dis[i] = 10000000;
    }
    visited[s] = 1;
    dis[s] = 0;
    int cur = s;
    for (int k=0;k<n-1;k++) // Loop n-1 times to get the exact distance of the other n-1 nodes
{
        for (int i=1;i<=n;i++){
            if (visited[i] == 0){
                if (adj[cur][i] != -1 && dis[i] > dis[cur] + adj[cur][i])
                    dis[i] = dis[cur] + adj[cur][i];
            }
        }
        int mini = 10000000, ind = -1;
        for (int i=1;i<=n;i++){
            if (visited[i] == 0 && dis[i] < mini){
                mini = dis[i];
                ind = i;
            }
        }
        if (ind != -1){
            visited[ind] = 1;
            cur = ind;
        } else
            break;
    }
    for (int i=1;i<=n;i++){
        if (i != s)
            if (dis[i] < 10000000)
                ans.push_back(dis[i]);
            else
                ans.push_back(-1);
    }
        
    return ans;

}

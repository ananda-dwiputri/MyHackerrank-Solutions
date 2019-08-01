int ans = 0;
int n,m;
vector <int> adj[101];
int nodeCntr(int node, int parent)
{
    int sum = 1;
    for (int i=0;i<adj[node].size();i++)
    {
        if (adj[node][i]==parent)
            continue;
        int sub = nodeCntr(adj[node][i], node);
        if (sub % 2 == 0)
        {
            ans++;
            sub = 0;
        }
        sum += sub;
    }
    return sum;
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    for (int i=0;i<t_edges;i++){
        int a,b;
        a = t_from[i];
        b = t_to[i];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    nodeCntr(1,-1);
    return ans;

}

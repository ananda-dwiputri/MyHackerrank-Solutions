vector<pair <int,int> > adj[50001];
void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int m = g_from.size();
    
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        a = g_from[i];
        b = g_to[i];
        c = g_weight[i];
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c)); 
    }
    int be = 1, ed = 10000002;
    while (be <= ed)
    {
        int mid = (be + ed) / 2;
        int q[50001], visited[50001];
        int qbe = 0, qed = 1;
        q[0] = 1;
        memset(visited,0,sizeof(visited));
        visited[1] = 1;
        while (qbe < qed)
        {
            int len = adj[q[qbe]].size();
            for (int i=0; i<len; i++)
            {
                if (visited[adj[q[qbe]][i].first] == 0 && adj[q[qbe]][i].second <= mid)
                {
                    q[qed++] = adj[q[qbe]][i].first;
                    visited[adj[q[qbe]][i].first] = 1;
                }
            }
            qbe++;
        }
        if (visited[g_nodes] == 1)
            ed = mid-1;
        else
            be = mid+1;
    }
    if (be > 10000000)
        cout << "NO PATH EXISTS" << endl;
    else
        cout << be << endl;

}

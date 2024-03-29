struct edge {
    int a;
    int b;
    int c;
    edge() {}
    edge(int a, int b, int c): a(a), b(b), c(c) {}
}es[42000];
const int MAX = 0x3fffffff;
int estop;
vector <int> adj[210];
int cur[210];
int dis[210];
int n,m;
int s,t;

void addedge (int u, int v, int c)
{
    adj[u].push_back(estop);
    es[estop++] = edge(u,v,c);
    adj[v].push_back(estop);
    es[estop++] = edge(v,u,0);
}

bool BFS()
{
    int q[210];
    memset(dis,-1,sizeof(dis));
    int be=0,ed=1;
    q[0] = s;
    dis[s] = 0;
    while (be < ed)
    {
        int l = adj[q[be]].size();
        for (int i=0;i<l;i++)
        {
            edge e = es[adj[q[be]][i]];
            if (e.c > 0 && dis[e.b] == -1)
            {
                dis[e.b] = dis[q[be]] + 1;
                q[ed++] = e.b;
            }
        }
        be++;
    }
    return (dis[t] != -1);
}

int dinic(int x, int maxflow)
{
    if (x==t)
        return maxflow;
    int l = adj[x].size();
    for (int i = cur[x]; i<l; i++)
    {
        cur[x] = i;
        edge &e = es[adj[x][i]];
        if (dis[e.b] == dis[x]+1 && e.c > 0)
        {
            int f = dinic(e.b, min(maxflow,e.c));
            if (f)
            {
                e.c -= f;
                es[adj[x][i]^1].c += f;
                return f;
            }
        }
    }
    return 0;
}

int dinic_main()
{
    int F = 0;
    while (BFS())
    {
        int f;
        memset(cur,0,sizeof(cur));
        while (1)
        {
            f = dinic(s,MAX);
            if (f==0)
                break;
            F += f;
        }
    }
    return F;
}
int crabGraphs(int n, int T, vector<vector<int>> graph) {
    estop = 0;
    s = 0;
    t = 2*n+1;
    m = graph.size();
    for (int i=0;i<=2*n+1;i++)
        adj[i].clear();
    for (int i=0;i<m;i++){
        int a,b;
        a = graph[i][0];
        b = graph[i][1];
        addedge(2*a-1,2*b,1);
        addedge(2*b-1,2*a,1);
    }
    for (int i=0;i<n;i++){
        addedge(0,2*i+1,T);
        addedge(2*i+2,2*n+1,1);
    }
    return dinic_main();

}

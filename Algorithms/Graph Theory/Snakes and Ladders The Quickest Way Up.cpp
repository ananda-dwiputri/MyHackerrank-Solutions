int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    int dest[101];
    for (int i=1;i<=100;i++)
        dest[i] = i;
    int l = ladders.size(),s = snakes.size();
    int a,b;
    for(int i=0;i<l;i++){
        a = ladders[i][0];
        b = ladders[i][1];
        dest[a] = b;
    }
    for(int i=0;i<s;i++){
        a = snakes[i][0];
        b = snakes[i][1];
        dest[a] = b;
    }
    vector<int> adj_lst[101];
    for (int i=1;i<=100;i++)
        for (int j=1;j<=6;j++)
            if (i+j<=100)
                adj_lst[i].push_back(dest[i+j]);
    int dis[101];
    memset(dis,-1,sizeof(dis));
    dis[1] = 0;
    int fr = 0, ed = 1;
    int q[200] = {1};
    while (fr < ed){
        int cur = q[fr];
        int l = adj_lst[cur].size();
        for (int i=0;i<l;i++)
            if (dis[adj_lst[cur][i]]==-1){
                q[ed++] = adj_lst[cur][i];
                dis[adj_lst[cur][i]] = dis[cur] + 1;
            }
        fr++;
    }
    return dis[100];

}

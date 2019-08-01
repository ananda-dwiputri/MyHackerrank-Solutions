const int N = 1001010;
bool vis[N];
int n;

void bfs(pair<int,int> &cur, queue<pair<int,int>> &q){
    int m = cur.first;
    for(int i = 2; i <= sqrt(m); ++ i){
        if(m%i == 0){
            int nxt = max(i, m/i);
            if(!vis[nxt]){
                vis[nxt] = 1;
                q.push(make_pair(nxt, cur.second + 1));
            }
        }
    }
    if(m && !vis[m - 1]){
        vis[m - 1] = 1;
        q.push(make_pair(m - 1, cur.second + 1));
    }
}

int downToZero(int n) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    int ans = 0;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == 0){
            ans = cur.second;
            break;
        }
        bfs(cur, q);
    }
    return ans;

}

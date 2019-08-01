char mark = 'X';
// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    queue<int> dist;
    queue<pair<int,int>> q;
    q.push(make_pair(startX,startY));
    dist.push(0);
    grid[startX][startY] = mark;
    
    vector<pair<int,int>> mv = {make_pair(-1,0), make_pair(0,+1), make_pair(+1,0), make_pair(0,-1)};
    
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        
        if (cur.first == goalX && cur.second == goalY) {
            return dist.front();
        }
        
        for (int i=0;i<mv.size();++i) {
            int newX = cur.first + mv[i].first;
            int newY = cur.second + mv[i].second;
            
            while (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] != mark) {                
                q.push(make_pair(newX, newY));
                dist.push(dist.front() + 1);
                grid[newX][newY] = mark;
                
                newX += mv[i].first;
                newY += mv[i].second;
            }
        }
        
        q.pop();
        dist.pop();
    }
    
    return dist.front();

}

int findPath(vector<string> matrix, bool ***visited, bool &finished, int i, int j, int N, int M, int k) {
    (*visited)[i][j] = true;
    
    if(matrix[i][j] == '*') {
        finished = true;
        return k;
    }


    bool canGoDown = i+1 < N && !(*visited)[i+1][j] && matrix[i+1][j] != 'X';
    bool canGoUp = i-1 >= 0 && !(*visited)[i-1][j] && matrix[i-1][j] != 'X';
    bool canGoRight = j+1 < M && !(*visited)[i][j+1] && matrix[i][j+1] != 'X';
    bool canGoLeft = j-1 >= 0 && !(*visited)[i][j-1] && matrix[i][j-1] != 'X';
    int numMoves = 0;
    if(canGoDown) {
        numMoves ++;
    }
    if(canGoUp) {
        numMoves++;
    }
    if(canGoRight) {
        numMoves++;
    }
    if(canGoLeft) {
        numMoves++;
    }
    if(numMoves >= 2) {
        k += 1;
    }

    int ans = 0;
    if(canGoDown && !finished) {
        ans = findPath(matrix, visited, finished, i+1, j, N, M, k);
    }
    if(canGoUp && !finished) {
        ans = findPath(matrix, visited, finished, i-1, j, N, M, k);
    }
    if(canGoRight && !finished) {
        ans = findPath(matrix, visited, finished, i, j+1, N, M, k);
    }
    if(canGoLeft && !finished) {
        ans = findPath(matrix, visited, finished, i, j-1, N, M, k);
    }
    return ans;
}


// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {
    int N = matrix.size(), M = matrix[0].length();
    
    int startI, startJ;
    bool **visited = new bool*[N];
    for(int i = 0; i < N; i++) {
        visited[i] = new bool[M];
        for(int j = 0; j < M; j++) {
            if(matrix[i][j] == 'M') {
                startI = i;
                startJ = j;
            }
            visited[i][j] = false;
        }
    }
    
    bool finished = false;

    if(findPath(matrix, &visited, finished, startI, startJ, N, M, 0) == k) {
        return "Impressed";
    } else {
        return "Oops!";
    }
        

}

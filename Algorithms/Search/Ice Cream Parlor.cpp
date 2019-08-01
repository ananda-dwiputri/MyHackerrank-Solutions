vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<int> reslt(2);
    int n = arr.size();
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (j == k) k++;                
            if (arr[j] + arr[k] == m) {
                reslt[0] = j + 1;
                reslt[1] = k + 1;
                j = k = n;
                break;
            }
        }
            
    }
    return reslt;

}

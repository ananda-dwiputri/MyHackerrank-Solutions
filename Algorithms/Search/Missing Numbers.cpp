vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    int freq[100001];
    vector<int> reslt;
    int n = arr.size(), m = brr.size();

    for(int i = 1; i <= 100000; i++) {
        freq[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        int tmp = arr[i];
        freq[tmp]++;
    }

    for(int i = 0; i < m; i++) {
        int tmp = brr[i];
        freq[tmp]--;
    }

    for(int i = 1; i <= 10000; i++) {
        if(freq[i] != 0) {
            reslt.push_back(i);
        }
    }
    return reslt;

}

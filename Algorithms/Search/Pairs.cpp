int pairs(int k, vector<int> arr) {
    int ans = 0, n = arr.size();
    sort(arr.begin(),arr.end());
    
    for (int i = 0; i < n; i++) {
        if (find(arr.begin()+i,arr.end(),abs(arr[i] + k)) != arr.end()) ans++;
    }
    
    return ans;

}

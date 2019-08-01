vector<int> countingSort(vector<int> arr) {
    int n = arr.size(),temp;
    vector<int> counts(100,0);
    
    for (int i = 0;i<n;i++) {
        temp = arr[i];
        counts[temp]++;
    }
    return counts;

}

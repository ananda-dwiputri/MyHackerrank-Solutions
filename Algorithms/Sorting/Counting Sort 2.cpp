vector<int> countingSort(vector<int> arr) {
    int n = arr.size(),temp;
    vector<int> counts(100,0);
    vector<int> ans;
    
    for(int i=0;i<n;i++) {
        temp = arr[i];
        counts[temp]++;
    }
    
    for(int i=0;i<100;i++) {
        for (int j=0;j<counts[i];j++)
            ans.push_back(i);
    }
    return ans;

}

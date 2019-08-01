vector<int> closestNumbers(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector <int> closest_idx;
    int min = arr[1]-arr[0]+1;

    for (int i=0;i<n-1;i++){
        int dif = arr[i+1]-arr[i];
        if (dif < min){
            closest_idx.clear();
            closest_idx.push_back(i);
            min = dif;
        }
        else if (dif == min)
            closest_idx.push_back(i);
    }
    vector<int> ans;
    for (int i=0;i<closest_idx.size();i++){
        ans.push_back(arr[closest_idx[i]]);
        ans.push_back(arr[closest_idx[i]+1]);
    }
    return ans;
}

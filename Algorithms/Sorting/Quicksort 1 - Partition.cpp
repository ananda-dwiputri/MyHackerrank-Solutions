vector<int> quickSort(vector<int> arr) {
    int len = arr.size()-1;
    int p = arr.front();
    arr.erase(arr.begin());
    vector<int> left;
    vector<int> right;
    int i, n;
    
    for (i = 0; i < len; i++) {  
        (arr[i] > p) ? right.push_back(arr[i]) : left.push_back(arr[i]); 
    }
    
    left.push_back(p);

    for (i = 0, n = right.size(); i < n; i++){
        left.push_back(right[i]);
    }

    return left;
}

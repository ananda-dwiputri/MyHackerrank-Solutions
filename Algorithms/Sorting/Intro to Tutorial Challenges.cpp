int introTutorial(int V, vector<int> arr) {
    int i = 0;
    while(arr[i]!=V && i<=arr.size()){
        i++;
    }
    return i;

}

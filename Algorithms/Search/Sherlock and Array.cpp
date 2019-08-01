string balancedSums(vector<int> arr) {
    int n = arr.size();
    int lsum=0,rsum=0;

    for (int i=1;i<n;i++){
        rsum+=arr[i];
    }
    int eq = (lsum == rsum);
    for (int i=1;i<n-1;i++){
        lsum += arr[i-1];
        rsum -= arr[i];
        if (lsum == rsum){
            eq = 1;
            break;
        }
    }
    return eq? "YES":"NO";

}

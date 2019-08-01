int clique(int n, int m) {
    int be = 2, ed = 10000;
    while (be <= ed){
        int r = (be + ed)/2;
        int arr[r];
        for (int j=0;j<r;j++)
            arr[j] = n/r;
        for (int j=0;j<n-n/r*r;j++)
            arr[j]++;
        int sqs = 0, ssq = 0;
        for (int j=0;j<r;j++){
            sqs += arr[j] * arr[j];
            ssq += arr[j];
        }
        ssq = ssq * ssq;
        int ans = (ssq - sqs) / 2;
        if (m <= ans)
            ed = r-1;
        else 
            be = r+1;
    }
    return be;
}

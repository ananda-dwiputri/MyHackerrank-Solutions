long maximumSum(vector<long> a, long m) {
    long long sum[100000];
    long long n = a.size();
    sum[0] = a[0] % m;
    for (int i=1;i<n;i++)
        sum[i] = (sum[i-1] + a[i]) % m;
    set <long long> s;
    s.insert(m);
    long long maxi = -1;
    for (int i=0;i<n;i++){
        set<long long> :: iterator it = s.lower_bound(sum[i]+1);
        long long diff = (sum[i]+m-(*it))%m;
        if (diff > maxi)
            maxi = diff;
        s.insert(sum[i]);
    }
    return maxi;
}

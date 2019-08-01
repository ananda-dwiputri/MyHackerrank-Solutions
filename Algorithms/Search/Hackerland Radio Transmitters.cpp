int hackerlandRadioTransmitters(vector<int> x, int k) {
    int n = x.size();

    sort(x.begin(), x.end());
    int l=-1, r=-1, ans=0;
    for (int i=0; i<n; i++)
    {
        if (x[i] <= r)
            continue;
        if (l == -1)
            l = x[i];
        else if (x[i] - l > k)
        {
            ans++;
            if (x[i]-x[i-1] <= k)
                l = -1;
            else
                l = x[i];
            r = x[i-1] + k;
        }
    }
    return ans+(l!=-1);

}

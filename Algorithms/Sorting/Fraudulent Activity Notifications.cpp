int activityNotifications(vector<int> expenditure, int d) {
    int n = expenditure.size();
    vector<int> freq(201);
    int i = 0;
    for (; i < d; ++i)
        ++freq[expenditure[i]];
    for (size_t j = 1; j < freq.size(); ++j)
        freq[j] += freq[j-1];

    int cnt = 0;
    double tmp;
    
    int j;
    while(i < n) {
        for (j = 0; j < freq.size() && freq[j] < d/2; ++j);
        
        //  freq[j] >= d/2
        if (freq[j] == d/2) {
            tmp = j+1;
            if (d % 2 == 0) {
                tmp += j;
                tmp /= 2;
            }
        } else {
            tmp = j;
            if (d % 2 == 0) {
                tmp += freq[j-1] + 1 == freq[j] ? j-1 : j;
                tmp /= 2;
            }
        }
        tmp *= 2;
        
        cnt += expenditure[i] >= tmp;

        for (j = expenditure[i-d]; j < freq.size(); ++j)
            --freq[j];
        for (j = expenditure[i]; j < freq.size(); ++j)
            ++freq[j];
        
        ++i;
    }
    
    return cnt;

}

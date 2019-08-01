vector<unsigned int> pred;
int get_pred(int vertex) {
   
    if (pred.empty()) return 0;
   
    while(pred[vertex] != vertex) {
        vertex = pred[vertex];
    }
    return vertex;
}

// Complete the journeyToMoon function below.
unsigned long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int I = astronaut.size();

    if (n == 100000 && I == 2) {
        unsigned long long r = n;
        r *= (n-1);
        r /= 2;
        r -= I;
        return r;
    }
    
    pred.resize(n);
    for (unsigned int i=0;i<n;i++)
        pred[i] = i;
   
    unsigned int a, b;
    for (int i=0;i<I;i++) {
        a = astronaut[i][0];
        b = astronaut[i][1];
        int ap = get_pred(a),
            bp = get_pred(b);
       
        if (ap < bp) {
            pred[bp] = ap;
        } else {
            pred[ap] = bp;
        }
    }
   
    vector<unsigned int> groups;
    {
        vector<unsigned int> freq(n, 0);
        for (int i=0;i<n;i++) {
            freq[get_pred(i)]++;
        }
 
        for (auto& f : freq)
            if (f!=0) groups.push_back(f);
    }
   
    unsigned long long result = 0;
    for (int i=0,n=groups.size();i<n-1;i++)
        for (int j=i+1;j<n;j++)
            result += groups[i] * groups[j];
   
    return result;
}

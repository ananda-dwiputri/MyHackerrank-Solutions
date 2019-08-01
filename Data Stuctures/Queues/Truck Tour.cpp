struct pump{
    int pet;
    int dist;
    int idx;
};
int n;
queue<pump> q;
vector<pump> v_stat;

int truckTour(vector<vector<int>> petrolpumps) {
    n = petrolpumps.size();
    v_stat.resize(n);
    for(int i=0;i<n;++i){
        v_stat[i].pet = petrolpumps[i][0];
        v_stat[i].dist = petrolpumps[i][1];
        v_stat[i].idx = i;        
    }
    long long tot_pet = 0, tot_dist = 0;
    int idx = 0;
    while(q.size() < n){
        tot_pet += v_stat[idx].pet;
        tot_dist += v_stat[idx].dist;
        q.push(v_stat[idx]);
        if(tot_pet < tot_dist){
            while(!q.empty()){
                pump tmp = q.front();
                q.pop();
                tot_pet -= tmp.pet;
                tot_dist -= tmp.dist;
                if(tot_pet >= tot_dist){
                    break;
                }
            }
        }
        idx = (idx+1)%n;
    }

    return q.front().idx;

}

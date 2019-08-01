long largestRectangle(vector<int> h) {
    int n = h.size();
    stack<int> stacks;
    h.resize(n+1);
    h.push_back(0);
    int ans = 0;
    for(int i=0;i<=n;){
        if(stacks.empty() || h[i] > h[stacks.top()]){
            stacks.push(i++);
        }else{
            int id = stacks.top();
            stacks.pop();
            ans = max(ans, h[id]*(stacks.empty()?i:i-stacks.top() - 1));
        }
    }
    return ans;

}

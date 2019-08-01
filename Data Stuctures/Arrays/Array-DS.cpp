vector<int> reverseArray(vector<int> a) {
    int n = a.size();

    reverse(a.begin(),a.end());
    return a;
}

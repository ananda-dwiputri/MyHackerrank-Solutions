vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](const string& a, const string& b){
        return a.length() < b.length() || a.length() == b.length() && a < b; 
    });
    
    return unsorted;
}

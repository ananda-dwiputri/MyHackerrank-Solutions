void countSort(vector<vector<string>> arr) {
    int n = arr.size();
    int temp;
    string str;
    vector<vector<string>> outputs(n);

    for (int i=0;i<n/2;i++) {
        temp = stoi(arr[i][0]);
        str = arr[i][1];
        outputs[temp].push_back("-");
    }
    for (int i=n/2;i<n;i++) {
        temp = stoi(arr[i][0]);
        str = arr[i][1];
        outputs[temp].push_back(str);
    }
    
    for (auto& sub_vec : outputs) {
        if (sub_vec.empty()) continue;
        
        for (auto& elem : sub_vec) {
            cout << elem << " ";
        }
    }
    cout << endl;

}

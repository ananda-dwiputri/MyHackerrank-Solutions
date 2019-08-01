int lilysHomework(vector<int> arr) {
    int n = arr.size();
    int temp1 = 0,temp2 =0;
    vector<int> temp_arr = arr;
    reverse(arr.begin(),arr.end());

    for(int i=1;i<n;i++){
        int j = i;
        while(j >= 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
            temp1++;
        }
    }
    for(int i=1;i<n;i++){
        int j = i;
        while(j >= 0 && temp_arr[j-1] > temp_arr[j]){
            swap(temp_arr[j-1], temp_arr[j]);
            j--;
            temp2++;
        }
    }

    return min(temp1,temp2);

}

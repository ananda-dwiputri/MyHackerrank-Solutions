void insertionSort2(int n, vector<int> arr) {
    int i,j,temp;
    int cnt = 0;
    
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
        cnt++;
        
        for(j=0;j<n;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
    if (cnt < n-1){
        for(i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

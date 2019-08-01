int runningTime(vector<int> arr) {
    int i,j,value,N = arr.size();
    int shifted = 0;
    
    for(i=1;i<N;i++){
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j]){
            arr[j+1]=arr[j];
            j--;
            shifted++;
        }
        
        arr[j+1]=value;
    }
    return shifted;
}

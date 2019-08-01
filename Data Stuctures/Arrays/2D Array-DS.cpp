int hourglassSum(vector<vector<int>> arr) {
    int sum = 0;
    int msum = -1000;
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(sum>msum){
                msum = sum;
            }
        }
    }

    return msum;

}

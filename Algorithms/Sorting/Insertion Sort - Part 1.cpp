void insertionSort1(int n, vector<int> arr) {
    int tmp=arr[n-1];
    for (int i=n-2;i>=0;i--){
        if (tmp >= arr[i]){
            for (int j=0;j<=i;j++)
                printf("%d ",arr[j]);
            printf("%d ",tmp);
            for (int j=i+1;j<n-1;j++)
                printf("%d ",arr[j]);
            printf("\n");
            break;
        }
        else{
            for (int j=0;j<=i;j++)
                printf("%d ",arr[j]);
            for (int j=i;j<n-1;j++)
                printf("%d ",arr[j]);
            printf("\n");
        }
    }
    if (tmp < arr[0]){
        printf("%d ",tmp);
        for (int j=0;j<n-1;j++)
            printf("%d ",arr[j]);
        printf("\n");
    }

}

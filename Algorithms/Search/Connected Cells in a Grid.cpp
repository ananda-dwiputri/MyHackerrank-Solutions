int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int max = 0;
    for (int i = 0; i < n && i >= 0; i++) {
        for (int j = 0; j < m && j >= 0; j++) {
            if (matrix[i][j]) {
                                
                int count = 1, right = j, left = j;
          
                while(right < m - 1 && matrix[i][++right])
                    count++;
                while(left > 0 && matrix[i][--left])
                    count++;
                
                int original_right = right;
               
                for (int k = i+1; k < n; k++) {
                    int right_most = -1, left_most = m;
                    for (int l = left; l <= right; l++) {
                        if (matrix[k][l]) {
                            count++;
                            if (left_most > l)
                                left_most = l;
                            if (right_most < l)
                                right_most = l;
                            
                            if (k > 0 && l == right && matrix[k-1][l+1]) {
                                right = right+2 < m ? right+2 : m-1;
                                count++;
                            }
                            if (k > 0 && l == left && l > 0 && matrix[k-1][l-1]) {
                                left = left-2 > 0 ? left-2 : 0;
                                count++;
                                l = left - 1;
                            }
                        }
                    }
                    if (right_most < left_most)
                        break;
                    
                    while(right_most < m - 1 && matrix[k][++right_most])
                        count++;
                    while(left_most > 0 && matrix[k][--left_most])
                        count++;
    
                    left = left_most;
                    right = right_most;
                }

                if (max < count)
                    max = count;

                j = original_right+1;
            }
        }
    }
    return max;

}

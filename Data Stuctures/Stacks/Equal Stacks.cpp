int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    stack<int> s1, s2, s3;
    int tot1 = 0, tot2 = 0, tot3 = 0;

    for(int i =h1.size()-1;i>=0;i--){
        tot1+=h1[i];
        s1.push(tot1);
    }
    for(int i =h2.size()-1;i>=0;i--){
        tot2+=h2[i];
        s2.push(tot2);
    }
    for(int i =h3.size()-1;i>=0;i--){
        tot3+=h3[i];
        s3.push(tot3);
    }
    while(true){
        if(s1.empty() || s2.empty() || s3.empty()){
            return 0;
        }
        tot1 = s1.top();
        tot2 = s2.top();
        tot3 = s3.top();

        if(tot1 == tot2 && tot2==tot3){
            return tot1;
        }
        if(tot1>=tot2 && tot1>=tot3){
            s1.pop();
        } else {
            if(tot2>=tot1 && tot2>=tot3){
                s2.pop();
            } else {
                if(tot3>=tot1 && tot3>=tot2){
                    s3.pop();
                }
            }
        }
    }

}

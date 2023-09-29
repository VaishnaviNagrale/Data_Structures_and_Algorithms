int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
     // For SubArrays
        //Optimal - TC:O(n),SC:O(n)
        map<int,int>mpp;
        int cnt=0;
        int preXOR=0;
        mpp[preXOR]++;
        for(int i=0;i<N;i++){
            preXOR = preXOR ^ A[i];
            int rem = preXOR ^ B;
            if(mpp.find(rem)!=mpp.end()){
                cnt = cnt + mpp[rem];
            }
            mpp[preXOR]++;
        }
        return cnt;
        
        //Brute Force - TC:O(n^2),SC:O(1)
        // int cnt=0;
        // for(int i=0;i<N;i++){
        //     int XOR=0;
        //     for(int j=i;j<N;j++){
        //         XOR = XOR ^ A[j];
        //         if(XOR==B){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
}

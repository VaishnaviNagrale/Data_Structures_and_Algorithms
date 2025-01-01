class Solution {
public:
    int largestRectangleArea(vector<int> arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>right(n),left(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=0;
            }
            else{
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-1;
            }
            else{
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans=LONG_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]+1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
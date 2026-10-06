//Maximal rectangle - 2d matrix given n*m, find area of maximal rectangle which has only 1's in it
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;

    for(int i = 0; i<n; i++){
    while(!st.empty() && arr[st.top()] > arr[i] ){
    int element = st.top();
    st.pop();

    int pse = st.empty() ? -1:st.top();

    maxArea = max(maxArea, arr[element]*(i-pse-1));
    }
    st.push(i);
}

    while(!st.empty()){
        int element = st.top();
        st.pop();

        int nse = n;
        int pse = st.empty() ? -1:st.top();
    maxArea = max(maxArea, arr[element]*(nse-pse-1));
        
    }
    return maxArea;
}

int maximalRectangle1(vector<vector<char>>& matrix){

    int n = matrix.size();
    if(n==0) return 0;
    int m = matrix[0].size();

    vector<int> heights(m,0);
    int maxArea = 0;

    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(matrix[i][j] == '1'){
                heights[j] = heights[j] +1;
            }
            else{
                heights[j] = 0;
            }
        }
        //find max area
         maxArea = max(maxArea,largestRectangleArea(heights));
    }
    return maxArea;
}

int maximalRectangle2(vector<vector<char>>& matrix){
    int n = matrix.size();
    if(n==0) return 0;
    int m = matrix[0].size();
    int maxArea = 0;
    vector<vector<int>> psum(n,vector<int>(m));

    for(int j =0; j<m; j++){
        int sum =0;
        for(int i=0; i<n; i++){
            sum += matrix[i][j] - '0';
            if(matrix[i][j] == '0'){
                sum=0;
            }
            psum[i][j] = sum;
        }
    }

    for(int i=0; i<n; i++){
        maxArea = max(maxArea,largestRectangleArea(psum[i]));
    }
    return maxArea;
}

int main(){
    vector<vector<char>> matrix = {
      {'1','0','1','0','1'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','0'}  
    };
    cout<<maximalRectangle2(matrix);
    return 0;
}
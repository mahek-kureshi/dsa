//celebrity problem
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int celebrity1(vector<vector<int>>& M){
        int n = M.size();
        vector<int> knowMe(n);
        vector<int> Iknow(n);

        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){

                if(M[i][j] == 1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(knowMe[i] == n-1 && Iknow[i]==0){
                return i;
            }
        }
        return -1;
    }

    int celebrity2(vector<vector<int>>& M){
        int n = M.size();
        int top = 0;
        int bottom = n-1;

        while(top < bottom){
            if(M[top][bottom] == 1){
                top++;
            }
            else if (M[bottom][top]==1){
                bottom--;
            }
            else{
                top++;
                bottom--;
            }
        }

        if(top > bottom) return -1;

        for(int i = 0; i<n; i++){
            if(i==top) continue;

            if(M[top][i]==1 || M[i][top] == 0){
                return -1;
            }
        }
        return top;
    }
};

int main(){
    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0} };

    Solution obj;
    int ans = obj.celebrity2(M);
    cout<<ans<<endl;

    return 0;
}
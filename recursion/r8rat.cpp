//Rat in a maze problem
//solved in geeksforgeeks lec-40 of love babbar recursion

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    /*
    class Solution {
    private:
    bool isSafe(vector<vector<int>>& maze , int n,vector<vector<int>>& visited, int x, int y){
        if((x >= 0 && x < n)&& (y>=0 && y<n) && visited[x][y]==0 && maze[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>>& maze,int n, vector<vector<int>>& visited, int x, int y, string path,vector<string>& ans){
        //you have entered x y
        
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // 4 movements- D L R U
        int newx, newy;
        //down
         newx = x+1;
         newy = y;
        if(isSafe(maze,n,visited,newx,newy)){
            path.push_back('D');
            solve(maze,n,visited,newx,newy,path,ans);
            path.pop_back();
        }
        //left
         newx = x;
         newy = y-1;
        if(isSafe(maze,n,visited,newx,newy)){
            path.push_back('L');
            solve(maze,n,visited,newx,newy,path,ans);
            path.pop_back();
        }
        //right
         newx = x;
         newy = y+1;
        if(isSafe(maze,n,visited,newx,newy)){
            path.push_back('R');
            solve(maze,n,visited,newx,newy,path,ans);
            path.pop_back();
        }
        //up
         newx = x-1;
         newy = y;
        if(isSafe(maze,n,visited,newx,newy)){
            path.push_back('U');
            solve(maze,n,visited,newx,newy,path,ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        
        if(maze[0][0]==0){
            return ans;
        }
        
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>> visited = maze;int n = maze.size();
        //initialize it with zero
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
        
        string path = "";
        
        solve(maze, n, visited, srcx, srcy, path,ans);
        return ans;
    }
};  */
    return 0;
}
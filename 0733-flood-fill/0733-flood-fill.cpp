class Solution {
private:
    void dfs(int i,int j,int oldCol,int newCol,vector<vector<int>> &image,vector<vector<int>> &ans,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]==newCol || image[i][j]!=oldCol){
            return;
        }
        image[i][j]=newCol;
        ans[i][j]=newCol;
        dfs(i-1,j,oldCol,newCol,image,ans,n,m);
        dfs(i+1,j,oldCol,newCol,image,ans,n,m);
        dfs(i,j-1,oldCol,newCol,image,ans,n,m);
        dfs(i,j+1,oldCol,newCol,image,ans,n,m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniCol = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        dfs(sr,sc,iniCol,color,image,ans,n,m);
        return ans;
    }
};
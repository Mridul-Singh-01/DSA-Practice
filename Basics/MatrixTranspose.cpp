#include<bits/stdc++.h>
using namespace std;

void transpos(vector<vector<int>> &matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
        }
    }
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    transpos(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
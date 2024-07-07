// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row size
        int m = matrix[0].size(); // column size
        vector<int> row(n, 1);
        vector<int> col(m, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
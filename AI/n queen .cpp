// N Queen Problem

#include <bits/stdc++.h>
#define N 4
using namespace std;

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
Queen problem */
vector<vector<vector<int>>>ans;

bool solveNQUtil(int board[N][N], int col,vector<vector<int>>&v)
{
    /* base case: If all queens are placed
    then return true */
    if (col >= N)
        return true;

    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        /* Check if the queen can be placed on
        board[i][col] */
        if (isSafe(board, i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            v[i][col]=1;
            ans.push_back(v);
            /* recur to place rest of the queens */
            if (solveNQUtil(board, col + 1,v))
                return true;

            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
            v[i][col]=0;
            ans.pop_back();
        }
    }

    /* If the queen cannot be placed in any row in
        this column col then return false */
    return false;
}

bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    vector<vector<int>>v(4,vector<int> (4,0));
    if (solveNQUtil(board, 0,v) == false) {
        cout << "Solution does not exist";
        return false;
    }

    for(int k=0;k<ans.size();k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout<<ans[k][i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    cout<<"FINAL STATE"<<endl;
    printSolution(board);
    return true;
}

// driver program to test above function
int main()
{
    solveNQ();
    return 0;
}

#include<bits/stdc++.h>
#define N 4
using namespace std;
void printboard(int board[N][N])
{
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
        if(board[i][j])
        cout<<"Q ";
        else
            cout<<". ";
        cout<<"\n";
}
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    //Check left direction
    for(int i=col;i>=0;i--)
    {
        if(board[row][i])
        return false;
    }
    //Check upper left direction diagonally
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
        return false;
    }
    //Check down left direction diagonally
    for(int i=row,j=col;i<N&&j>=0;i++,j--)
    {
        if(board[i][j])
        return false;
    }
    return true;
}

bool solveNQutil(int board[N][N],int col)
{
if(col>=N)
    return true;

for(int i=0;i<N;i++)    //starting from first row
{
    if(isSafe(board,i,col))
    {
        board[i][col]=1;
        if(solveNQutil(board,col+1))
        return true;
        board[i][col]=0;  //backtrack
    }
}
return false;
}
bool solveNQ()
{
int board[N][N];
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        board[i][j]=0;
    }
}
if(solveNQutil(board,0)==false)
{
    cout<<"Solution does not exist";
    return false;
}
    printboard(board);
return true;
}
int main()
{
solveNQ();
return 0;
}
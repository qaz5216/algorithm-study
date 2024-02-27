#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>
using namespace std;
int N;
vector<vector<int>>board;
vector<vector<vector<int>>> numcase;
void printSolution(vector<vector<int>> arr)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<<arr[i][j]<<" ";
		cout <<"\n";
	}
}
bool isSafe(int row, int col)
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

// /* A recursive utility function to solve N
//    Queen problem */
void solveNQUtil(int col)
{
	/* base case: If all queens are placed
	  then return true */
	if (col >= N){
        numcase.push_back(board);
		return;
    }

	for (int i = 0; i < N; i++)
	{
		/* Check if the queen can be placed on
		  board[i][col] */
		if (isSafe(i, col))
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			solveNQUtil(col + 1);
			/* If placing queen in board[i][col]
			   doesn't lead to a solution, then
			   remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK 
		}
	}
	/* If the queen cannot be placed in any row in
	   this colum col  then return false */
	return;
}

// /* This function solves the N Queen problem using
//    Backtracking. It mainly uses solveNQUtil() to
//    solve the problem. It returns false if queens
//    cannot be placed, otherwise, return true and
//    prints placement of queens in the form of 1s.
//    Please note that there may be more than one
//    solutions, this function prints one  of the
//    feasible solutions.*/
void solveNQ()
{
    solveNQUtil(0);
	if (numcase.size() == 0)
	{
		cout<<"Solution does not exist";
		return;
	}
    cout << "case num = " << numcase.size()<<"\n"<<endl;
	for(int i=0;i<numcase.size();i++){
    cout << "case "<<i+1<<endl;
    printSolution(numcase[i]);
    cout << "\n";
    }
	return;
}

// // driver program to test above function 
int main()
{
    cout << "insert N" <<endl;
    cin >> N;
    for(int i=0;i<N;i++){
        vector<int> tmp;
        for(int j=0;j<N;j++){
            tmp.push_back(0);
        }
        board.push_back(tmp);
    }
    clock_t start,end;
    double result;
    start=clock();
	solveNQ();
    end=clock();
    result=(double)(end-start);
    cout << "time: "<<result<<" ms"<<endl;
    cout << "want exit press any key"<<endl;
    getch();
	return 0;
}

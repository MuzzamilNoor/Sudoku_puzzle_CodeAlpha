#include <iostream>
using namespace std;

const int N = 6;

bool isSafe(int grid[N][N], int row, int col, int num) {

	for (int x = 0; x < N; x++) {
		if (grid[row][x] == num || grid[x][col] == num) {
			return false;
		}
	}

	return true;
}
bool findEmptyLocation(int grid[N][N], int& row, int& col) {
	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (grid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}
bool isfull(int grid[N][N])
{
	int row, col;
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (grid[row][col] == 0)
			{
				return false;
			}

		}
	}
	return true;

}

void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

bool solveSudokupuzzle(int grid[N][N]) {
	int row = 0, col = 0;

	while (true)
	{
		if (!findEmptyLocation(grid, row, col))
		{
			return true;
		}
		cout << "Enter the number (1 - 6) for row " << row + 1 << " and column " << col + 1 << ": ";
		int num;
		cin >> num;

		if (num < 1 || num > 6 || !isSafe(grid, row, col, num))
		{
			cout << "Number entered at INVALID position..." << endl;
			return false;
		}

		grid[row][col] = num;
		printGrid(grid);
		cout << endl;
		if (solveSudokupuzzle(grid)) {
			return true;
		}

		grid[row][col] = 0;
		return false;
	}
}

int main()
{
	//--------------------SUDOKU PUZZLE
	int Sudokugrid4[N][N]{
	{1, 0, 0, 4},
	{0, 0, 1, 0},
	{2, 0, 0, 1},
	{0, 1, 0, 0}
	};
	//You can play puzzle of 9*9 with simply changing N value 

	int grid[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	//You can play puzzle of 6*6 with simply changing N value 

	int sudokuGrid[6][6] = {
	   {1, 0, 0, 4, 5, 0},
	   {0, 0, 0, 0, 0, 3},
	   {0, 5, 0, 6, 0, 0},
	   {0, 0, 1, 0, 4, 0},
	   {3, 0, 0, 0, 0, 6},
	   {0, 4, 6, 0, 0, 0}
	};
	cout << "                           *************************************" << endl;
	cout << "                                 WELCOME TO SUDOKU PUZZLE" << endl;
	cout << "                           *************************************" << endl << endl;

	printGrid(Sudokugrid4);
	cout << endl;

	cout << "Lets Slove the Sudoku Puzzle of Grid 4*4" << endl << endl;
	if (solveSudokupuzzle(Sudokugrid4) == true)
	{
		cout << "                               **************************" << endl;
		cout << "                                     CONGRATULATION" << endl;
		cout << "                               **************************" << endl << endl;
		cout << "Solved Sudoku Grid:" << endl;
		cout << "-------------------" << endl;
		printGrid(Sudokugrid4);

	}
	//Here I use this state because im not using any kind of timer in which it task
	//must be complete so if you enter any wronge number in wrong position your game will end
	else {
		cout << "\n                                   *********************" << endl;
		cout << "                                         GAME OVER" << endl;
		cout << "                                   *********************" << endl << endl;

	}

}

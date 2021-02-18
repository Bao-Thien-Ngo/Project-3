#include <iostream>
#include <vector>
using namespace std;

//declaring function to multiple two matrixes
vector<vector<int> > combine(vector<vector<int> > matrix1, vector<vector<int> > matrix2);

int main() {

	//grid 1
	bool x = true;
	while (x == true) {
		char option;

		//grid 1
		int rows_1; //declaring row
		int columns_1; // declaring columns;
		cout << "Enter the number of rows in the first matrix >>> "; //ask the number of row for matrix 1
		cin >> rows_1;
		cout << endl;
		cout << "Enter the number of columns in the first matrix >>> "; //ask the number of column for matrix 1
		cin >> columns_1;
		cout << endl;
		cout << "Please enter the value in this matrix, you can enter each row at once, each cell or all of them seperated by space" << endl;

		// creating a vector of vector with size equal to row 1 (I just learned from the internet, so please check that)
		vector<vector<int> > matrix1(rows_1);

		//for loop that asking the user to input value for the matrix1
		for (int i = 0; i < rows_1; i++) {
			matrix1.at(i).resize(columns_1);
			for (int j = 0; j < columns_1; j++) {
				cin >> matrix1[i][j];
			}
		}

		cout << "You entered the grid 1 as" << endl;

		//for loop that outputting the values for the matrix1
		for (int i = 0; i < rows_1; i++) {
			matrix1.at(i).resize(columns_1);
			for (int j = 0; j < columns_1; j++) {
				cout << matrix1[i][j];
				cout << " ";
			}
			cout << endl;
		}

		cout << endl;
		//grid 2

		int rows_2; //declaring row
		int columns_2; // declaring columns;
		cout << "Enter the number of rows in the second matrix >>> "; //ask the number of row for matrix 2
		cin >> rows_2;
		cout << endl;
		cout << "Enter the number of columns in the second matrix >>> "; //ask the number of column for matrix 2
		cin >> columns_2;
		cout << endl;
		cout << "Please enter the value in this matrix, you can enter each row at once, each cell or all of them seperated by space" << endl;

		// creating a vector of vector with size equal to row 2 (I just learned from the internet, so please check that)
		vector<vector<int> > matrix2(rows_2);

		//for loop that asking the user to input value for the matrix1
		for (int i = 0; i < rows_2; i++) {
			matrix2.at(i).resize(columns_2);
			for (int j = 0; j < columns_2; j++) {
				cin >> matrix2[i][j];

			}
		}

		cout << "You entered the grid 2 as" << endl;

		//for loop that outputting the values for the matrix2
		for (int i = 0; i < rows_2; i++) {
			matrix2.at(i).resize(columns_2);
			for (int j = 0; j < columns_2; j++) {
				cout << matrix2[i][j];
				cout << " ";
			}
			cout << endl;
		}

		cout << endl;

		//add two matrixes together if they have the same row and column
		if (rows_1 == rows_2 && columns_1 == columns_2) {
			cout << "g1 + g2 is" << endl;
			for (int i = 0; i < rows_1; i++) {
				matrix1[i].resize(columns_1);
				for (int j = 0; j < columns_1; j++) {
					cout << matrix1[i][j] + matrix2[i][j];
					cout << " ";
				}
				cout << endl;
			}
		}
		// Otherwise output a statement that you cannot add the rows and columns together
		else {
			cout << "Cannot add 2 grids of this size together" << endl;;
		}

		//Multiple two matrixes
		if (columns_1 == rows_2) {
			vector<vector<int> > matrix3 = combine(matrix1, matrix2);
			cout << "g1 * g2 is" << endl;
			for (int i = 0; i < rows_1; i++) {
				for (int j = 0; j < columns_2; j++) {
					cout << matrix3[i][j];
					cout << " ";
				}
				cout << endl;
			}
		}
		// Otherwise output a statement that you cannot multiple the rows and columns together
		else {
			cout << "Cannot multiple 2 grids together" << endl;
		}

		cout << "Press Q to exit ,any other key to do another grid" << endl;
		cin >> option;
		option = toupper(option);
		switch (option) {
		case 'Q':
			x = false;
			break;
		default:
			x = true;
			break;
		}
	}

	system("pause");
	return 0;

}

// function to multiple two matrixes
vector<vector<int> > combine(vector<vector<int> > matrix1, vector<vector<int> > matrix2) {
	vector<vector<int> > matrix3;
	for (int i = 0; i < matrix1.size(); i++) {
		vector<int> matrix_4; //matrix4 is used to strore each value in matrix3
		for (int j = 0; j < matrix2[0].size(); j++) {
			int sum = 0;
			for (int g = 0; g < matrix2.size(); g++) {
				sum += matrix1[i][g] * matrix2[g][j];
			}
			matrix_4.push_back(sum); // add each value to matrix4
		}
		matrix3.push_back(matrix_4);// add value from matrix 4 back to matrix3
	}
	return matrix3;
}

/*
cout << endl;
		//multiplication two matrixes
		vector<vector<int> > multiplication;
		if (columns_1 == rows_2) {
			cout << "g1 * g2 is" << endl;
			for (int i = 0; i < matrix1.size(); i++) {
				vector<int> matrix_3;
				for (int j = 0; j < matrix2[0].size(); j++) {
					int sum = 0;
					for (int g = 0; g < matrix2.size(); g++) {
						sum += matrix1[i][g] * matrix2[g][j];
					}
					matrix_3.push_back(sum);
				}
				multiplication.push_back(matrix_3);
			}
		}
		// Otherwise output a statement that you cannot add the rows and columns together
		else {
			cout << "Cannot multiple two matrixes" << endl;;
		}
*/
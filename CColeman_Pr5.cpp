#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int array1[], int array2[], int array3[]);
bool checkRange(int array1[], int array2[], int array3[]);
bool checkUnique(int array1[], int array2[], int array3[]);
bool checkRowSum(int array1[], int array2[], int array[]);
bool checkColSum(int array1[], int array2[], int array3[]);
bool checkDiagSum(int array1[], int array2[], int array3[]);
void fillArray(int array1[], int array2[], int array3[]);
void showArray(int array1[], int array2[], int array3[]);

int main()
{

	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding         to each row of the grid */
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	// Your code goes here
	char choice;
	do {
		fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3);

		showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3);
		cout << "\n";
		bool isMgcSqr = isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3);

		if (isMgcSqr == true) {
			cout << "This is a Lo Shu Magic Square.";
			break;
		}
		else {
			cout << "This is not a Lo Shu Magic Square." << endl;
			cout << "Do you wish to try again (y/n)? ";
			cin >> choice;
			cout << "\n";

		}
	} while (choice == 'y');

	return 0;
}
// Function definitions go here

bool checkDiagSum(int array1[], int array2[], int array3[]) {
	int val1 = array1[0] + array2[1] + array3[2];
	int val2 = array3[0] + array2[1] + array1[2];
	bool isGood = false;

	if (val1 == val2) {
		isGood = true;
	}

	return isGood;
}

bool checkColSum(int array1[], int array2[], int array3[]) {
	int val1 = array1[0] + array2[0] + array3[0];
	int val2 = array1[1] + array2[1] + array3[1];
	int val3 = array1[2] + array2[2] + array3[2];
	bool isGood = true;
	if ((val1 != val2) || (val1 != val3) || (val3 != val2)) {
		isGood = false;
	}
	return isGood;
}

bool checkRowSum(int array1[], int array2[], int array3[]) {
	int val1 = array1[0] + array1[1] + array1[2];
	int val2 = array2[0] + array2[1] + array3[2];
	int val3 = array3[0] + array3[1] + array3[2];
	bool isGood = false;

	if ((val1 != val2) || (val1 != val3) || (val3 != val2)) {
		isGood = true;
	}
	return isGood;
}

bool checkUnique(int array1[], int array2[], int array3[]) {
	bool isUnique = true;

	if (array1[0] == array1[1] || array1[0] == array1[2] || array1[0] == array2[0] || array1[0] == array2[1] || array1[0] == array2[2] || array1[0] == array3[0] || array1[0] == array3[1] || array1[0] == array3[2]) {
		isUnique = false;
	}
	if (array1[1] == array1[2] || array1[1] == array2[0] || array1[1] == array2[1] || array1[1] == array2[2] || array1[1] == array3[0] || array1[1] == array3[1] || array1[1] == array3[2]) {
		isUnique = false;
	}
	if (array1[2] == array2[0] || array1[2] == array2[1] || array1[2] == array2[2] || array1[2] == array3[0] || array1[2] == array3[1] || array1[2] == array3[2]) {
		isUnique = false;
	}
	if (array2[0] == array2[1] || array2[0] == array2[2] || array2[0] == array3[0] || array2[0] == array3[1] || array2[0] == array3[2]) {
		isUnique = false;
	}
	if (array2[1] == array2[2] || array2[1] == array3[0] || array2[1] == array3[1] || array2[1] == array3[2]) {
		isUnique = false;
	}
	if (array2[2] == array3[0] || array2[2] == array3[1] || array2[2] == array3[2]) {
		isUnique = false;
	}
	if ( array3[0] == array3[1] || array3[0] == array3[2]) {
		isUnique = false;
	}
	if (array3[1] == array3[2]) {
		isUnique = false;
	}

	return isUnique;
}

bool checkRange(int array1[], int array2[], int array3[]) {
	bool inRange = true;
	for (int b = 0; b <= 2; b++) {
		if(array1[b] > MAX || array1[b] < MIN) {
			inRange = false;
		}
		if (array2[b] > MAX || array2[b] < MIN) {
			inRange = false;
		}
		if (array3[b] > MAX || array3[b] < MIN) {
			inRange = false;
		}
	}
	return inRange;
}

void showArray(int array1[], int array2[], int array3[]) {
	cout << array1[0] << " " << array1[1] << " " << array1[2] << endl;
	cout << array2[0] << " " << array2[1] << " " << array2[2] << endl;
	cout << array3[0] << " " << array3[1] << " " << array3[2] << endl;
}

void fillArray(int array1[], int array2[], int array3[]) {
	for (int a = 1; a <= ROWS; a++) {
		
		for (int b = 0; b <= 2; b++) {
			cout << "Enter the # for row " << a << " and column " << b + 1 << ": ";
			if (a == 1) {
				cin >> array1[b];
			}
			if (a == 2) {
				cin >> array2[b];
			}
			if (a == 3) {
				cin >> array3[b];
			}
		}
		cout << "\n";
	}
}

bool isMagicSquare(int array1[], int array2[], int array3[]) {
	bool inRange = checkRange(array1, array2, array3);
	bool isUnique = checkUnique(array1, array2, array3);
	bool rowSum = checkRowSum(array1, array2, array3);
	bool colSum = checkRowSum(array1, array2, array3);
	bool diagSum = checkDiagSum(array1, array2, array3);
	bool magicSquare;
	
	if (inRange == true && isUnique == true && rowSum == true && colSum == true && diagSum == true) {
		magicSquare = true;
	}
	else {
		magicSquare = false;
	}
	return magicSquare;
}
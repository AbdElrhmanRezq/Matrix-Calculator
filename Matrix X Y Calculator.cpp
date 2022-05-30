#include<iostream>
#include<cmath>
using namespace std;
bool entered = false;
int matAx = 1, matAy = 1;
int matBx = 1, matBy = 1;
int matA[10][10], matB[10][10];
int signs[10][10];


void signer(int signs[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0)
				signs[i][j] = 1;
			else
				signs[i][j] = -1;
		}
	}
}
void displayer(int mat[][10], int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}
void displayerD(long double mat[][10], int x, int y) { 
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

//Abandoned function of getting 3*3 matrix

int mat3X(int mat[][10]) {
	int sum = (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]))
		- (mat[1][0] * (mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]))
		+ (mat[2][0] * (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]));
	return sum;
}

//This function gets the det of 2*2 Matrix

int mat2X(int mat[][10]) {
	int sum = (mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
	return sum;
}

//Recusrsion Part

long long smallmat(int mat[][10], int x, int y, int r) {
	int x1 = 0, y1 = 0;
	long long sum = 0;
	int newmat[10][10];
	for (int i = 0; i < x; i++) {
		y1 = 0;
		for (int j = 0; j < y; j++) {
			if (i == r || j == 0) {
				continue;
			}
			else {
				newmat[x1][y1] = mat[i][j];
				y1++;
			}
		}
		if(i!=r)x1++;
	}
	if (x1 > 2) {
		for (int i = 0; i < x1 ; i++) {
			sum+=(newmat[i][0] * smallmat(newmat, x1, x1, i) *signs[i][0]); 
		}
	}
	else {
		return mat2X(newmat);
	}
	return sum;
}
//Initiating Determinant
long long det (int matA[][10], int matAx, int matAy) {
	long long sum = 0;
	if(matAx!=matAy)
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
		if (matAx == 2) { cout << mat2X(matA)<<endl;}
		else if (matAx == 1) { cout << matA[0][0] << endl; }
		else {
			for (int i = 0; i < matAx; i++) {
				sum += (matA[i][0] * (smallmat(matA, matAx, matAy, i)) * signs[i][0]);
			}
		}
	}
	return sum;
}
void divider(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy);
void inverse(int matB[][10], int matBx, int matN[][10]); 
long long SmallDets(int matB[][10], int matBx, int a, int b);
void multiD(int matA[][10], int matAx, int matAy, long double matB[][10], int matBx, int matBy); 
void divider2(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy);
void divider1(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy);
//Multiplier
void multi(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy) {
	if(!(matAy==matBx))
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
		//New mat to store
		int matN[10][10];
		//For loop counts rows
		//For loop counts columns
		//First row in the new mat 3*3-> (1,1)(1,1) & (1,2)(2,1)  & (1,3)(3,1) - (1,1)(2,1) & (1,2)
		for (int i = 0; i < matAx; i++) {
			for (int j = 0; j < matBy; j++) {
				int sum = 0;
				for (int k = 0; k < matAy; k++) {
					sum += (matA[i][k] * matB[k][j]);
				}
				matN[i][j] = sum;
			}
		}
		displayer(matN, matAx, matBy);
	}
}
void sub(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy) {
	if (matAx != matBx || matAy != matBy)
		cout << "The operation you chose is invalid for the given matrices."<<endl;
	else {
		for (int i = 0; i < matAx; i++) {
			for (int j = 0; j < matAy; j++) {
				cout << (matA[i][j] - matB[i][j]) << ' ';
			}
			cout << endl;
		}
	}
}
void sum(int matA[][10], int matAx , int matAy, int matB[][10], int matBx, int matBy) {
	if (matAx != matBx || matAy != matBy)
		cout << "The operation you chose is invalid for the given matrices."<<endl;
	else {
		for (int i = 0; i < matAx; i++) {
			for (int j = 0; j < matAy; j++) {
				cout << (matA[i][j] + matB[i][j]) << ' ';
			}
			cout << endl;
		}
	}
}
void entervalue(int mat[][10], int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> mat[i][j];
		}
	}
}
void calculator() {
	bool working = true;
	while (working) {
		if (entered == false) {
			cout << "Please enter dimensions of Matrix A:"<<endl;
			cin >> matAx >> matAy;
			cout << "Please enter dimensions of Matrix B:"<<endl;
			cin >> matBx >> matBy;
			cout << "Please enter values of Matrix A:"<<endl;
			entervalue(matA, matAx, matAy);
			cout << "Please enter values of Matrix B:"<<endl;
			entervalue(matB, matBx, matBy);
		}
		cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
		entered = true;
		int choice;
		cin >> choice;
		if (choice == 1)
			sum(matA, matAx, matAy, matB, matBx, matBy);
		else if (choice == 2)
			sub(matA, matAx, matAy, matB, matBx, matBy);
		else if (choice == 3)
			multi(matA, matAx, matAy, matB, matBx, matBy);
		else if (choice == 4) {
			if (matBx == 2 && matBy == 2) {
				divider2(matA, matAx, matAy, matB, matBx, matBy);
			}
			else if (matBx==1 && matBy ==1) {
				divider1(matA, matAx, matAy, matB, matBx, matBy);
			}
			else {
				divider(matA, matAx, matAy, matB, matBx, matBy);
			}
		}
		else if (choice == 5)
			det(matA, matAx, matAy);
		else if (choice == 6)
			det(matB, matBx, matBy);		
		else
			working = false;
	}
	cout << "Thank you!"<<endl;
}
int main() { 
	signer(signs);
	calculator();
}
void divider1(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy) {
	if (!(matAy == matBx) || matBx != matBy || matB[0][0] == 0)
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
		long double matB1[10][10];
		matB1[0][0] = ((long double)1 / matB[0][0]);
		multiD(matA, matAx, matAy, matB1, 1, 1);
	}
}
void divider2(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy) {
	if (!(matAy == matBx) || matBx != matBy || mat2X(matB) == 0)
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
		long long determinantB = mat2X(matB);
		long double matB2[10][10];
		matB2[0][0] = matB[1][1] / ((long double)determinantB);
		matB2[1][1] = matB[0][0] / ((long double)determinantB);
		matB2[1][0] = (-1) * matB[1][0] / ((long double)determinantB);
		matB2[0][1] = (-1) * matB[0][1] / ((long double)determinantB);
		multiD(matA, matAx, matAy, matB2, 2, 2);
	}
}
void divider(int matA[][10], int matAx, int matAy, int matB[][10], int matBx, int matBy) {
	if (!(matAy == matBx) || matBx!=matBy || det(matB,matBx,matBx) ==0)
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
			int matN[10][10];
			inverse(matB, matBx, matN);	
	}
}
void inverse(int matB[][10], int matBx, int matN[][10]) {
	for (int i = 0; i < matBx; i++) {
		for (int j = 0; j < matBx; j++) {
			matN[i][j] = (signs[i][j] * SmallDets(matB, matBx,i,j));
		}
	}
	//displayer(matN, matBx, matBx);
	long long determinantB = det(matB, matBx, matBx);
	//cout << "determinanteB is " << determinantB << endl;
	long double matBmain[10][10];
	for (int i = 0; i < matBx; i++) {
		for (int j = 0; j < matBx; j++) {
			matBmain[j][i] = (matN[i][j] /(long double) determinantB);
		}
	}
	//displayerD(matBmain,matBx,matBx);
	multiD(matA,matAx,matAy,matBmain,matBx,matBy);
}
long long SmallDets(int matB[][10], int matBx, int a, int b) {
	int x1 = 0, y1 = 0;
	long long sum = 0;
	int newmat[10][10];
	for (int i = 0; i < matBx; i++) {
		y1 = 0;
		for (int j = 0; j < matBx; j++) {
			if (i == a || j == b) {
				continue;
			}
			else {
				newmat[x1][y1] = matB[i][j];
				y1++;
			}
		}
		if (i != a)x1++;
	}
	if (x1 > 2) {
		for (int i = 0; i < x1; i++) {
			sum += (newmat[i][0] * smallmat(newmat, x1, x1, i) * signs[i][0]);
		}
	}
	else {
		return mat2X(newmat);
	}
	return sum;
}
void multiD(int matA[][10], int matAx, int matAy, long double matB[][10], int matBx, int matBy) {
	if (!(matAy == matBx))
		cout << "The operation you chose is invalid for the given matrices." << endl;
	else {
		long double matN[10][10];
		for (int i = 0; i < matAx; i++) {
			for (int j = 0; j < matBy; j++) {
				long double sum = 0;
				for (int k = 0; k < matAy; k++) {
					sum += (matA[i][k] *(double) matB[k][j]);
				}
				matN[i][j] = llround(sum);
			}
		}
		displayerD(matN, matAx, matBy);
	}
}
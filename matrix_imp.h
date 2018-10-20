#ifndef MATRIX_IMP_H_INCLUDED
#define MATRIX_IMP_H_INCLUDED

#include"matrix.h"

//////////////// IMP - Class Matrix///////////////////////

//////////////////////////////////////////////////////////////
//////////////////ctor//////////////////////////////////
/////////////////////////////////////////////////////////////
//default Constructor
template <typename T, int r , int c>
Matrix<T,r,c>::Matrix(){
	defult = 0;
	MyVector<MyVector<T,c> ,r> dmatrix(0);
	matrix = dmatrix ;
}

//Constructor With Value
template <typename T, int r , int c>
Matrix<T,r,c>::Matrix(const T& defVal){
	defult = defVal;
	MyVector<MyVector<T,c> ,r> dmatrix(defult);
	matrix = dmatrix;
}

//Copy Constructor
template <typename T, int r,int c>
Matrix<T,r,c>::Matrix(const Matrix<T,r,c>& Mat_to_Copy){
	if ((Mat_to_Copy.row_num != r) || (Mat_to_Copy.col_num != c)){
		cout << "Matrix Must be the Equal size" << endl;
		exit(0);
	} else {
		defult = Mat_to_Copy.defult;
		matrix = Mat_to_Copy.matrix;
		col_num=Mat_to_Copy.col_num;
		row_num=Mat_to_Copy.row_num;
	}
}

//////////////////////////////////////////////////////////////
//////////////////OPERATORS//////////////////////////////////
/////////////////////////////////////////////////////////////

//print operator <<
template <typename T1, int r1, int c1>
ostream& operator<<(ostream& os, const Matrix<T1, r1, c1>& mat)
{
	for (int i = 0; i < r1; i++)
	{
	    for (int j = 0; j < c1; j++){
            cout << mat[i][j]<<" ";
        }
        cout << endl;
	}
	cout << endl;
	return os;
}

//Operator ()
template <typename T, int r , int c>
T& Matrix<T, r, c>::operator() (int n_row, int n_col){
    return this->matrix(n_row)(n_col);
}

//Operator =
template <typename T, int r , int c>
void Matrix<T,r,c>::operator= (const Matrix<T,r,c>& Matrix1){
    this->matrix = Matrix1.matrix;
    this->col_num = Matrix1.col_num;
    this->row_num = Matrix1.row_num;
    this->defult = Matrix1.defult;
}

//operator * - multiply  Matrix by const number
template<typename T, int r, int c>
Matrix< T, r, c> operator*(T Number, Matrix< T, r, c> mat)
{
	Matrix< T, r, c> Mat_Result;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			Mat_Result(i, j) = Number * mat.matrix[i][j];
		}
	}
	return Mat_Result;
}

//operator ==
template <typename T1, int r1, int c1, int r2, int c2>
bool operator==(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2){
	if (matrix1.row_num != matrix2.row_num || matrix1.col_num != matrix2.col_num)
		return false;
	for(int i=0; i<matrix1.row_num;i++){
		for(int j=0;j<matrix1.col_num;j++){
			if(matrix1[i][j] != matrix2[i][j])
				return false;
		}
	}
	return true;
}

//operator !=
template <typename T1, int r1, int c1, int r2, int c2>
bool operator!=(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2 ){
	return !(matrix1==matrix2);
}

//operator +=
template <typename T, int r, int c>
Matrix<T,r,c>& Matrix<T,r,c>::operator+=(const Matrix<T,r,c>& mat){
	Matrix<T,r,c> mat_res;
	mat_res = *this + mat;
	(*this) = mat_res;
	return *this;
}

//////////////////////////////////////////////////////////////
////////////////functions////////////////////////////////
/////////////////////////////////////////////////////////////
//Sum all the elements in Matrix
template <typename T, int r, int c>
const T Matrix<T,r,c>::sum()const{
    T sum =0;
    for(int i=0; i<r; i++){
		for(int j=0;j<c;j++){
            sum += this->matrix[i][j];
        }
    }
	return sum;
}

//Return the average of the elements in Matrix
template <typename T, int r, int c>
const T Matrix<T,r,c>::avg()const{
	return this->sum()/(r*c);
}

//Return the Min member in Matrix
template <typename T, int r, int c>
const T& Matrix<T,r,c>::min()const{
	T minVal = defult;
	for(int i=0; i<r; i++){
		for(int j=0;j<c;j++){
			if(minVal>this->matrix[i][j]){
				minVal = this->matrix[i][j];
		   }
		}
	}
	return minVal;
}

//min fun
template <typename T, int r, int c>
T min(const Matrix<T,r,c> mat){
	return mat.min();
}

/////////////////////////////////////////////////////////////////////////////
//operator * - multiply  Matrix with Matrix
template <typename T, int r, int c, int r1, int c1>
Matrix<T,r,c1> operator*(const Matrix<T,r,c>& matrix1,const Matrix<T,r1,c1>& matrix2) {
	if(c != r1){ // columns Matrix1 not equal to rows Matrix2
		throw typename Matrix<T,r,c>::IllegalOperation("Matrices multiplication error - sizes mismatch!! \n");
	}
	Matrix<T,r,c1> mat_res;
	int sum=0;
	for(int i =0; i<r; i++){
		for(int j =0; j<c1; j++){
			for(int k =0; k<r; k++){
				sum = sum + matrix1[i][k]*matrix2[k][j];
			}
			mat_res(i,j) = sum;
			sum = 0;
		}
	}
	return mat_res;
}
//operator+ - add matrix to matrix
template <typename T, int r, int c, int r1, int c1>
Matrix<T,r,c1> operator+(const Matrix<T,r,c>& matrix1,const Matrix<T,r1,c1>& matrix2) {
	if(r != r1 || c != c1){
		throw typename Matrix<T,r,c>::IllegalOperation ("Matrices addition error - sizes mismatch!! \n\0");
	}
	Matrix<T,r,c1> mat_res;
	for(int i =0; i<r; i++){
		for(int j =0; j<c1; j++){
			mat_res(i,j) = matrix1[i][j] + matrix2[i][j];
		}
	}
	return mat_res;
}


#endif // MATRIX_IMP_H_INCLUDED

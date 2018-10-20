#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "myVector.h"
#include "matrix_imp.h"

#ifndef Matrix_H_INCLUDED
#define Matrix_H_INCLUDED

using namespace std;

template <typename T, int r, int c>

//////// Matrix Class
class Matrix{
	private:
		T defult;
		int row_num = r;
		int col_num = c;
	protected:
		MyVector<MyVector<T,c>,r> matrix;

	public:
		Matrix();//default constructor
		Matrix(const T& defVal); //Constructor With Value
		Matrix(const Matrix<T, r, c>& Mat_to_Copy); //Copy Constructor

		//operators
		void operator= (const Matrix<T,r,c>& Matrix1); //operator =
		MyVector<T,c> operator[](int index) const {return matrix[index];} //operator []
		virtual T& operator()(int nrow, int ncol); //operator ()
		Matrix<T,r,c>& operator+=(const Matrix<T,r,c>& mat); //operator +=

        template <typename T1, int r1, int c1> friend ostream& operator<<(ostream&, const Matrix< T1, r1, c1>&); //Print operator
		template <typename T1, int r1, int c1> friend Matrix<T1,r1,c1> operator*(T1 number,Matrix<T1,r1,c1> mat); //operator * by const
		template <typename T1, int r1, int c1, int r2, int c2> friend bool operator==(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2);//operator ==
		template <typename T1, int r1, int c1, int r2, int c2> friend bool operator!=(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2);//operator !=
		//other functions
		const T sum()const; //Sum Matrix Function
		const T avg()const; //Avg Matrix Function
		const T& min()const;
		T min(const Matrix<T,r,c> mat); //Min Value Matrix Function

		///// Exception Class
    class IllegalOperation :public std::exception
    {
        private:
            const string errmsg;
        public:
			IllegalOperation(string  const &msg = " ") : errmsg(msg) {}
             virtual const char* what() const throw()
            { return errmsg.c_str(); }
    };
};

 ///////////////// Operators of Matrix Class ///////////////////////
template <typename T1, int r1, int c1, int r2, int c2>
bool operator==(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2);

template <typename T1, int r1, int c1, int r2, int c2>
bool operator!=(const Matrix<T1,r1,c1> matrix1, const Matrix<T1,r2,c2> matrix2);

template <typename T, int r, int c, int r1, int c1>
Matrix<T,r,c1> operator*(const Matrix<T,r,c>& matrix1,const Matrix<T,r1,c1>& matrix2);

template <typename T, int r, int c, int r1, int c1>
Matrix<T,r,c1> operator+(const Matrix<T,r,c>& matrix1,const Matrix<T,r1,c1>& matrix2);

/////////// SymetricMatrix-Class/////////
template<typename T, int Sym_Size>
class SymetricMatrix : public  Matrix< T, Sym_Size, Sym_Size>{
	public:
		SymetricMatrix(T defVal) : Matrix<T,Sym_Size,Sym_Size>(defVal){} //Constructor
		virtual T& operator()(int nrow, int ncol);
};

////////////////IMP - SymetricMatrix//////////////////////////////
        //Operator () SymetricMatrix
template <typename T, int Sym_Size>
T& SymetricMatrix<T, Sym_Size>::operator() (int n_row, int n_col){
    this->matrix(n_col)(n_row);
    return this->matrix(n_row)(n_col);
}

#endif // Matrix_H_INCLUDED

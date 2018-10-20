#include <stdlib.h>

#include "myVector_imp.h"

#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

using namespace std;

template <typename T, int len>

// Class MyVector - Initializing Vector in constant time
class MyVector
{
    private:
		T def;
		T* vec;
		int* from;
		int* to;
		int top;

    public:
		MyVector(T defVal=T(0)); //Constructor
		~MyVector(); //Destructor
		MyVector(const MyVector<T,len>& vec_to_cpy); //Copy Constructor
		//operators
		T& operator[](int i)const;
		T& operator()(int i);
		MyVector& operator=(const MyVector<T,len>& name);
		template <typename T1, int len1> friend ostream& operator<<(ostream& os,const MyVector<T1,len1>& mVec);
};

#endif // MYVECTOR_H_INCLUDED

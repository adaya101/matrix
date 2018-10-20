#ifndef MYVECTOR_IMP_H_INCLUDED
#define MYVECTOR_IMP_H_INCLUDED

#include "myVector.h"

//////////////// IMP ///////////////////////

//Constructor
template <typename T, int len>
MyVector<T,len>::MyVector(T defVal){
	def = defVal;
	top = 0;
	vec = new T[len];
	from = new int[len];
	to = new int[len];
}

//Destructor
template <typename T, int len>
MyVector<T,len>::~MyVector(){
	delete[] vec;
	delete[] from;
	delete[] to;
}

//Copy Constructor
template <typename T, int len>
MyVector<T,len>::MyVector(const MyVector<T,len>& vec_to_cpy){
	def = vec_to_cpy.def;
	top = vec_to_cpy.top;
	vec = new T[len];
	from = new int[len];
	to = new int[len];
	for(int i=0 ; i<len ; i++){
		vec[i] = vec_to_cpy.vec[i];
		from[i]=vec_to_cpy.from[i];
		to[i]=vec_to_cpy.to[i];
	}
}

//////////////////////////////////////////////////////////////
//////////////////OPERATORS//////////////////////////////////
/////////////////////////////////////////////////////////////

//Operator =
template <typename T,int len>
MyVector<T,len>& MyVector<T,len>::operator=(const MyVector<T,len> &name){
    if (this == &name){
		return *this;
    }
    def = name.def;
    top = name.top;
    for(int i=0 ; i<len ; i++){
		vec[i] = name.vec[i];
		from[i]=name.from[i];
		to[i]=name.to[i];
    }
    return *this;
}

//operator [] - read only
template <typename T, int len>
T& MyVector<T,len>::operator[](int index)const{
    if (index >=len){
		cout << "Vector index out of bound []" << endl;
		exit(0);
    }
    if(from[index]>=0 && from[index]< top && to[from[index]]==index){
		return vec[index];
    } else{
        from[index] = top;
        to[top] = index;
        vec[index] = def;
    }
    return vec[index];
}

//operator () - insert
template <typename T, int len>
T& MyVector<T,len>::operator()(int index){
    if (index >= len){
        cout << "Vector index out of bound()" << endl;
        exit(0);
    }
    if(from[index]>=0 && from[index]< top && to[from[index]]==index){
		return vec[index];
    } else{
        from[index] = top;
        to[top] = index;
        vec[index] = def;
        top++;
	}
	return vec[index];
}

// Print Operator <<
template <typename T, int len>
ostream& operator<<(ostream& os, const MyVector<T,len>& mVec ){
	for(int i=0; i<len; i++){
		cout <<" "<< mVec[i];
	}
	cout << endl;
	return os;
}

#endif // MYVECTOR_IMP_H_INCLUDED

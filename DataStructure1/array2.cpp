/*************************************************************************
	> File Name: shunXuBiao2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed  3 Feb 10:35:02 2021
 ************************************************************************/

#include<iostream>
#include<cstring>

using namespace std::cin;
using namespace std::cout;
using namespace std;

template <typename Type> class Vector {
     private:
        int size, length;
        Type *data;             
     public: 
        Vector(int data_size){ 
            size = data_size;
            length = 0;
            data = New Type[size];
        }
        ~Vector(){
            delete [] data;
        }
         bool insert(int loc, Type value){
             if ( loc < 0 || loc > length ){
                 return false;
             }
             if ( loc >= size ){
                 // need to expand the linklist
             }
             for (int i = length; i > loc; i--){
                 data[i] = data[i - 1];
             }
             data[loc] = value;
             length++;
             cout << "Success with insertion"<<endl;
             return true;
         }
         void expand(){
             Type *old_data = data;
             size *= 2;
             data = new Type[size];
             for(int i = 0; i < length; i++){
                 data[i] = old_data[i];
             }
             delete[] old_data;
         }
         bool search( const Type &value ){
             for (int i = 0; i < length; i++){
                 if (data[i] == value){
                     return i;
                 }
             }  
            return false;
             
        
         }
        bool remove(int index){ 
            
        }
};


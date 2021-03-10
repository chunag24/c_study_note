/*************************************************************************
	> File Name: ShunXuBiao.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 Jan 21:55:15 2021
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
using std::cout;
using std::endl;
using std::cin;
template <typename Type> class Vector {
    private: 
        int size, length;
        Type *data;
    public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
     }
            
    ~Vector() {
        delete [] data;
     }
    bool insert(int loc, Type value){
        if ( loc < 0 || loc > length ) {
            cout << "failed" << endl;
            return false;
        }

        if ( length >= size ) {
            // if the length of the list  is greater than the size
            // There is a need to expand 
            expand();
            cout << "expand" << endl;
        }
        // insert the value to loc 
        // moving value backward 
        for (int i = length ; i > loc ; i-- ){
            data[i] = data[i - 1];
        }
        data[loc] = value;
        // increment the length and return true 
        length++;
        cout << "success" << endl;
        return true;
    }

    void expand(){
        Type *old_data = data; // pointing to the address of the existing list
        size = size * 2; // double the list size 
        data = new Type[size];//assigning the list with the expanded size 
        for(int i = 0; i < length ; i++){
             data[i] = old_data[i];
        }
        delete [] old_data;
    
    }
};


int main (){
    Vector<int> a(5);
    int x, c, b;

    cin >> x;
    
    for ( int i = 0; i < x ; i++) {
        cin >> c >> b;
        a.insert(c, b);
    }

    return 0;
}





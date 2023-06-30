
// Name: Your First Name & Last Name
// SSID: Student ID Number
// Assignment #: 2
// Submission Date: DATE_SUBMITTED
//
#ifndef _ITEMS_HPP
#define _ITEMS_HPP
#include <iostream>
#include "BaseItems.h"

template <class T>
class Items : public BaseItems <T> {
public:
    //int ar[5];
    //int* ptr = &ar[0];
    Items <T>() : _number_of_items(0), _items(nullptr) {
     }

    Items <T>(int n, std::initializer_list <T> il) {
        //std::cout << " Paramatrized Constructor\n";
        _number_of_items = n;
        _items = new T[_number_of_items];
    
        std::copy(il.begin(),il.end(), _items);

        
        

        //std::cout << *(il.begin()+_number_of_items);

        /*

        std::cout << "Loop\n";
        for (auto i : il) {
            std::cout << i << std::endl;
            //ptr++;
        }
        */
        
        //std::cout << &il <<std::endl;
        
        
        //std::cout << number_of_items;
    
    }
    Items <T>(const Items <T>& items) {
        std::cout << "Copy Constructor\n";
        _number_of_items = items._number_of_items();
        _items = new T[_number_of_items];
        std::copy(items.begin(), items.end(), _items);
    }
    ~Items <T>() {

        delete[] _items;
    }
    //
    // TODO A2: override all BaseItems virtual functions
 
    //set the value of number of items n, return false if n is invalid size
    virtual bool update_number_of_items(int n) override;


    // return true if number of items is zero
    virtual bool empty() override;;

    // returns the number of items
    virtual int number_of_items() override;
    virtual T* begin() override;
    virtual T* end() override;
    // For a BaseItems object b, the expression
    // b.front () is equivalent to *b.begin(), undefined if empty()
    virtual T& front() override;
    // For a non -empty BaseItems object b, the expression
    // b.back() is equivalent to *std::prev(b.end()), undefined if empty
    virtual T& back() override;
    // std:: out_of_range exception thrown if !( position < number_of_items ()).
    virtual T& at(int position) override;
    // If number_of_items () is 0, items() may or may not return a null pointer.
    virtual T* items() override;
    virtual const T* items() const override;
    // return Reference to the requested element.
    virtual T& operator [] (int position) override;
    


private:
    int _number_of_items = 0;
    T* _items = nullptr;
};


//issues with this function
template <class T>
bool Items<T>::update_number_of_items(int n) {
    
        if ( n<= 0)
        {
            return false;
        }
        else
        {
            _number_of_items = n;
            _items = new T[_number_of_items];
            
            return true;
        }
    
}


template <class T>
bool Items<T>::empty() {
    if (_number_of_items == 0){
        true;
    }
    return false;
}

template <class T>
int Items<T>::number_of_items() {
    return _number_of_items;
}

//wrong (?)
template <class T>
T* Items<T>::begin() {
    if (_items == nullptr){
        
        
    }
    //items = &il;
    return _items;
}

template <class T>
T* Items<T>::end() {
    return begin()+_number_of_items;
}

template <class T>
T& Items<T>::front() {
    return *begin();
}

template <class T>
T& Items<T>::back() {
    return *end();
}

class out_of_range{
public:
    out_of_range(const std::string& err)
        : errMsg(err){}
    std::string getError(){return errMsg;}
private:
    std::string errMsg;
};

template <class T>
T& Items<T>::at(int position) {
    try {
        return _items[position];
        if (position > _number_of_items)
            throw out_of_range("out of range");
        }
    catch (out_of_range& rangeError){
        std::cout << "boo";
    }
    //i tried to throw an exception but i cant get it to work sorry professor
}

template <class T>
T* Items<T>::items() {
    return _items;
}

template <class T>
const T* Items<T>::items() const {
    return nullptr;
}

template <class T>
T& Items<T>::operator[](int position) {
    
    return _items[position];
    
}



#endif

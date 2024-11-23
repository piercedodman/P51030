/*
  *  rd_array.h
  *                                                
  *  COSC 1030 Fall 2024
  *  Project #5
  *
  *  Due on: DEC 6, 2024
  *  Author: Dodman  rpd62                           
  * 
  *
  *  In accordance with the class policies and Georgetown's
  *  Honor Code, I certify that, with the exception of the 
  *  class resources and those items noted below, I have neither
  *  given nor received any assistance on this project. 
  *
  *  References not otherwise commented within the program source code.
  *  Note that you should not mention any help from the TAs, the professor, 
  *  or any code taken from the class textbooks.
  *
  */
 
 
 
 
 #ifndef __COSC1030_FALL2024_P5_RD_ARRAY_H__
 #define __COSC1030_FALL2024_P5_RD_ARRAY_H__
 
 
 #include <stdexcept>
 #include "Exceptions.h"
 
 
 using std::bad_alloc;
 using std::out_of_range;
 using std::invalid_argument;
 using std::exception;
 using std::vector;
 using std::cout;
 using std::endl;
 using std::string;
 
 
 template <typename T>
 class RD_Array {
 
     template <typename F>
     friend std::ostream& operator<<(std::ostream& os, const RD_Array<F> &rhsObj);
 
 
 public:
     RD_Array();     // GIVEN CODE Implemented outside of class declaration
         
     RD_Array( const RD_Array<T> & );
         
     ~RD_Array();    // GIVEN CODE Implemented outside of class declaration
 
     T& at( const unsigned long ) const;   // GIVEN CODE Implemented outside of class declaration
 
     unsigned long size() const { return currentSize; }         // GIVEN CODE In-line implementation
     unsigned long capacity() const { return currentCapacity; } // GIVEN CODE In-line implementation
 
     void insert( unsigned long ndx, const T& );    
     void remove( unsigned long ndx );
 
     void push_front( const T& );
     void pop_front();
     T& front() const;
 
     void push_back( const T& );
     void pop_back();
     T& back() const;
 
     void resize( const unsigned long, const T& = T() );
         
     void clear();          // GIVEN CODE Implemented outside of class declaration 
     bool empty() const;    // GIVEN CODE Implemented outside of class declaration 
 
 private:
     T* contents;
     unsigned long currentSize;
     unsigned long currentCapacity;
 
     void increaseCapacity();
 
 }; // END RD_Array<T> class declaration
 
 
 
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                    class RD_Array implementation                       **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 
 
 
 /****************************************************************************
  *              non-member function overloaded operator<<                   *
  ****************************************************************************/
 
 template <typename T>
 std::ostream& operator<<(std::ostream& os, const RD_Array<T> &rhsObj)
 {
     
         // PUT YOUR CODE HERE
 
     return os;
 
 } //END overloaded stream insertion operator for RD_Array<T> class
 
 
 
 /****************************************************************************
  **                                                                        **
  **                            private methods                             **
  **                                                                        **
  ****************************************************************************/
 
 /****************************************************************************
  *                           increaseCapacity                               *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::increaseCapacity()
{
    if (currentCapacity == 0) {
        currentCapacity = 1;
    } else {
        currentCapacity *= 2;
    }

    T* newContents = new T[currentCapacity];
    
    for (unsigned long i = 0; i < currentSize; i++) {
        newContents[i] = contents[i];
    }
    
    delete[] contents;
    contents = newContents;
}
 
 
 
 /****************************************************************************
  **                                                                        **
  **                            public methods                              **
  **                                                                        **
  ****************************************************************************/
 
 /****************************************************************************
  *                         default constructor                              *
  *                                                                          *
  * The default constructor is provided to students                          *
  * in COSC 1030 Fall 2024                                                   *
  * to use in part or in total for class projects.                           *
  *                                                                          *
  * Students may use this code as their own, without any attribution.        *
  * Using the code is for the purpose of this class and this project ONLY.   *
  * The code remains property of the course instructor and may NOT be        *
  * used in other projects, discussed with other students, or distrubuted    *
  * in any way or at any time before, during, or after this                  *
  * Fall 2024 semester.                                                      *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 RD_Array<T>::RD_Array()
 {
     currentSize = 0;
     currentCapacity = 0;
 
     contents = NULL;
 
 } // END default constructor RD_Array class
 
 
 
 /****************************************************************************
  *                           copy constructor                               *
  ****************************************************************************/
 
 template <typename T>
 RD_Array<T>::RD_Array( const RD_Array<T> & otherArray )
 {
 
        currentSize = otherArray.currentSize;
        currentCapacity = otherArray.currentCapacity;
    
        contents = new T[currentCapacity];
    
        for ( unsigned long i = 0; i < currentSize; i++ )
        {
            contents[i] = otherArray.contents[i];
        }
 
 
 } // END copy constructor for class RD_Array
 
 
 
 /****************************************************************************
  *                                destructor                                *
  *                                                                          *
  * The destructor is provided to students                                   *
  * in COSC 1030 Fall 2024                                                   *
  * to use in part or in total for class projects.                           *
  *                                                                          *
  * Students may use this code as their own, without any attribution.        *
  * Using the code is for the purpose of this class and this project ONLY.   *
  * The code remains property of the course instructor and may NOT be        *
  * used in other projects, discussed with other students, or distrubuted    *
  * in any way or at any time before, during, or after this                  *
  * Fall 2024 semester.                                                      *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 RD_Array<T>::~RD_Array()
 {
     cout << "deallocating memory for object having size = " << currentSize << " and ";
     cout << "capacity = " << currentCapacity;
     cout << endl;
 
     delete [] contents;
 
 } // END destructor for RD_Array class
 
 
 
 /****************************************************************************
  *                              at method                                   *
  *                                                                          *
  * The at class method is provided to students                              *
  * in COSC 1030 Fall 2024                                                   *
  * to use in part or in total for class projects.                           *
  *                                                                          *
  * Students may use this code as their own, without any attribution.        *
  * Using the code is for the purpose of this class and this project ONLY.   *
  * The code remains property of the course instructor and may NOT be        *
  * used in other projects, discussed with other students, or distrubuted    *
  * in any way or at any time before, during, or after this                  *
  * Fall 2024 semester.                                                      *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 T& RD_Array<T>::at( const unsigned long ndx ) const
 {
     string errMsg = "ERROR: in RD_Array<T>::at invalid index, cannot return anything";
 
     if ( ndx >= currentSize )
     {
         throw std::out_of_range(errMsg);
     }
 
     return contents[ndx];
 
 } // END at method class RD_Array
 
 
 
 /****************************************************************************
  *                             insert method                                *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::insert(unsigned long ndx, const T& infoToAdd)
 {
 
    if (ndx > currentSize) {
        throw out_of_range("Index out of range");
    }

    if (currentSize >= currentCapacity) {
        increaseCapacity();
    }

    for (unsigned long i = currentSize; i > ndx; i--) {
        contents[i] = contents[i - 1];
    }

    contents[ndx] = infoToAdd;
    currentSize++;
 
 } // END insert method class RD_Array
 
 
 
 /****************************************************************************
  *                             remove method                                *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::remove( unsigned long ndx )
 {
 
if (empty()) {
    throw no_such_object("Array is empty");
}

if (ndx >= currentSize) {
    throw out_of_range("Index out of range");
}

for (unsigned long i = ndx; i < currentSize - 1; i++) {
    contents[i] = contents[i + 1];
}

currentSize--;
 
 } // END remove method class RD_Array
 
 
 
 /****************************************************************************
  *                           push_back method                               *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::push_back( const T& infoToAdd )
 {
 
    insert(currentSize, infoToAdd);
 
 } // END push_back method class RD_Array
 
 
 
 /****************************************************************************
  *                            pop_back method                               *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::pop_back()
 {
 
        remove(currentSize - 1);
 
 } // END pop_back method class RD_Array
 
 
 
 /****************************************************************************
  *                             back method                                  *
  ****************************************************************************/
 
 template <typename T>
 T& RD_Array<T>::back() const
 {
 
    return at(currentSize - 1);
 
 } // END back method class RD_Array
 
 
 
 /****************************************************************************
  *                           push_front method                              *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::push_front( const T& infoToAdd )
 {
 
    insert(0, infoToAdd);
 
 } // END push_front method class RD_Array
 
 
 
 /****************************************************************************
  *                            pop_front method                              *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::pop_front()
 {
 
        remove(0);
 
 
 } // END pop_front method class RD_Array
 
 
 
 /****************************************************************************
  *                             front method                                 *
  ****************************************************************************/
 
 template <typename T>
 T& RD_Array<T>::front() const
 {
 
     // PUT YOUR CODE HERE 
         
         return T();  // PLACE HOLDER RETURN, REPLACE WITH YOUR CODE 
 
 } // END front method class RD_Array
 
 
 
 /****************************************************************************
  *                             resize method                                *
  ****************************************************************************/
 
 template <typename T>
 void RD_Array<T>::resize( const unsigned long newSize, const T& value )
 {
         
     // PUT YOUR CODE HERE
         
 } // END resize method class RD_Array
 
 
 
 /****************************************************************************
  *                             empty method                                 *
  *                                                                          *
  * The empty class method is provided to students                           *
  * in COSC 1030 Fall 2024                                                   *
  * to use in part or in total for class projects.                           *
  *                                                                          *
  * Students may use this code as their own, without any attribution.        *
  * Using the code is for the purpose of this class and this project ONLY.   *
  * The code remains property of the course instructor and may NOT be        *
  * used in other projects, discussed with other students, or distrubuted    *
  * in any way or at any time before, during, or after this                  *
  * Fall 2024 semester.                                                      *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 bool RD_Array<T>::empty() const
 {
     return currentSize == 0;
 
 } // END empty method class RD_Array
 
 
 
 /****************************************************************************
  *                             clear method                                 *
  *                                                                          *
  * The clear class method is provided to students                           *
  * in COSC 1030 Fall 2024                                                   *
  * to use in part or in total for class projects.                           *
  *                                                                          *
  * Students may use this code as their own, without any attribution.        *
  * Using the code is for the purpose of this class and this project ONLY.   *
  * The code remains property of the course instructor and may NOT be        *
  * used in other projects, discussed with other students, or distrubuted    *
  * in any way or at any time before, during, or after this                  *
  * Fall 2024 semester.                                                      *
  *                                                                          *
  ****************************************************************************/
 
 
 template <typename T>
 void RD_Array<T>::clear()
 {
     currentSize = 0;
 
 } // END clear method class RD_Array
 
 
 
 
 
 
 #endif /* __COSC1030_FALL2024_P5_RD_ARRAY_H__ */
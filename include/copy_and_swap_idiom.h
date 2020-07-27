#include <iostream>
#include <sstream> // for stringstream. to_string alternative for Win/MinGW
#include <cstddef> // std::size_t
#include "debugmacro.h"

class Array{
//private:
public:
    std::string name;
    std::size_t len;
    int *array;

    /* Parametrized C'tor */
    Array(std::size_t n=0, const std::string naming="unknown") :
            name(naming),
            len(n),
            array(n? new int [n] : nullptr)
    {
        DEBUG_MSG("Array "+ name + " -- Parametrized C'tor called");
    }

    /* Copy C'tor */
    Array(const Array &other) noexcept: 
            name(other.name),
            len(other.len),
            array(other.len? new int [other.len] : nullptr)
    {
        DEBUG_MSG("Array "+ name + " -- Copy C'tor called");
        for (size_t i=0; i<len; i++){
            array[i] = other.array[i];
        }
    }

    /* Move C'tor */
    Array(Array &&other) noexcept : Array()
    {
        DEBUG_MSG("Array "+ name + " -- Move C'tor called");
        swap(*this, other);
        //std::swap(this->name, other.name);
        DEBUG_MSG("Array "+ other.name + " -- getting destroyed");
    }

    //Array & operator =(const Array &other) = delete;
    //Array & operator =(Array &&other) = delete;
    Array & operator =(Array other /* Copy */){
        /* and Swap */
        DEBUG_MSG("Array "+ name + " -- Combined Assignment operator called");
        swap(*this, other);
        return *this;
    }

    friend Array operator +(Array first, const Array &second){
        DEBUG_MSG("Adding Array "+ first.name + " + Array " + second.name);
        for (size_t i=0; i<first.len && i<second.len; i++){
            first.array[i] += second.array[i];
        }
        first.name += "+"+second.name;
        return first;
    }

    friend Array operator +(Array ans, const int a){
        DEBUG_MSG("Adding Array "+ ans.name + " + integer " << a);
        for (size_t i=0; i<ans.len; i++){
            ans.array[i] += a;
        }
        std::stringstream ss;
        ss << a;
        std::string mystr = ss.str();
        ans.name += ("+" + mystr);
        return ans;
    }

    ~Array(){
        DEBUG_MSG("Array "+ name + " -- D'tor called");
        delete [] array;
    }

    friend void swap(Array &first, Array &second){
        DEBUG_MSG("Array Swap called -- swapping '"+first.name+"' and '"+second.name+"'");
        std::swap(first.name, second.name);
        std::swap(first.len, second.len);
        std::swap(first.array, second.array);
    }
};

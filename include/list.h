#pragma once

#include<iostream>
#include"debugmacro.h"

/******************************************************************************/
//! \brief Class defining a singly-linked linked list.
template <typename T>
class List {
    public:

        /** Class methods. */

        //! \brief Constructor for List object.
        List();

        //! \brief Copy Constructor for List object.
        List(const List &);

        //! \brief Move Constructor for List object.
        List(List &&);

        //! \brief Destructor for List object.
        ~List();

        /** Overloaded operators for the class. */

        //! \brief assignment operator.
        List & operator =(List);

        /** Friend functions. */

        //! \brief Displays the linked list.
        template <typename S>
        friend std::ostream& operator<<(std::ostream& os, const List<S> &);

        //! \brief Swap function.
        template <typename S>
        friend void swap(List<S> &, List<S> &);

    /**************************************************************************/
    private:

        //! \brief Struct defining a single node in a singly-linked linked list.
        struct Node {
            Node *next;
            T data;

            /** Struct methods. */

            //! \brief Parametrized Constructor.
            Node(Node *n=nullptr, const T& d=T());
            //Node(Node *n=nullptr, T d=T()) next(n), data(d){}

            //! \brief Copy Constructor.
            Node(const Node &) = delete;

            //! \brief Move Constructor.
            Node(Node &&) = delete;

            //! \brief Destructor.
            ~Node() = default;

            //! \brief Delete Copy Assignmet.
            Node & operator=(const Node &) = delete;

            //! \brief Delete Move Assignmet.
            Node & operator=(Node &&) = delete;

            //! \brief Data Getter function.
            T & getdata() {
                DEBUG_MSG("Node:: Getting data");
                return data;
            }
            //! \brief Data Setter function.
            void setdata(T newdata=T()){
                DEBUG_MSG("Node:: Setting data");
                data = newdata;
            }
            //! \brief Next getter function.
            Node* getnext() {
                DEBUG_MSG("Node:: Getting next");
                return next;
            }

            /** Friends. */

            ////! \brief Displays the data in the Node.
            //template <typename S>
            //friend std::ostream& operator<<(std::ostream&, const Node *);
        };

        /**********************************************************************/
        /** List variables */
        Node *head;
        Node *tail; //! Never allocated. Only pointed to.

    public:
        Node *gethead() {
            DEBUG_MSG("List:: Getting head");
            return head;
        };


        //! \brief Insert data at the beginnging/head of the list object.
        void push_top(T newdata=T()){
            DEBUG_MSG("Node:: Inserting a node at front with data");
            auto tmp = new Node (head, newdata);
            head = tmp;
            if (tail==nullptr) tail = tmp;
        }

        //! \brief Insert data at the end/tail of the list object.
        void push_bottom(T newdata=T()){
            DEBUG_MSG("Node:: Inserting a node at end with data");
            auto tmp = new Node (nullptr, newdata);
            if (tail!=nullptr) tail->next = tmp;
            tail = tmp;
            if (head==nullptr) head = tmp;
        }

        //! \brief Remove node from the beginnging/head of the list object.
        void pop_top();

        //! \brief Remove node from the end/tail of the list object.
        void pop_bottom();

        //! \brief Reverse the linked list.
        void reverse();

};

/******************************************************************************/
/******************************************************************************/
/* * * * * * * * * * * * * * * * * * * LIST * * * * * * * * * * * * * * * * * */
/******************************************************************************/
/******************************************************************************/
//! \brief Parametrized constructor.
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr) {
    DEBUG_MSG("List:: Parametrized C'tor called");
}

//! \brief Copy constructor.
template <typename T>
List<T>::List(const List<T> & other) : head(other.head), tail(nullptr)
{
    DEBUG_MSG("List:: Copy C'tor called");
    if (head){
        DEBUG_MSG("List:: Copying the head node");
        head = new List<T>::Node(other.head->next, other.head->data);
        auto *tmp = head;
        while (tmp->next){
            DEBUG_MSG("List:: Copying a node");
            tmp->next=new List<T>::Node(tmp->next->next, tmp->next->data);
            tmp=tmp->next;
        }
        tail=tmp;
        DEBUG_MSG("List:: Finished copying the list");
    }
}

//! \brief Move constructor.
template <typename T>
List<T>::List(List<T> && other) : List()
{
    DEBUG_MSG("List:: Move C'tor called");
    swap(*this, other);
    DEBUG_MSG("List:: Finished swapping");
}

//! \brief Destructor.
template <typename T>
List<T>::~List()
{
    DEBUG_MSG("List:: D'tor called");
    auto tmp = head;
    while (head){
    DEBUG_MSG("List:: Node destroyed");
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

//! \brief Remove node from the beginnging/head of the list object.
template <typename T>
void List<T>::pop_top(){
    DEBUG_MSG("Node:: Removing a node at front of list");
    if (head==nullptr) throw std::runtime_error("Error! Attempted node removal from an empty list");
    if (head==tail){ /* Single node in the linked list */
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else{
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
}

//! \brief Remove node from the end/tail of the list object.
template <typename T>
void List<T>::pop_bottom(){
    DEBUG_MSG("Node:: Removing a node at end of list");
    if (tail==nullptr) throw std::runtime_error("Error! Attempted node removal from an empty list");
    if (tail==head){ /* Single node in the linked list */
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else{
        auto keepMe = head;
        auto deleteMe = head->next;
        while (deleteMe->next){
            keepMe=deleteMe;
            deleteMe = deleteMe->next;
        }
        delete deleteMe;
        tail = keepMe;
        tail->next = nullptr;
    }
}

//! \brief Reverse the linked list.
template <typename T>
void List<T>::reverse(){
    DEBUG_MSG("List:: Reversing the linked list");
    if (head!=nullptr){
        decltype(head) prev = nullptr;
        while (head->next!=nullptr){
            auto tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        head->next = prev;
    }
}


/**********************************************************************/
/** Overloaded Operator. */

//! \brief Displays the linked list.
template <typename T>
List<T> & List<T>::operator=(List<T> other){
    DEBUG_MSG("List:: Assignment operator called");
    swap(*this, other);
    return *this;
}

/**********************************************************************/
/** Friend functions. */

//! \brief Displays the linked list.
template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& ll){
    auto ptr = ll.head;
    os << "[";
    while(ptr){
        os << ptr->data << ", ";
        ptr=ptr->next;
    }
    os << "]";
    return os;
}

//! \brief Swap function for Copy-and-Swap Idiom.
template <typename T>
void swap(List<T> &first, List<T> &second){
    DEBUG_MSG("List:: Swap called");
    using namespace std;
    swap(first.head, second.head);
}

/******************************************************************************/
/******************************************************************************/
/* * * * * * * * * * * * * * * * * * * NODE * * * * * * * * * * * * * * * * * */
/******************************************************************************/
/******************************************************************************/
//! \brief Constructor.
template <typename T>
List<T>::Node :: Node(List<T>::Node *n, const T &d): next(n), data(d) {
    DEBUG_MSG("Node:: Parametrized C'tor called");
}

/**********************************************************************/
/** Friends. */

////! \brief Displays the data in the List<T>::Node.
//template <typename T>
//std::ostream& operator<<(std::ostream& os, typename List<T>::Node node){
//    os << node.getdata();
//    return os;
//}

////! \brief Swap function for Copy-and-Swap Idiom.
//template <typename T>
//void swap(typename List<T>::Node &first, typename List<T>::Node &second){
//    DEBUG_MSG("Swap called");
//    std::swap(first.next, second.next);
//    std::swap(first.data, second.data);
//}
//



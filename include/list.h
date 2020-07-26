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

        //! \brief Insert data at the beginnging/head of the list object.
        void insert_at_front(T newdata=T()){
            DEBUG_MSG("Node:: Inserting a node with data");
            auto tmp = new Node (nullptr, newdata);
            tmp->next = head;
            head = tmp;
        }

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
            Node(Node *n=nullptr, T& d=T());
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
            const T & getdata() const {
                DEBUG_MSG("Node:: Getting data");
                return data;
            }
            //! \brief Data Setter function.
            void setdata(T newdata=T()){
                DEBUG_MSG("Node:: Setting data");
                data = newdata;
            }
            //! \brief Next getter function.
            Node* getnext() const {
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

    public:
        Node *gethead() const {
            DEBUG_MSG("List:: Getting head");
            return head;
        };
};

/******************************************************************************/
/******************************************************************************/
/* * * * * * * * * * * * * * * * * * * LIST * * * * * * * * * * * * * * * * * */
/******************************************************************************/
/******************************************************************************/
//! \brief Parametrized constructor.
template <typename T>
List<T>::List() : head(nullptr){
    DEBUG_MSG("List:: Parametrized C'tor called");
}

//! \brief Copy constructor.
template <typename T>
List<T>::List(const List<T> & other) : head(other.head)
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
List<T>::Node :: Node(List<T>::Node *n, T &d): next(n), data(d) {
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



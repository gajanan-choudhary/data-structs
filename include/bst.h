#pragma once

#include<iostream>
#include"debugmacro.h"
#define BST BinarySearchTree

/******************************************************************************/
//! \brief Class defining a singly-linked binary search tree.
template <typename key_t, typename T>
class BST {
    public:

        /** Class methods. */

        //! \brief Constructor for BST object.
        BST() : root(nullptr) {
            DEBUG_MSG("BST:: Parametrized C'tor called");
        }

        //! \brief Copy Constructor for BST object.
        BST(const BST &other) : BST() {
            DEBUG_MSG("BST:: Copy C'tor called");
            if (other.root){
                DEBUG_MSG("BST:: Copying the root node");
                //root = new BST<key_t, T>::Node(other.root->left, other.root->right, other.root->data);
                root = new Node(*(other.root));
                DEBUG_MSG("BST:: Finished copying the tree");
            }
            else{
                DEBUG_MSG("BST:: other tree appears too be empty. Nothing to be copied.");
            }
        }

        //! \brief Move Constructor for BST object.
        BST(BST &&other) : BST(){
            DEBUG_MSG("BST:: Move C'tor called");
            swap(*this, other);
            DEBUG_MSG("BST:: Finished swapping");
        }

        //! \brief Destructor for BST object.
        ~BST(){
            DEBUG_MSG("BST:: D'tor called");
            delete root;
        }

        /** Overloaded operators for the class. */

        //! \brief assignment operator.
        BST & operator =(BST other){
            DEBUG_MSG("BST:: Assignment operator called");
            swap(*this, other);
            return *this;
        }

        /** Friend functions. */

        //! \brief Displays the binary search tree.
        template <typename key_s, typename S>
        friend std::ostream& operator<<(std::ostream& os, const BST<key_s, S> &);

        //! \brief Displays the data in the Node.
        template <typename key_s, typename S>
        friend std::ostream& operator<<(std::ostream&, const typename BST<key_s, S>::Node *);

        //! \brief Swap function.
        template <typename key_s, typename S>
        friend void swap(BST<key_s, S> &, BST<key_s, S> &);

    /**************************************************************************/
    private:

        //! \brief Struct defining a single node in a singly-linked binary search tree.
        struct Node {
            Node *left;
            Node *right;
            key_t key;
            T data;

            /** Struct methods. */

            //! \brief Parametrized Constructor.
            Node(const key_t &k=key_t(), const T& d=T()):left(nullptr), right(nullptr), key(k), data(d) {
                DEBUG_MSG("Node:: Parametrized c'tor I called");
            }

            //! \brief Parametrized Constructor.
            Node(Node *l=nullptr, Node *r=nullptr, const key_t &k=key_t(), const T& d=T()):left(l), right(r), key(k), data(d) {
                DEBUG_MSG("Node:: Parametrized c'tor II called");
            }

            //! \brief Parametrized Constructor.
            Node(Node *l=nullptr, Node *r=nullptr, key_t&& k=key_t(), T&& d=T()):left(l), right(r), key(std::move(k)), data(std::move(d)) {
                DEBUG_MSG("Node:: Parametrized c'tor III called");
            }

            //! \brief Copy Constructor.
            Node(const Node &other) : left(nullptr), right(nullptr), key(other.key), data(other.data){
                DEBUG_MSG("Node:: Copying node");
                if (other.left!=nullptr) left = new Node(*(other.left));
                if (other.right!=nullptr) right = new Node(*(other.right));
            }

            //! \brief Move Constructor.
            Node(const Node &&other) : Node(){
                DEBUG_MSG("Node:: Moving node");
                swap(*this, other);
            }

            //! \brief Destructor.
            ~Node(){
                DEBUG_MSG("Node:: D'tor called");
                delete left; left = nullptr;
                delete right; right = nullptr;
            }

            //! \brief Assignmet.
            Node & operator=(const Node other){
                DEBUG_MSG("Node:: Combined assignment called");
                swap(*this, other);
                return *this;
            }

            //! \brief Data Getter function.
            T & getdata() {
                DEBUG_MSG("Node:: Getting data");
                return data;
            }
            //! \brief Key Getter function.
            key_t & getkey() {
                DEBUG_MSG("Node:: Getting key");
                return key;
            }
            //! \brief left getter function.
            Node* getleft() {
                DEBUG_MSG("Node:: Getting left");
                return left;
            }
            //! \brief right getter function.
            Node* getright() {
                DEBUG_MSG("Node:: Getting right");
                return right;
            }

            Node* search(const key_t &k) {
                DEBUG_MSG("Node:: Searching subtree for key "<<k);
                if (this!=nullptr){
                    if (this->key < k) return this->left->search(k);
                    else if (this->key > k) return this->right->search(k);
                    else return this;
                }
                return this;
            }

            void insert(const key_t &k, const T&d) {
                //assert(this!=nullptr);
                if (k < this->key){
                    if(this->left!=nullptr){
                        DEBUG_MSG("Node:: Going left");
                        return this->left->insert(k, d);
                    }
                    else{
                        DEBUG_MSG("Node:: Inserting {key, data} = "<<k << ", " << d << " on the left");
                        this->left = new Node(k, d);
                    }
                }
                else if (k > this->key){
                    if(this->right!=nullptr){
                        DEBUG_MSG("Node:: Going right");
                        return this->right->insert(k, d);
                    }
                    else{
                        DEBUG_MSG("Node:: Inserting {key, data} = "<<k << ", " << d << " on the right");
                        this->right = new Node(k, d);
                    }
                }
                else{
                    /* Key already exists. */
                    DEBUG_MSG("Node:: Replacing data in existing key {key, data} = "<<k << ", " << d);
                    this->data = d;
                }
            }

            /** Friends. */

        };

        /**********************************************************************/
        /** BST variables */
        Node *root;

    public:
        Node *getroot() {
            DEBUG_MSG("BST:: Getting root");
            return root;
        };


        //! \brief Binary search.
        Node* search(const key_t &newkey) const {
            DEBUG_MSG("BST:: Searching for node with key " << newkey);
            return root->search(newkey);
        }

        //! \brief Sorted insert.
        void insert(const key_t &newkey=key_t(), const T &newdata=T()){
            DEBUG_MSG("BST:: Inserting node {key, data} = " << newkey << ", "<< newdata);
            if (root==nullptr){
                DEBUG_MSG("BST:: Inserting ROOT node {key, data} = " << newkey << ", "<< newdata);
                root = new Node(newkey, newdata);
            }
            else root->insert(newkey, newdata);
        }

        //! \brief Remove node from the beginnging/root of the list object.
        //void remove();

        //! \brief rebalance the binary search tree.
        //void rebalance();

        //! \brief Operator[]
        Node *operator[](const key_t &k){
            return search(k);
        }

};

/******************************************************************************/
/******************************************************************************/
/* * * * * * * * * * * * * * * * * * * NODE * * * * * * * * * * * * * * * * * */
/******************************************************************************/
/******************************************************************************/

/**********************************************************************/
/** Friends. */

//! \brief Displays the data in the BST<key_t, T>::Node -- in-order traversal.
template <typename key_s, typename S>
std::ostream& operator<<(std::ostream& os, const typename BST<key_s, S>::Node *node){
    /* In-order traversal */
    if (node!=nullptr){
        operator<< <key_s, S>(os, node->left);
        os << node->data << ", ";
        operator<< <key_s, S>(os, node->right);
    }
    return os;
}
//! \brief Displays the binary search tree.
template <typename key_s, typename S>
std::ostream& operator<<(std::ostream& os, const BST<key_s, S>& bst){
    os << "[";
    operator<< <key_s, S>(os, bst.root);
    os << "]";
    return os;
}


//! \brief Swap function for Copy-and-Swap Idiom.
template <typename key_t, typename T>
void swap(typename BST<key_t, T>::Node &first, typename BST<key_t,T>::Node &second){
    DEBUG_MSG("Swap called");
    std::swap(first.left, second.left);
    std::swap(first.right, second.right);
    std::swap(first.key, second.key);
    std::swap(first.data, second.data);
}

/******************************************************************************/
/******************************************************************************/
/* * * * * * * * * * * * * * * * * * * LIST * * * * * * * * * * * * * * * * * */
/******************************************************************************/
/******************************************************************************/

/**********************************************************************/
/** Friend functions. */

//! \brief Swap function for Copy-and-Swap Idiom.
template <typename key_t, typename T>
void swap(BST<key_t, T> &first, BST<key_t, T> &second){
    DEBUG_MSG("BST:: Swap called");
    using namespace std;
    swap(first.root, second.root);
}


/******************************************************************************/
////! \brief Remove node from the beginnging/root of the list object.
//template <typename key_t, typename T>
//void BST<key_t, T>::remove(){
//    DEBUG_MSG("Node:: Removing a node at front of list");
//    if (root==nullptr) throw std::runtime_error("Error! Attempted node removal from an empty list");
//    if (root==tail){ /* Single node in the binary search tree */
//        delete tail;
//        root = nullptr;
//        tail = nullptr;
//    }
//    else{
//        auto tmp = root;
//        root = root->left;
//        delete tmp;
//    }
//}

////! \brief Rebalance the binary search tree.
//template <typename key_t, typename T>
//void BST<key_t, T>::rebalance(){
//    DEBUG_MSG("BST:: Reversing the binary search tree");
//    if (root!=nullptr){
//        decltype(root) prev = nullptr;
//        while (root->left!=nullptr){
//            auto tmp = root->left;
//            root->left = prev;
//            prev = root;
//            root = tmp;
//        }
//        root->left = prev;
//    }
//}


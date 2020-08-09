#include "doctest.h"
#include "bst.h"
using namespace std;

TEST_CASE("Empty BST<int, int>") {
    DEBUG_MSG(endl);
    BST<int, int> u;
    CHECK(u.getroot() == nullptr);
    DEBUG_MSG("Printing BST: "<< u);
    SUBCASE("Copy C'tor") {
        BST<int, int> v = u;
        CHECK(v.getroot() == nullptr);
    }
    SUBCASE("Copy Assignment") {
        BST<int, int> v;
        v = u;
        CHECK(v.getroot() == nullptr);
    }
    SUBCASE("Move C'tor") {
        BST<int, int> v = std::move(u);
        CHECK(v.getroot() == nullptr);
    }
    SUBCASE("Move Assignment") {
        BST<int, int> v;
        v = std::move(u);
        CHECK(v.getroot() == nullptr);
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
    }
    //SUBCASE("Rebalance") {
    //    u.rebalance();
    //}
    CHECK(u.getroot() == nullptr);
}

TEST_CASE("Single-noded BST<int, int>") {
    DEBUG_MSG(endl);
    BST<int, int> u;
    SUBCASE("Insert new node without any arguments."){
        SUBCASE("Insert."){
            u.insert();
        }
        SUBCASE("Insert."){
            u.insert();
        }
    }
    //SUBCASE("Rebalance") {
    //    u.insert();
    //    u.rebalance();
    //}
    CHECK(u.getroot()->getkey() == int());
    CHECK(u.getroot()->getdata() == int());
    CHECK(u.getroot()->getleft() == nullptr);
    CHECK(u.getroot()->getright() == nullptr);
}

TEST_CASE("Single-noded BST<int, int>") {
    DEBUG_MSG(endl);
    BST<int, int> u;
    u.insert(1,5);
    CHECK(u.getroot()->getkey() == 1);
    CHECK(u.getroot()->getdata() == 5);
    CHECK(u.getroot()->getleft() == nullptr);
    CHECK(u.getroot()->getright() == nullptr);
    DEBUG_MSG("Printing BST: "<< u);

    SUBCASE("Copy C'tor") {
        BST<int, int> v = u;
        CHECK(v.getroot() != u.getroot());
        CHECK(v.getroot()->getkey() == 1);
        CHECK(v.getroot()->getdata() == 5);
        CHECK(v.getroot()->getleft() == nullptr);
        CHECK(v.getroot()->getright() == nullptr);
    }
    SUBCASE("Copy Assignment") {
        BST<int, int> v;
        v = u;
        CHECK(v.getroot() != u.getroot());
        CHECK(v.getroot()->getkey() == 1);
        CHECK(v.getroot()->getdata() == 5);
        CHECK(v.getroot()->getleft() == nullptr);
        CHECK(v.getroot()->getright() == nullptr);
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
    }
    //SUBCASE("Rebalance") {
    //    u.rebalance();
    //}
    CHECK(u.getroot() != nullptr);
    CHECK(u.getroot()->getdata() == 5);
    CHECK(u.getroot()->getleft() == nullptr);
    CHECK(u.getroot()->getright() == nullptr);

    SUBCASE("Move C'tor") {
        BST<int, int> v = std::move(u);
        CHECK(v.getroot() != u.getroot());
        CHECK(v.getroot()->getdata() == 5);
        CHECK(v.getroot()->getleft() == nullptr);
        CHECK(v.getroot()->getright() == nullptr);
        CHECK(u.getroot() == nullptr); // Make sure it moved
    }
    SUBCASE("Move Assignment") {
        BST<int, int> v;
        v = std::move(u);
        CHECK(v.getroot() != u.getroot());
        CHECK(v.getroot()->getdata() == 5);
        CHECK(v.getroot()->getleft() == nullptr);
        CHECK(v.getroot()->getright() == nullptr);
        CHECK(u.getroot() == nullptr); // Make sure it moved
    }
}

//TEST_CASE("BST Operations - BST<int, int>") {
//    DEBUG_MSG(endl);
//    BST<int, int> u;
//    SUBCASE("Exception check - Popping an empty binary search tree"){
//        REQUIRE_THROWS_WITH_AS(u.remove(),
//                "Error! Attempted node removal from an empty binary search tree",
//                const std::runtime_error &);
//    }
//
//    SUBCASE("insert x 4, remove x 4") {
//        int arr[]={141, 12, 342, 4521};
//        for (int i=0; i<4; i++){
//            u.insert(arr[i]);
//            auto tmp=u.getroot();
//            int j = 0;
//            while(tmp){
//                CHECK(tmp->getdata()==arr[i-j]);
//                tmp=tmp->next;
//                j++;
//            }
//            DEBUG_MSG("Printing BST: "<< u);
//        }
//        for (int i=0; i<4; i++){
//            u.remove();
//            auto tmp=u.getroot();
//            int j = 0;
//            while(tmp){
//                CHECK(tmp->getdata()==arr[3-j]);
//                tmp=tmp->next;
//                j++;
//            }
//            DEBUG_MSG("Printing BST: "<< u);
//        }
//    }
//    SUBCASE("insert, insert, insert") {
//        int arr[]={1352, 165, 125};
//        int ans[]={arr[2], arr[0], arr[1]};
//        u.insert(arr[0]);
//        u.insert(arr[1]);
//        u.insert(arr[2]);
//        int j=0;
//        auto tmp=u.getroot();
//        while(tmp){
//            CHECK(tmp->getdata()==ans[j]);
//            tmp=tmp->next;
//            j++;
//        }
//        DEBUG_MSG("Printing BST: "<< u);
//    }
//}

TEST_CASE("Multiple-noded BST<int, int>") {
    DEBUG_MSG(endl);
    BST<int, int> u;
    u.insert(2,5);
    u.insert(1,1);
    u.insert(3,25);
    DEBUG_MSG("Printing BST: "<< u);
    CHECK(u.getroot()->getkey() == 2);
    CHECK(u.getroot()->getdata() == 5);
    CHECK(u.getroot()->getleft() != nullptr);
    CHECK(u.getroot()->getright() != nullptr);
    CHECK(u.getroot()->getleft()->getkey() == 1);
    CHECK(u.getroot()->getleft()->getdata() == 1);
    CHECK(u.getroot()->getright()->getkey() == 3);
    CHECK(u.getroot()->getright()->getdata() == 25);
    CHECK(u.getroot()->getleft()->getleft() == nullptr);
    CHECK(u.getroot()->getleft()->getright() == nullptr);
    CHECK(u.getroot()->getright()->getleft() == nullptr);
    CHECK(u.getroot()->getright()->getright() == nullptr);
    SUBCASE("Overwrite BST by copy assignment") {
        BST<int, int> v;
        v.insert(2140,2140);
        v.insert(7,7);
        u = v;
        CHECK(u.getroot()!=nullptr);
        CHECK(u.getroot()->getdata() == 2140);
        CHECK(u.getroot()->getleft()->getdata() == 7);
        CHECK(u.getroot()->getleft()->getleft() == nullptr);
        CHECK(v.getroot()!=nullptr);
        CHECK(v.getroot()->getdata() == 2140);
        CHECK(v.getroot()->getleft()->getdata() == 7);
        CHECK(v.getroot()->getright() == nullptr);
        CHECK(v.getroot()->getleft()->getright() == nullptr);
        CHECK(v.getroot()->getleft()->getleft() == nullptr);
        DEBUG_MSG("Printing overwritten Binary Search Tree: "<< u);
        /* Make sure the binary search trees are different and copied. */
        CHECK(u.getroot()!=v.getroot());
        CHECK(u.getroot()->getleft()!=v.getroot()->getleft());
        CHECK((u.getroot()+1)!=(v.getroot()+1)); // Tail
    }
    SUBCASE("Overwrite BST by move assignment") {
        BST<int, int> v;
        v.insert(915,915);
        v.insert(5,5);
        v.insert(1405, 1429);
        v.insert(9,9);
        v.insert(92405, 92135);
        v.insert(51905, 51930);
        u = std::move(v);
        CHECK(v.getroot()==nullptr);
        CHECK(u.getroot()!=nullptr);
        CHECK(u.getroot()->getdata() == 915);
        CHECK(u.getroot()->getleft()->getdata() == 5);
        CHECK(u.getroot()->getright()->getdata() == 1429);
        CHECK(u.getroot()->getright()->getright()->getdata() == 92135);
        CHECK(u.getroot()->getright()->getright()->getleft()->getdata() == 51930);
        DEBUG_MSG("Printing overwritten Binary Search Tree: "<< u);
        /* Make sure the binary search trees are different. */
        CHECK(u.getroot()!=v.getroot());
        CHECK((u.getroot()+1)!=(v.getroot()+1)); // Tail
    }
    //SUBCASE("Rebalance the binary search tree"){
    //    u.rebalance();
    //    DEBUG_MSG("Printing rebalanced Binary Search Tree: "<< u);
    //    CHECK(u.getroot()->getdata() == 5);
    //    CHECK(u.getroot()->getleft()->getdata() == 1);
    //    CHECK(u.getroot()->getleft()->getleft()->getdata() == 25);
    //    CHECK(u.getroot()->getleft()->getleft()->getleft() == nullptr);
    //}
}

TEST_CASE("Multiple-noded BST<int, string>") {
    DEBUG_MSG(endl);
    BST<string, string> u;
    //u.insert("b", "b");
    //u.insert("a", "a");
    //u.insert("z", "z");
    u.insert("Templates", "Templates");
    u.insert("are", "are");
    u.insert("beautiful!", "beautiful!");
    DEBUG_MSG("Printing BST: "<< u);
    CHECK(u.getroot()->getdata() == "Templates");
    CHECK(u.getroot()->getright()->getdata() == "are");
    CHECK(u.getroot()->getright()->getright()->getdata() == "beautiful!");
    CHECK(u.getroot()->getleft() == nullptr);
    CHECK(u.getroot()->getright()->getleft() == nullptr);
    CHECK(u.getroot()->getright()->getright()->getleft() == nullptr);
    CHECK(u.getroot()->getright()->getright()->getright() == nullptr);
    SUBCASE("Overwrite BST by copy assignment") {
        BST<string, string> v;
        v.insert("OOP", "OOP");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Binary Search Tree: "<< u);
    }
    SUBCASE("Overwrite BST by move assignment") {
        BST<string, string> v;
        v.insert("world", "world");
        v.insert("o", "o");
        v.insert("l", "l");
        v.insert("l", "l");
        v.insert("e", "e");
        v.insert("H", "H");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Binary Search Tree: "<< u);
    }
}

TEST_CASE("Complex Multiple-noded BST<int, BST<string, string>>") {
    DEBUG_MSG(endl);

    BST<string, string> sentence1;
    sentence1.insert("Hello", "Hello");
    sentence1.insert("world!", "world!");
    CHECK(sentence1.getroot()->getkey() == "Hello");
    CHECK(sentence1.getroot()->getdata() == "Hello");
    CHECK(sentence1.getroot()->getright()->getkey() == "world!");
    CHECK(sentence1.getroot()->getright()->getdata() == "world!");

    decltype(sentence1) sentence2;
    sentence2.insert("OOP", "OOP");
    sentence2.insert("is", "is");
    sentence2.insert("difficult!", "difficult!");
    CHECK(sentence2.getroot()->getkey() == "OOP");
    CHECK(sentence2.getroot()->getdata() == "OOP");
    CHECK(sentence2.getroot()->getright()->getkey() == "is");
    CHECK(sentence2.getroot()->getright()->getdata() == "is");
    CHECK(sentence2.getroot()->getright()->getleft()->getkey() == "difficult!");
    CHECK(sentence2.getroot()->getright()->getleft()->getdata() == "difficult!");

    decltype(sentence1) sentence3;
    sentence3.insert("Templates", "Templates");
    sentence3.insert("are", "are");
    sentence3.insert("beautiful!", "beautiful!");

    BST<int, decltype(sentence1)> u;
    u.insert(2,sentence1);
    u.insert(1,sentence2);
    u.insert(3,sentence3);

    DEBUG_MSG("Printing BST: "<< sentence1);
    DEBUG_MSG("Printing BST: "<< sentence2);
    DEBUG_MSG("Printing BST: "<< sentence3);
    DEBUG_MSG("Printing BST: "<< u);
    auto *tmp = &(u.getroot()->getdata());
    CHECK(tmp->getroot()->getkey() == "Hello");
    CHECK(tmp->getroot()->getdata() == "Hello");
    CHECK(tmp->getroot()->getright()->getkey() == "world!");
    CHECK(tmp->getroot()->getright()->getdata() == "world!");

    tmp = &(u.getroot()->getleft()->getdata());
    CHECK(tmp->getroot()->getdata() == "OOP");
    CHECK(tmp->getroot()->getright()->getdata() == "is");
    CHECK(tmp->getroot()->getright()->getleft()->getdata() == "difficult!");

    tmp = &(u.getroot()->getright()->getdata());
    CHECK(tmp->getroot()->getdata() == "Templates");
    CHECK(tmp->getroot()->getright()->getdata() == "are");
    CHECK(tmp->getroot()->getright()->getright()->getdata() == "beautiful!");

    //SUBCASE("Rebalance binary-search-tree-of-binary-search-trees."){
    //    u.rebalance();
    //    DEBUG_MSG("Printing rebalanced Binary Search Tree: "<< u);
    //    auto *tmp = &(u.getroot()->getdata());
    //    CHECK(tmp->getroot()->getdata() == "Templates");
    //    CHECK(tmp->getroot()->getleft()->getdata() == "are");
    //    CHECK(tmp->getroot()->getleft()->getleft()->getdata() == "beautiful!");
    //
    //    tmp = &(u.getroot()->getleft()->getdata());
    //    CHECK(tmp->getroot()->getdata() == "OOP");
    //    CHECK(tmp->getroot()->getleft()->getdata() == "is");
    //    CHECK(tmp->getroot()->getleft()->getleft()->getdata() == "difficult!");
    //
    //    tmp = &(u.getroot()->getleft()->getleft()->getdata());
    //    CHECK(tmp->getroot()->getdata() == "Hello");
    //    CHECK(tmp->getroot()->getleft()->getdata() == "world!");
    //    SUBCASE("Rebalance binary-search-trees inside binary-search-tree-of-binary-search-trees."){
    //        auto *tmp1 = &(u.getroot()->getdata());
    //        tmp1->rebalance();
    //        DEBUG_MSG("Printing rebalanced Binary Search Tree: "<< u);
    //        CHECK(tmp1->getroot()->getdata() == "beautiful!");
    //        CHECK(tmp1->getroot()->getleft()->getdata() == "are");
    //        CHECK(tmp1->getroot()->getleft()->getleft()->getdata() == "Templates");

    //        tmp1 = &(u.getroot()->getleft()->getdata());
    //        tmp1->rebalance();
    //        DEBUG_MSG("Printing rebalanced Binary Search Tree: "<< u);
    //        CHECK(tmp1->getroot()->getdata() == "difficult!");
    //        CHECK(tmp1->getroot()->getleft()->getdata() == "is");
    //        CHECK(tmp1->getroot()->getleft()->getleft()->getdata() == "OOP");

    //        tmp1 = &(u.getroot()->getleft()->getleft()->getdata());
    //        tmp1->rebalance();
    //        DEBUG_MSG("Printing rebalanced Binary Search Tree: "<< u);
    //        CHECK(tmp1->getroot()->getdata() == "world!");
    //        CHECK(tmp1->getroot()->getleft()->getdata() == "Hello");
    //    }
    //}
}


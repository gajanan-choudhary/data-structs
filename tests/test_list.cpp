#include "doctest.h"
#include "list.h"
using namespace std;



TEST_CASE("Empty List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    CHECK(u.gethead() == nullptr);
    DEBUG_MSG("Printing Linked list: "<< u);
    SUBCASE("Copy C'tor") {
        List<int> v = u;
        CHECK(v.gethead() == nullptr);
    }
    SUBCASE("Copy Assignment") {
        List<int> v;
        v = u;
        CHECK(v.gethead() == nullptr);
    }
    SUBCASE("Move C'tor") {
        List<int> v = std::move(u);
        CHECK(v.gethead() == nullptr);
    }
    SUBCASE("Move Assignment") {
        List<int> v;
        v = std::move(u);
        CHECK(v.gethead() == nullptr);
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
    }
    SUBCASE("Reverse") {
        u.reverse();
    }
    CHECK(u.gethead() == nullptr);
}

TEST_CASE("Single-noded List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    SUBCASE("Insert new node without any arguments."){
        SUBCASE("Push top."){
            u.push_top();
        }
        SUBCASE("Push bottom."){
            u.push_bottom();
        }
    }
    SUBCASE("Reverse") {
        u.push_top();
        u.reverse();
    }
    CHECK(u.gethead()->getdata() == int());
    CHECK(u.gethead()->getnext() == nullptr);
}

TEST_CASE("Single-noded List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    u.push_top(5);
    DEBUG_MSG("Printing Linked list: "<< u);

    SUBCASE("Copy C'tor") {
        List<int> v = u;
        CHECK(v.gethead() != u.gethead());
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
    }
    SUBCASE("Copy Assignment") {
        List<int> v;
        v = u;
        CHECK(v.gethead() != u.gethead());
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
    }
    SUBCASE("Reverse") {
        u.reverse();
    }
    CHECK(u.gethead() != nullptr);
    CHECK(u.gethead()->getdata() == 5);
    CHECK(u.gethead()->getnext() == nullptr);

    SUBCASE("Move C'tor") {
        List<int> v = std::move(u);
        CHECK(v.gethead() != u.gethead());
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
        CHECK(u.gethead() == nullptr); // Make sure it moved
    }
    SUBCASE("Move Assignment") {
        List<int> v;
        v = std::move(u);
        CHECK(v.gethead() != u.gethead());
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
        CHECK(u.gethead() == nullptr); // Make sure it moved
    }
}

TEST_CASE("List Operations - List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    SUBCASE("Exception check - Popping an empty list"){
        REQUIRE_THROWS_WITH_AS(u.pop_bottom(),
                "Error! Attempted node removal from an empty list",
                const std::runtime_error &);

        REQUIRE_THROWS_WITH_AS(u.pop_top(),
                "Error! Attempted node removal from an empty list",
                const std::runtime_error &);
    }

    SUBCASE("pushtop x 4, popbottom x 4") {
        int arr[]={141, 12, 342, 4521};
        for (int i=0; i<4; i++){
            u.push_top(arr[i]);
            auto tmp=u.gethead();
            int j = 0;
            while(tmp){
                CHECK(tmp->getdata()==arr[i-j]);
                tmp=tmp->next;
                j++;
            }
            DEBUG_MSG("Printing Linked list: "<< u);
        }
        for (int i=0; i<4; i++){
            u.pop_bottom();
            auto tmp=u.gethead();
            int j = 0;
            while(tmp){
                CHECK(tmp->getdata()==arr[3-j]);
                tmp=tmp->next;
                j++;
            }
            DEBUG_MSG("Printing Linked list: "<< u);
        }
    }
    SUBCASE("pushbottom x 4, poptop x 4") {
        int arr[]={1512, 252, 365, 48};
        for (int i=0; i<4; i++){
            u.push_bottom(arr[i]);
            auto tmp=u.gethead();
            int j = 0;
            while(tmp){
                CHECK(tmp->getdata()==arr[j]);
                tmp=tmp->next;
                j++;
            }
            DEBUG_MSG("Printing Linked list: "<< u);
        }
        for (int i=0; i<4; i++){
            u.pop_top();
            auto tmp=u.gethead();
            int j = i+1;
            while(tmp){
                CHECK(tmp->getdata()==arr[j]);
                tmp=tmp->next;
                j++;
            }
            DEBUG_MSG("Printing Linked list: "<< u);
        }
    }
    SUBCASE("pushtop, pushbottom, pushtop") {
        int arr[]={1352, 165, 125};
        int ans[]={arr[2], arr[0], arr[1]};
        u.push_top(arr[0]);
        u.push_bottom(arr[1]);
        u.push_top(arr[2]);
        int j=0;
        auto tmp=u.gethead();
        while(tmp){
            CHECK(tmp->getdata()==ans[j]);
            tmp=tmp->next;
            j++;
        }
        DEBUG_MSG("Printing Linked list: "<< u);
    }
    SUBCASE("pushbottom, pushtop, pushbottom") {
        int arr[]={216, 1123, 7355};
        int ans[]={arr[1], arr[0], arr[2]};
        u.push_bottom(arr[0]);
        u.push_top(arr[1]);
        u.push_bottom(arr[2]);
        int j=0;
        auto tmp=u.gethead();
        while(tmp){
            CHECK(tmp->getdata()==ans[j]);
            tmp=tmp->next;
            j++;
        }
        DEBUG_MSG("Printing Linked list: "<< u);
    }
}

TEST_CASE("Multiple-noded List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    u.push_top(5);
    u.push_top(1);
    u.push_top(25);
    DEBUG_MSG("Printing Linked list: "<< u);
    CHECK(u.gethead()->getdata() == 25);
    CHECK(u.gethead()->getnext()->getdata() == 1);
    CHECK(u.gethead()->getnext()->getnext()->getdata() == 5);
    CHECK(u.gethead()->getnext()->getnext()->getnext() == nullptr);
    SUBCASE("Overwrite List by copy assignment") {
        List<int> v;
        v.push_top(2140);
        v.push_bottom(7);
        u = v;
        CHECK(u.gethead()!=nullptr);
        CHECK(u.gethead()->getdata() == 2140);
        CHECK(u.gethead()->getnext()->getdata() == 7);
        CHECK(u.gethead()->getnext()->getnext() == nullptr);
        CHECK(v.gethead()!=nullptr);
        CHECK(v.gethead()->getdata() == 2140);
        CHECK(v.gethead()->getnext()->getdata() == 7);
        CHECK(v.gethead()->getnext()->getnext() == nullptr);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
        /* Make sure the lists are different and copied. */
        CHECK(u.gethead()!=v.gethead());
        CHECK(u.gethead()->getnext()!=v.gethead()->getnext());
        CHECK((u.gethead()+1)!=(v.gethead()+1)); // Tail
    }
    SUBCASE("Overwrite List by move assignment") {
        List<int> v;
        v.push_top(5);
        v.push_top(9);
        v.push_top(915);
        v.push_top(1429305);
        v.push_top(9214305);
        v.push_top(519305);
        u = std::move(v);
        CHECK(v.gethead()==nullptr);
        CHECK(u.gethead()!=nullptr);
        CHECK(u.gethead()->getdata() == 519305);
        CHECK(u.gethead()->getnext()->getdata() == 9214305);
        CHECK(u.gethead()->getnext()->getnext()->getdata() == 1429305);
        CHECK(u.gethead()->getnext()->getnext()->getnext()->getdata() == 915);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
        /* Make sure the lists are different. */
        CHECK(u.gethead()!=v.gethead());
        CHECK((u.gethead()+1)!=(v.gethead()+1)); // Tail
    }
    SUBCASE("Reverse the list"){
        u.reverse();
        DEBUG_MSG("Printing reversed Linked list: "<< u);
        CHECK(u.gethead()->getdata() == 5);
        CHECK(u.gethead()->getnext()->getdata() == 1);
        CHECK(u.gethead()->getnext()->getnext()->getdata() == 25);
        CHECK(u.gethead()->getnext()->getnext()->getnext() == nullptr);
    }
}

TEST_CASE("Multiple-noded List<string>") {
    DEBUG_MSG(endl);
    List<string> u;
    u.push_top("r");
    u.push_top("a");
    u.push_top("b");
    DEBUG_MSG("Printing Linked list: "<< u);
    CHECK(u.gethead()->getdata() == "b");
    CHECK(u.gethead()->getnext()->getdata() == "a");
    CHECK(u.gethead()->getnext()->getnext()->getdata() == "r");
    CHECK(u.gethead()->getnext()->getnext()->getnext() == nullptr);
    SUBCASE("Overwrite List by copy assignment") {
        List<string> v;
        v.push_top("OOP");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
    SUBCASE("Overwrite List by move assignment") {
        List<string> v;
        v.push_top("world");
        v.push_top("o");
        v.push_top("l");
        v.push_top("l");
        v.push_top("e");
        v.push_top("H");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
}

TEST_CASE("Complex Multiple-noded List<List<string>>") {
    DEBUG_MSG(endl);

    List<string> sentence1;
    sentence1.push_top("world!");
    sentence1.push_top("Hello");

    decltype(sentence1) sentence2;
    sentence2.push_top("difficult!");
    sentence2.push_top("is");
    sentence2.push_top("OOP");

    decltype(sentence1) sentence3;
    sentence3.push_bottom("Templates");
    sentence3.push_bottom("are");
    sentence3.push_bottom("beautiful!");

    List<decltype(sentence1)> u;
    u.push_top(sentence3);
    u.push_top(sentence2);
    u.push_top(sentence1);

    DEBUG_MSG("Printing Linked list: "<< u);
    List<string> *tmp = &(u.gethead()->getdata());
    CHECK(tmp->gethead()->getdata() == "Hello");
    CHECK(tmp->gethead()->getnext()->getdata() == "world!");

    tmp = &(u.gethead()->getnext()->getdata());
    CHECK(tmp->gethead()->getdata() == "OOP");
    CHECK(tmp->gethead()->getnext()->getdata() == "is");
    CHECK(tmp->gethead()->getnext()->getnext()->getdata() == "difficult!");

    tmp = &(u.gethead()->getnext()->getnext()->getdata());
    CHECK(tmp->gethead()->getdata() == "Templates");
    CHECK(tmp->gethead()->getnext()->getdata() == "are");
    CHECK(tmp->gethead()->getnext()->getnext()->getdata() == "beautiful!");

    SUBCASE("Reverse list-of-lists."){
        u.reverse();
        DEBUG_MSG("Printing reversed Linked list: "<< u);
        auto *tmp = &(u.gethead()->getdata());
        CHECK(tmp->gethead()->getdata() == "Templates");
        CHECK(tmp->gethead()->getnext()->getdata() == "are");
        CHECK(tmp->gethead()->getnext()->getnext()->getdata() == "beautiful!");
    
        tmp = &(u.gethead()->getnext()->getdata());
        CHECK(tmp->gethead()->getdata() == "OOP");
        CHECK(tmp->gethead()->getnext()->getdata() == "is");
        CHECK(tmp->gethead()->getnext()->getnext()->getdata() == "difficult!");
    
        tmp = &(u.gethead()->getnext()->getnext()->getdata());
        CHECK(tmp->gethead()->getdata() == "Hello");
        CHECK(tmp->gethead()->getnext()->getdata() == "world!");
        SUBCASE("Reverse lists inside list-of-lists."){
            auto *tmp1 = &(u.gethead()->getdata());
            tmp1->reverse();
            DEBUG_MSG("Printing reversed Linked list: "<< u);
            CHECK(tmp1->gethead()->getdata() == "beautiful!");
            CHECK(tmp1->gethead()->getnext()->getdata() == "are");
            CHECK(tmp1->gethead()->getnext()->getnext()->getdata() == "Templates");

            tmp1 = &(u.gethead()->getnext()->getdata());
            tmp1->reverse();
            DEBUG_MSG("Printing reversed Linked list: "<< u);
            CHECK(tmp1->gethead()->getdata() == "difficult!");
            CHECK(tmp1->gethead()->getnext()->getdata() == "is");
            CHECK(tmp1->gethead()->getnext()->getnext()->getdata() == "OOP");

            tmp1 = &(u.gethead()->getnext()->getnext()->getdata());
            tmp1->reverse();
            DEBUG_MSG("Printing reversed Linked list: "<< u);
            CHECK(tmp1->gethead()->getdata() == "world!");
            CHECK(tmp1->gethead()->getnext()->getdata() == "Hello");
        }
    }
}


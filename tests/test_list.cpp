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
        CHECK(v.gethead() == u.gethead());
    }
    SUBCASE("Copy Assignment") {
        List<int> v;
        v = u;
        CHECK(v.gethead() == nullptr);
        CHECK(v.gethead() == u.gethead());
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
        CHECK(u.gethead() == nullptr);
    }
    SUBCASE("Move C'tor") {
        List<int> v = std::move(u);
        CHECK(v.gethead() == nullptr);
        CHECK(v.gethead() == u.gethead());
    }
    SUBCASE("Move Assignment") {
        List<int> v;
        v = std::move(u);
        CHECK(v.gethead() == nullptr);
        CHECK(v.gethead() == u.gethead());
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
        CHECK(u.gethead() == nullptr);
    }
}

TEST_CASE("Single-noded List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    u.push_top(5);
    DEBUG_MSG("Printing Linked list: "<< u);
    CHECK(u.gethead()->getdata() == 5);
    CHECK(u.gethead()->getnext() == nullptr);
    SUBCASE("Copy C'tor") {
        List<int> v = u;
        CHECK(v.gethead() != u.gethead()); // Make sure it copied.
        CHECK(u.gethead()->getdata() == 5);
        CHECK(u.gethead()->getnext() == nullptr);
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
    }
    SUBCASE("Copy Assignment") {
        List<int> v;
        v = u;
        CHECK(v.gethead() != u.gethead()); // Make sure it copied.
        CHECK(u.gethead()->getdata() == 5);
        CHECK(u.gethead()->getnext() == nullptr);
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
    }
    SUBCASE("Self Copy Assignment") {
        u = u;
        CHECK(u.gethead()->getdata() == 5);
        CHECK(u.gethead()->getnext() == nullptr);
    }
    SUBCASE("Move C'tor") {
        List<int> v = std::move(u);
        CHECK(v.gethead() != u.gethead()); // Make sure it moved.
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
        CHECK(u.gethead() == nullptr);
    }
    SUBCASE("Move Assignment") {
        List<int> v;
        v = std::move(u);
        CHECK(v.gethead() != u.gethead()); // Make sure it moved.
        CHECK(v.gethead()->getdata() == 5);
        CHECK(v.gethead()->getnext() == nullptr);
        CHECK(u.gethead() == nullptr);
    }
    SUBCASE("Self Move Assignment") {
        u = std::move(u);
        CHECK(u.gethead() != nullptr);
        CHECK(u.gethead()->getdata() == 5);
        CHECK(u.gethead()->getnext() == nullptr);
    }

}
TEST_CASE("List Operations - List<int>") {
    DEBUG_MSG(endl);
    List<int> u;

    SUBCASE("top, top, top, top") {
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
    }
    SUBCASE("bottom, bottom, bottom, bottom") {
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
    }
    SUBCASE("top, bottom, top") {
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
    SUBCASE("bottom, top, bottom") {
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
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
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
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
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

    List<string> sentence2;
    sentence2.push_top("difficult!");
    sentence2.push_top("is");
    sentence2.push_top("OOP");

    List<string> sentence3;
    sentence3.push_top("beautiful!");
    sentence3.push_top("are");
    sentence3.push_top("Templates");

    List<List<string>> u;
    u.push_top(sentence3);
    u.push_top(sentence2);
    u.push_top(sentence1);

    DEBUG_MSG("Printing Linked list: "<< u);
    auto *tmp = &(u.gethead()->getdata());
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
}

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
    u.insert_at_front(5);
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

TEST_CASE("Multiple-noded List<int>") {
    DEBUG_MSG(endl);
    List<int> u;
    u.insert_at_front(5);
    u.insert_at_front(1);
    u.insert_at_front(25);
    DEBUG_MSG("Printing Linked list: "<< u);
    CHECK(u.gethead()->getdata() == 25);
    CHECK(u.gethead()->getnext()->getdata() == 1);
    CHECK(u.gethead()->getnext()->getnext()->getdata() == 5);
    CHECK(u.gethead()->getnext()->getnext()->getnext() == nullptr);
    SUBCASE("Overwrite List by copy assignment") {
        List<int> v;
        v.insert_at_front(2140);
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
    SUBCASE("Overwrite List by move assignment") {
        List<int> v;
        v.insert_at_front(5);
        v.insert_at_front(9);
        v.insert_at_front(915);
        v.insert_at_front(1429305);
        v.insert_at_front(9214305);
        v.insert_at_front(519305);
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
}

TEST_CASE("Multiple-noded List<string>") {
    DEBUG_MSG(endl);
    List<string> u;
    u.insert_at_front("r");
    u.insert_at_front("a");
    u.insert_at_front("b");
    DEBUG_MSG("Printing Linked list: "<< u);
    CHECK(u.gethead()->getdata() == "b");
    CHECK(u.gethead()->getnext()->getdata() == "a");
    CHECK(u.gethead()->getnext()->getnext()->getdata() == "r");
    CHECK(u.gethead()->getnext()->getnext()->getnext() == nullptr);
    SUBCASE("Overwrite List by copy assignment") {
        List<string> v;
        v.insert_at_front("OOP");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
    SUBCASE("Overwrite List by move assignment") {
        List<string> v;
        v.insert_at_front("world");
        v.insert_at_front("o");
        v.insert_at_front("l");
        v.insert_at_front("l");
        v.insert_at_front("e");
        v.insert_at_front("H");
        u = std::move(v);
        DEBUG_MSG("Printing overwritten Linked list: "<< u);
    }
}

TEST_CASE("Complex Multiple-noded List<List<string>>") {
    DEBUG_MSG(endl);

    List<string> sentence1;
    sentence1.insert_at_front("world!");
    sentence1.insert_at_front("Hello");

    List<string> sentence2;
    sentence2.insert_at_front("difficult!");
    sentence2.insert_at_front("is");
    sentence2.insert_at_front("OOP");

    List<string> sentence3;
    sentence3.insert_at_front("beautiful!");
    sentence3.insert_at_front("are");
    sentence3.insert_at_front("Templates");

    List<List<string>> u;
    u.insert_at_front(sentence3);
    u.insert_at_front(sentence2);
    u.insert_at_front(sentence1);

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

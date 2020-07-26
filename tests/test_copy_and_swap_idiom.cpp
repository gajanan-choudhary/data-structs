#include<assert.h>
#include "doctest.h"
#include "copy_and_swap_idiom.h"

TEST_CASE("Array") {
    SUBCASE("Parametrized Constructor -- default values");
    {
        Array u;
        CHECK(u.len == 0);
        CHECK(u.array == nullptr);
    }

    SUBCASE("Parametrized Constructor");
    {
        Array v(5,"v");
        for (int i=0; i<(int)v.len; i++) {v.array[i]=i;}
        CHECK(v.len == 5);
        CHECK(v.array != nullptr);
        for (int i=0; i<(int)v.len; i++) {CHECK(v.array[i]==i);}
        SUBCASE("Copy constructor");
        {
            auto w = v;
            CHECK(w.array != nullptr);
            CHECK(v.array != nullptr);
            CHECK(w.array != v.array); // Important
            CHECK(w.len == 5);
            CHECK(w.len == v.len);
            for (int i=0; i<(int)w.len; i++) {CHECK(w.array[i]==v.array[i]);}
        }
        SUBCASE("Parametrized constructor + Copy assignment");
        {
            Array w(50,"w");
            w=v;
            CHECK(w.array != nullptr);
            CHECK(v.array != nullptr);
            CHECK(w.array != v.array); // Important
            CHECK(w.len == 5);
            CHECK(w.len == v.len);
            for (int i=0; i<(int)w.len; i++) {CHECK(w.array[i]==v.array[i]);}
        }
        SUBCASE("Move constructor + Integer Addition operator");
        {
            Array w = v+0;
            CHECK(w.array != nullptr);
            CHECK(v.array != nullptr);
            CHECK(w.array != v.array); // Important
            CHECK(w.len == 5);
            CHECK(w.len == v.len);
            for (int i=0; i<(int)w.len; i++) {CHECK(w.array[i]==v.array[i]);}
        }
        SUBCASE("Move assignment + Vector Addition operator");
        {
            Array w(1,"w");
            w = v+v;
            CHECK(w.array != nullptr);
            CHECK(v.array != nullptr);
            CHECK(w.array != v.array); // Important
            CHECK(w.len == 5);
            CHECK(w.len == v.len);
            for (int i=0; i<(int)w.len; i++) {CHECK(w.array[i]==2*v.array[i]);}
        }
        SUBCASE("Self copy assignment");
        {
            v=v;
            CHECK(v.array != nullptr);
            CHECK(v.len == 5);
            for (int i=0; i<(int)v.len; i++) {CHECK(v.array[i]==i);}
        }
        SUBCASE("Self move assignment + Integer Addition operator");
        {
            v = v+0;
            CHECK(v.array != nullptr);
            CHECK(v.len == 5);
            for (int i=0; i<(int)v.len; i++) {CHECK(v.array[i]==i);}
        }
    }
}



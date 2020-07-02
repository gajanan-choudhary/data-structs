#include "doctest.h"
#include "vector.h"
#include <cmath>
using namespace std;

TEST_CASE("Vector") {
    Vector u;
    Vector w;
    Vector v(12.0, 16.0);

    SUBCASE("Constructor and getter -- default values") {
        //CHECK(u);
        CHECK(u.getx() == 0.0);
        CHECK(u.gety() == 0.0);
    }

    SUBCASE("Constructor and getter -- given values") {
        //CHECK(v);
        CHECK(v.getx() == 12.0);
        CHECK(v.gety() == 16.0);
    }

    SUBCASE("Setter and getter") {
        u.setx(3.0);
        u.sety(4.0);
        CHECK(u.getx() == 3.0);
        CHECK(u.gety() == 4.0);
        SUBCASE("Magnitude") {
            CHECK(std::fabs(u.mag() - 5.0) < 1.0E-12);
        }
        SUBCASE("Overloaded operators"){
            SUBCASE("Assignment"){
                w = u;
                CHECK(w.getx()==u.getx());
                CHECK(w.gety()==u.gety());
                //SUBCASE("if: == and != conditions"){
                //    CHECK(w == u);
                //    CHECK(w != v);
                //}
                SUBCASE("Self assignment"){
                    Vector *tmp = &u;
                    u = u;
                    CHECK(tmp == &u);
                    CHECK(tmp->getx()==u.getx());
                    CHECK(tmp->gety()==u.gety());
                    //SUBCASE("if: == and != conditions"){
                    //    CHECK(u == u);
                    //    CHECK(u != v);
                    //}
                }
            }
            SUBCASE("Math"){
                SUBCASE("+"){
                    w = u + v;
                    CHECK(w.getx()==u.getx()+v.getx());
                    CHECK(w.gety()==u.gety()+v.gety());
                }
                SUBCASE("-"){
                    w = u - v;
                    CHECK(w.getx()==u.getx()-v.getx());
                    CHECK(w.gety()==u.gety()-v.gety());
                }
                SUBCASE("+="){
		    Vector *tmp = &u;
                    u += v;
                    CHECK(tmp == &u);
                    CHECK(tmp->getx()==u.getx());
                    CHECK(tmp->gety()==u.gety());
                    CHECK(u.getx()==15.0);
                    CHECK(u.gety()==20.0);
                }
                SUBCASE("-="){
		    Vector *tmp = &u;
                    u -= v;
                    CHECK(tmp == &u);
                    CHECK(tmp->getx()==u.getx());
                    CHECK(tmp->gety()==u.gety());
                    CHECK(u.getx()== -9.0);
                    CHECK(u.gety()==-12.0);
                }
                SUBCASE("Scalar-vector multiplication"){
                    w = 5 * u;
                    CHECK(w.getx()==5*u.getx());
                    CHECK(w.gety()==5*u.gety());
                }
                SUBCASE("Vector-scalar multiplication"){
                    w = u * 5;
                    CHECK(w.getx()==5*u.getx());
                    CHECK(w.gety()==5*u.gety());
                }
                SUBCASE("Scalar division"){
                    w = u / 5;
                    CHECK(w.getx()==u.getx()/5);
                    CHECK(w.gety()==u.gety()/5);
                }
            }
        }
    }
}


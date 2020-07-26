#include<cmath>
#include"vector.h"

using namespace std;

/******************************************************************************/
/******************************************************************************/
/** Class methods
 */

/******************************************************************************/
/**
 * \brief Default constructor for Vector - initializes to 0.
 */
Vector::Vector(double xx, double yy){
    x=xx; y=yy;
}

/******************************************************************************/
/**
 * \brief Default destructor for Vector - does nothing.
 */
Vector::~Vector(){
}

/******************************************************************************/
/**
 * \brief Sets value of $x$.
 */
void Vector::setx(double xx){x=xx;}

/******************************************************************************/
/**
 * \brief Sets value of $y$.
 */
void Vector::sety(double yy){y=yy;}

/******************************************************************************/
/**
 * \brief Gets value of $x$.
 */
double Vector::getx(void){return x;}

/******************************************************************************/
/**
 * \brief Gets value of $y$.
 */
double Vector::gety(void){return y;}

/******************************************************************************/
/**
 * \brief Gets the magnitude of the vector $||v||$.
 */
double Vector::mag(void){return sqrt(x*x+y*y);}

/******************************************************************************/
/******************************************************************************/
/** Overloaded operators for class.
 */

/******************************************************************************/
/**
 * \brief Vector addition.
 */
void Vector::operator =(const Vector& b){this->x=b.x; this->y=b.y;}

/******************************************************************************/
/**
 * \brief Vector addition.
 */
Vector Vector::operator+(const Vector& b){
    return Vector(this->x+b.x, this->y+b.y);
}

/******************************************************************************/
/**
 * \brief Vector subtraction.
 */
Vector Vector::operator-(const Vector& b){
    return Vector(this->x-b.x, this->y-b.y);
}

/******************************************************************************/
/**
 * \brief Vector-scalar multiplication.
 */
Vector Vector::operator*(const double& c){
    return Vector(x*c, y*c);
}

/******************************************************************************/
/**
 * \brief Scalar-vector multiplication.
 */
Vector operator*(const double& c, const Vector& a){
    return Vector(c*a.x, c*a.y);
}

/******************************************************************************/
/**
 * \brief Vector/scalar division.
 */
Vector Vector::operator/(const double& c){
    return Vector(x/c, y/c);
}

/******************************************************************************/
/**
 * \brief Vector self-increment operator.
 */
void Vector::operator +=(const Vector& b){this->x+=b.x; this->y+=b.y;}

/******************************************************************************/
/**
 * \brief Vector self-decrement operator.
 */
void Vector::operator -=(const Vector& b){this->x-=b.x; this->y-=b.y;}

/******************************************************************************/
/**
 * \brief Displays the vector.
 */
ostream& operator<<(ostream& os, const Vector& v){
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

/******************************************************************************/
/**
 * \brief Reads in the vector from the user.
 */
istream& operator>>(istream& is, Vector& v){
    cout << "Enter x value: ";
    is >> v.x;
    cout << "Enter y value: ";
    is >> v.y;
    return is;
}


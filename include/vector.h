#pragma once

#include<iostream>

/**
 * \brief 2D vector class.
 */
class Vector {
    /**************************************************************************/
    private:
        /** $x$-coordinate */
        double x;
        /** $y$-coordinate */
        double y;

    /**************************************************************************/
    public:

        /**********************************************************************/
        /** Class methods. */

        /**
         * \brief Constructor for Vector object.
         */
        Vector(double xx=0.0, double yy=0.0);

        /**
         * \brief Default destructor for Vector object - does nothing for now.
         */
        ~Vector();

        /**
         * \brief Sets value of $x$.
         */
        void setx(double xx);

        /**
         * \brief Sets value of $y$.
         */
        void sety(double yy);

        /**
         * \brief Gets value of $x$.
         */
        double getx(void);

        /**
         * \brief Gets value of $y$.
         */
        double gety(void);

        /**
         * \brief Gets the magnitude of the vector $||v||$.
         */
        double mag(void);

        /**********************************************************************/
        /** Overloaded operators for the class. */

        /**
         * \brief Vector assignment.
         */
        void operator =(const Vector &b);
       
        /**
         * \brief Vector addition.
         */
        Vector operator+(const Vector& b);
       
        /**
         * \brief Vector subtraction.
         */
        Vector operator-(const Vector& b);

        /**
         * \brief Vector-scalar multiplication.
         */
        Vector operator*(const double& c);

        /**
         * \brief Scalar-vector multiplication.
         */
        friend Vector operator*(const double& c, const Vector& a);

        /**
         * \brief Vector/scalar division.
         */
        Vector operator/(const double& c);

        /**
         * \brief Vector self-increment operator.
         */
        void operator +=(const Vector &b);
       
        /**
         * \brief Vector self-decrement operator.
         */
        void operator -=(const Vector &b);
       
        /**********************************************************************/
        /** Friend functions
          */

        /**
         * \brief Displays the vector.
         */
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);

        /**
         * \brief Reads in the vector from the user.
         */
        friend std::istream& operator>>(std::istream& is, Vector& v);

};


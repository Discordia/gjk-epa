#pragma once

#include <cmath>

template<typename T>
class Matrix22
{
public:

    //
    // Members
    //

    union
    {
        T m4[4];
        T m22[2][2];
    };

public:

    //!
    //!
    //!
    Matrix22()
    {
        identity();
    }


    //!
    //!
    //!
    Matrix22(T m00, T m01, T m10, T m11)
    {
        m22[0][0] = m00;
        m22[0][1] = m01;
        m22[1][0] = m10;
        m22[1][1] = m11;
    }

    //!
    //!
    //!
    void identity()
    {
        m4[0] = 1;
        m4[1] = 0;
        m4[2] = 0;
        m4[3] = 1;
    }

    //
    // Operators
    //

    //!
    //!
    //!
    bool operator==(const Matrix22<T>& o)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (o.m4[i] != m4[i])
                return false;
        }

        return true;
    }

    //!
    //!
    //!
    bool operator!=(const Matrix22<T>& o)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (o.m4[i] != m4[i])
                return true;
        }

        return false;
    }

};

//!
//! Inline rotation to an abolute angle
//!
template<typename T>
inline void rotate(Matrix22<T>& m, T angle)
{
    T cosa = static_cast<T>(cos(angle));
    T sina = static_cast<T>(sin(angle));

    m.m22[0][0] = cosa;
    m.m22[0][1] = -sina;
    m.m22[1][0] = sina;
    m.m22[1][1] = cosa;
}

typedef Matrix22<float> mat22f;
typedef Matrix22<double> mat22d;

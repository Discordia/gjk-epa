#pragma once

#include <cassert>
#include <cmath>
#include <limits>

template<typename T>
struct Vector2
{

    // members

    union
    {
        T x, u, s;
    };
    union
    {
        T y, v, t;
    };

    // constructors

    Vector2()
            : x(0), y(0)
    {
    }

    Vector2(const T& vx, const T& vy)
            : x(vx), y(vy)
    {
    }

    Vector2(const T v[])
            : x(v[0]), y(v[1])
    {
    }

    Vector2(const Vector2& v)
            : x(v.x), y(v.y)
    {
    }

    Vector2(const T& v)
            : x(v), y(v)
    {
    }

    /////////////////////////////////////////////////////
    // operators                                       //
    /////////////////////////////////////////////////////

    const T& operator[](int index) const
    {
        assert(index >= 0 && index < 2);
        return reinterpret_cast<const T*>(this)[index];
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < 2);
        return reinterpret_cast<T*>(this)[index];
    }

    operator const T*() const
    {
        return reinterpret_cast<const T*>(this);
    }

    operator T*()
    {
        return reinterpret_cast<T*>(this);
    }

    bool operator==(const Vector2<T>& v)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (v[i] != (*this)[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Vector2<T>& v)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (v[i] != (*this)[i])
                return true;
        }
        return false;
    }

    Vector2 operator+() const
    {
        return *this;
    }

    Vector2 operator-() const
    {
        return Vector2(-x, -y);
    }

    Vector2 operator+(const Vector2& v) const
    {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator-(const Vector2& v) const
    {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 operator*(const Vector2& v) const
    {
        return Vector2(x * v.x, y * v.y);
    }

    Vector2 operator*(const T& s) const
    {
        return Vector2(x * s, y * s);
    }

    Vector2 operator/(const T& s) const
    {
        assert(s != 0);
        T is = 1 / s;
        return Vector2(x * is, y * is);
    }

    Vector2& operator+=(const Vector2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2& operator-=(const Vector2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2& operator*=(const Vector2& v)
    {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    Vector2& operator*=(const T& s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2& operator/=(const T& s)
    {
        assert(s != 0);
        T is = 1 / s;
        x *= is;
        y *= is;
        return *this;
    }

    Vector2& operator=(const Vector2& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vector2& operator=(const T& v)
    {
        x = v;
        y = v;
        return *this;
    }

    ////////////////////////////////////////////////////
    // methods                                        //
    ////////////////////////////////////////////////////

    //!
    //!
    //!
    bool isZero()
    {
        return x == 0 && y == 0;
    }

    //!
    //!
    //!
    T normalize()
    {
        T magnitude = getMagnitude();
        if (magnitude <= std::numeric_limits<T>::epsilon())
        {
            return 0;
        }

        T m = 1 / static_cast<T>(magnitude);
        x *= m;
        y *= m;

        return static_cast<T>(magnitude);
    }

    //!
    //!
    //!
    T getMagnitude()
    {
        return static_cast<T>(sqrt(x * x + y * y));
    }

    //!
    //!
    //!
    Vector2& left()
    {
        T temp = this->x;
        this->x = this->y;
        this->y = -temp;

        return *this;
    }

    //!
    //!
    //!
    Vector2& right()
    {
        T temp = this->x;
        this->x = -this->y;
        this->y = temp;

        return *this;
    }

    //!
    //!
    //!
    Vector2 getLeftHandOrthogonalVector()
    {
        return Vector2(this->y, -this->x);
    }
};

/////////////////////////////////////////////////////////
// inline functions                                    //
/////////////////////////////////////////////////////////

template<typename T>
inline T lengthSquared(const Vector2<T>& v)
{
    return v.x * v.x + v.y * v.y;
}

template<typename T>
inline T length(const Vector2<T>& v)
{
    return static_cast<T>(sqrt(v.x * v.x + v.y * v.y));
}

template<typename T>
inline T distanceSquared(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
}

template<typename T>
inline T distance(const Vector2<T>& v1, const Vector2<T>& v2)
{
    return static_cast<T>(sqrt(distanceSquared(v1, v2)));
}

template<typename T>
inline T dotProduct(const Vector2<T>& a, const Vector2<T>& b)
{
    return a.x * b.x + a.y * b.y;
}

template<typename T>
inline Vector2<T> crossProduct(const Vector2<T>& v)
{
    return Vector2<T>(-v.y, v.x);
}

template<typename T>
inline Vector2<T> normalize(const Vector2<T>& v)
{
    T s = static_cast<T>(sqrt(v.x * v.x + v.y * v.y));
    if (s != 0)
        s = 1 / s;

    return Vector2<T>(v.x * s, v.y * s);
}

template<typename T>
inline Vector2<T> rotateZ(const Vector2<T>& v, T angle)
{
    T cosa = static_cast<T>(cos(angle));
    T sina = static_cast<T>(sin(angle));
    return Vector2<T>(
            cosa * v.x - sina * v.y,
            sina * v.x + cosa * v.y);
}

template<typename T>
inline Vector2<T> lerp(const Vector2<T>& a, const Vector2<T>& b, const T& time)
{
    return Vector2<T>(
            a.x + (b.x - a.x) * time,
            a.y + (b.y - a.y) * time);
}

template<typename T>
inline Vector2<T> operator*(const T& s, const Vector2<T>& v)
{
    return Vector2<T>(v.x * s, v.y * s);
}

typedef Vector2<float> point2f;
typedef Vector2<float> vec2f;

typedef Vector2<double> point2d;
typedef Vector2<double> vec2d;

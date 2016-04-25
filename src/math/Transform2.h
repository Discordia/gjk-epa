#pragma once

#include <math/Vector2.h>
#include <math/Matrix22.h>

template<typename T>
class Transform2
{
public:

    //!
    //!
    //!
    Transform2()
            : translation(0, 0), scaleV(1, 1)
    {
    }

    //!
    //!
    //!
    Transform2(Vector2 <T> position)
            : translation(position), scaleV(1, 1)
    {
    }

    //!
    //!
    //!
    const Vector2 <T>& getTranslation() const
    {
        return translation;
    }

    //!
    //!
    //!
    void setTranslation(const T x, const T y)
    {
        translation.x = x;
        translation.y = y;
    }

    //!
    //!
    //!
    void setTranslation(const vec2f t)
    {
        translation.x = t.x;
        translation.y = t.y;
    }

    //!
    //!
    //!
    Matrix22 <T> getRotation() const
    {
        return rotation;
    }

    //!
    //!
    //!
    void translate(vec2f vector)
    {
        translation += vector;
    }

    //!
    //!
    //!
    void translate(T x, T y)
    {
        translate(vec2f(x, y));
    }

    //!
    //!
    //!
    void scale(T x, T y)
    {
        scale(vec2f(x, y));
    }

    //!
    //!
    //!
    void scale(vec2f o)
    {
        scaleV = o;
    }

    //!
    //! Rotate the rotation matrix to an absolute angle
    //!
    void rotateR(T angle)
    {
        rotate(rotation, angle);
    }

    //!
    //!
    //!
    vec2f getTransformed(vec2f vector) const
    {
        vec2f tv;

        T x = vector.x;
        T y = vector.y;

        tv.x = rotation.m22[0][0] * x + rotation.m22[0][1] * y + translation.x;
        tv.y = rotation.m22[1][0] * x + rotation.m22[1][1] * y + translation.y;

        return tv;
    }

    //!
    //!
    //!
    vec2f getTransformedR(vec2f vector) const
    {
        vec2f tv;

        tv.x = rotation.m22[0][0] * vector.x + rotation.m22[0][1] * vector.y;
        tv.y = rotation.m22[1][0] * vector.x + rotation.m22[1][1] * vector.y;

        return tv;
    }

    //!
    //!
    //!
    void toArray(T* m16) const
    {
        m16[0] = scaleV.x * rotation.m22[0][0];
        m16[1] = rotation.m22[0][1];
        m16[2] = 0;
        m16[3] = 0;
        m16[4] = rotation.m22[1][0];
        m16[5] = scaleV.y * rotation.m22[1][1];
        m16[6] = 0;
        m16[7] = 0;
        m16[8] = 0;
        m16[9] = 0;
        m16[10] = 1;
        m16[11] = 0;
        m16[12] = translation.x;
        m16[13] = translation.y;
        m16[14] = 0;
        m16[15] = 1;
    }

private:

    //!
    Vector2 <T> translation;

    //!
    Vector2 <T> scaleV;

    //!
    Matrix22 <T> rotation;
};

typedef Transform2<float> Transform2f;
typedef Transform2<double> Transform2d;

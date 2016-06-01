#pragma once

#include <glm/vec2.hpp>
#include <glm/mat2x2.hpp>

using glm::fvec2;
using glm::fmat2x2;

class Transform2
{
public:

    Transform2()
        : translation(0, 0), scaleV(1, 1)
    {
    }

    Transform2(fvec2 position)
        : translation(position), scaleV(1, 1)
    {
    }

    const fvec2& getTranslation() const
    {
        return translation;
    }

    const fmat2x2& getRotation() const
    {
        return rotation;
    }

    void translate(fvec2 vector)
    {
        translation += vector;
    }

    void translate(float x, float y)
    {
        translate(fvec2(x, y));
    }

    void scale(float x, float y)
    {
        scale(fvec2(x, y));
    }

    void scale(fvec2 o)
    {
        scaleV = o;
    }

    void transform(fvec2& v) const
    {
        float x = v.x;
        float y = v.y;

        v.x = rotation[0][0] * x + rotation[0][1] * y + translation.x;
        v.y = rotation[1][0] * x + rotation[1][1] * y + translation.y;
    }

    fvec2 getTransformed(const fvec2& v) const
    {
        fvec2 tv;

        float x = v.x;
        float y = v.y;

        tv.x = rotation[0][0] * x + rotation[0][1] * y + translation.x;
        tv.y = rotation[1][0] * x + rotation[1][1] * y + translation.y;

        return tv;
    }

    fvec2 getInverseTransformedR(fvec2 v) const
    {
        fvec2 tv;

        float x = v.x;
        float y = v.y;

        // since the transpose of a rotation matrix is the inverse
        tv.x = rotation[0][0] * x + rotation[1][0] * y;
        tv.y = rotation[0][1] * x + rotation[1][1] * y;

        return tv;
    }

    //!
    //!
    //!
    void toArray(float* m16) const
    {
        m16[0] = scaleV.x * rotation[0][0];
        m16[1] = rotation[0][1];
        m16[2] = 0;
        m16[3] = 0;
        m16[4] = rotation[1][0];
        m16[5] = scaleV.y * rotation[1][1];
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
    glm::fvec2 translation;

    //!
    glm::fvec2 scaleV;

    //!
    glm::fmat2x2 rotation;
};

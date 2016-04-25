#pragma once

#include <cassert>
#include <cstdint>

class Dimension
{
public:

    //
    // Constructors
    //

    Dimension()
            : width(0), height(0)
    {
    }

    Dimension(int32_t width, int32_t height)
            : width(width), height(height)
    {
    }

    Dimension(const Dimension& d)
    {
        width = d.width;
        height = d.height;
    }


    //
    // Operators
    //

    bool operator==(const Dimension& d)
    {
        return this->width == d.width && this->height == d.height;
    }

    bool operator!=(const Dimension& d)
    {
        return this->width != d.width || this->height != d.height;
    }

    Dimension operator+() const
    {
        return *this;
    }

    Dimension operator-() const
    {
        return Dimension(-width, -height);
    }

    Dimension operator+(const Dimension& d) const
    {
        return Dimension(width + d.width, height + d.height);
    }

    Dimension operator-(const Dimension& d) const
    {
        return Dimension(width - d.width, height - d.height);
    }

    template<typename T>
    Dimension operator*(const T& s) const
    {
        return Dimension(static_cast<int32_t>(width * s), static_cast<int32_t>(height * s));
    }

    Dimension operator/(const double& s) const
    {
        assert(s != 0);

        double is = 1.0 / s;

        return Dimension(static_cast<int32_t>(width * is), static_cast<int32_t>(height * is));
    }

    Dimension& operator+=(const Dimension& d)
    {
        width += d.width;
        height += d.height;

        return *this;
    }

    Dimension& operator-=(const Dimension& d)
    {
        width -= d.width;
        height -= d.height;

        return *this;
    }

    template<typename T>
    Dimension& operator*=(const T& s)
    {
        width *= static_cast<int32_t>(s);
        height *= static_cast<int32_t>(s);

        return *this;
    }

    template<typename T>
    Dimension& operator/=(const T& s)
    {
        assert(s != 0);

        T is = 1 / s;
        width = static_cast<int32_t>(width * is);
        height = static_cast<int32_t>(height * is);

        return *this;
    }

    Dimension& operator=(const Dimension& d)
    {
        width = d.width;
        height = d.height;

        return *this;
    }

    //
    // Methods
    //

public:

    //!
    int32_t width;

    //!
    int32_t height;
};
#pragma once

class Epsilon
{
public:

    //!
    //!
    //!
    static const double& getEpsilon()
    {
        return E;
    }

    //!
    //!
    //!
    static const double compute()
    {
        double e = 0.5;
        while (1.0 + e > 1.0)
        {
            e *= 0.5;
        }
        return e;
    }

private:

    //!
    static const double E;
};

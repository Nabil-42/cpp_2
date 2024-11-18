#ifndef FIXED
#define FIXED

#include <string>
#include <iostream>

class Fixed
{
    public: 
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(Fixed& other);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int i);

    private:
        int _fix;
        const static int _bits;

};

#endif
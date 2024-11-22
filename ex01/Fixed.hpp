#ifndef FIXED
#define FIXED

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    public: 
        Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        ~Fixed();


        int getRawBits() const;
        void setRawBits(int i);
        int toInt(void) const;
        float toFloat(void) const;
        
        friend std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

    private:
        int _value;
        const static int _bits = 8;

};

#endif
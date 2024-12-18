#ifndef FIXED_HPP
#define FIXED_HPP

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

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();    
    Fixed operator++(int);  
    Fixed& operator--();   
    Fixed operator--(int);  

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    int getRawBits(void) const;
    void setRawBits(int raw);
    float toFloat(void) const;
    int toInt(void) const;
    
    friend std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

private:
    int _value;
    static const int _bits = 8;
};

#endif

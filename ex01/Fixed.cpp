#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fix = 0;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    _fix = src.getRawBits();
}

Fixed& Fixed::operator=(Fixed& other)
{

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fix = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fix;
}

void Fixed::setRawBits(int i)
{
    _fix = i;
}



#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called\n";
    _value = intValue << _bits;

}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called\n";
    _value = roundf(floatValue * (1 << _bits));

}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _value = other.getRawBits();
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
    return _value;
}

void Fixed::setRawBits(int i)
{
    _value = i;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt(void) const 
{
    return _value >> _bits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();  
    return out;
}

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = _value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = _value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result._value = (_value * other._value) >> _bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._value == 0) 
    {
        std::cerr << "Erreur: division par zéro!" << std::endl;
        return Fixed(0);  
    }
    Fixed result;
    result._value = (_value << _bits) / other._value;
    return result;
}

Fixed& Fixed::operator++() 
{ 
    _value += 1;
    return *this;
}

Fixed Fixed::operator++(int) 
{ 
    Fixed temp = *this;
    _value += 1;
    return temp;
}

Fixed& Fixed::operator--()    
{     _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) 
{ 
    Fixed temp = *this;
    _value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}

#ifndef FIXED
#define FIXED

 #include <iostream>
 #include <string>

 class Fixed
 {
    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fix;
        const static int _bits = 8;
 };


#endif
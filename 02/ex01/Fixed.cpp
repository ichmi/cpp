#include "Fixed.hpp"

int const Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed(void) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixedRef) {
    std::cout << "Copy constructor called" << std::endl;

    *this = fixedRef;
}

Fixed::Fixed(int const integerValue) {
    std::cout << "Int constructor called" << std::endl;

    this->_rawBits = integerValue << Fixed::_fractionalBitsNumber;
}

Fixed::Fixed(float const floatValue) {
    std::cout << "Float constructor called" << std::endl;

    this->_rawBits = static_cast<int>(roundf(floatValue * (1 << Fixed::_fractionalBitsNumber)));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

int Fixed::toInt(void) const {
  return this->_rawBits >> Fixed::_fractionalBitsNumber;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits) / (1 << Fixed::_fractionalBitsNumber);
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;

    this->setRawBits(rhs.getRawBits());

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixedPointNumber) {
    return os << fixedPointNumber.toFloat();
}

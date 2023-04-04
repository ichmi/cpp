#include "Fixed.hpp"

int const Fixed::_fractionalBitsNumber = 8;

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(Fixed const &fixedRef) {
    *this = fixedRef;
}

Fixed::Fixed(int const integerValue) {
    this->_rawBits = integerValue << Fixed::_fractionalBitsNumber;
}

Fixed::Fixed(float const floatValue) {
    this->_rawBits = static_cast<int>(roundf(floatValue * (1 << Fixed::_fractionalBitsNumber)));
}

Fixed::~Fixed(void) {}

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
    this->setRawBits(rhs.getRawBits());
    return *this;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixedPointNumber) {
    return os << fixedPointNumber.toFloat();
}


bool Fixed::operator==(Fixed const &rhs) const {
    return (this->_rawBits == rhs._rawBits);
}

bool Fixed::operator!=(Fixed const &rhs) const {
    return (this->_rawBits != rhs._rawBits);
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return (this->_rawBits >= rhs._rawBits);
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return (this->_rawBits <= rhs._rawBits);
}

bool Fixed::operator>(Fixed const &rhs) const {
    return (this->_rawBits > rhs._rawBits);
}

bool Fixed::operator<(Fixed const &rhs) const {
    return (this->_rawBits < rhs._rawBits);
}


Fixed Fixed::operator+(Fixed const &rhs) {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) {
    return Fixed(this->toFloat() / rhs.toFloat());
}


Fixed &Fixed::operator++(void) {
    ++this->_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed objPos(*this);

    this->_rawBits++;
    return objPos;
}

Fixed &Fixed::operator--(void) {
    --this->_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed objPos(*this);

    this->_rawBits--;
    return objPos;
}


Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
    return lhs._rawBits < rhs._rawBits ? lhs : rhs;
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs) {
    return lhs._rawBits < rhs._rawBits ? lhs : rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
    return lhs._rawBits > rhs._rawBits ? lhs : rhs;
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
    return lhs._rawBits > rhs._rawBits ? lhs : rhs;
}

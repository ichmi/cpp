#include "Data.hpp"

Data::Data(void) : _value(0) {}

Data::Data(Data const &obj) {
    *this = obj;
}

Data::~Data(void) {}

Data &Data::operator=(Data const &rhs) {
    this->_value = rhs.getValue();

    return *this;
}

Data::Data(int value) : _value(value) {}

int Data::getValue(void) const {
    return this->_value;
}

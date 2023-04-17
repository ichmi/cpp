#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
    private:
        int _value;

    public:
        Data(void);
        Data(Data const &obj);
        ~Data(void);
        Data &operator=(Data const &rhs);

        Data(int value);

        int  getValue(void) const;
};

#endif

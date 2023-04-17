#include "Serializer.hpp"

int main() {
    std::cout << BLUE "Serialization/Deserialization (stack)" RES << std::endl;
    {
        Data data(42);
        std::cout << GRAY "Original data:      " YELLOW << data.getValue() << RES << std::endl;

        uintptr_t ptr = Serializer::serialize(&data);
        std::cout << GRAY "Serialized value:   " YELLOW << ptr << RES << std::endl;
        
        Data* ptrData = Serializer::deserialize(ptr);
        std::cout << GRAY "Deserialized value: " GREEN << ptrData->getValue() << RES << std::endl;
    }
    
    std::cout << BLUE "\nSerialization/Deserialization (heap)" RES << std::endl;
    {
        Data *data = new Data(42);
        std::cout << GRAY "Original data:      " YELLOW << data->getValue() << RES << std::endl;

        uintptr_t ptr = Serializer::serialize(data);
        std::cout << GRAY "Serialized value:   " YELLOW << ptr << RES << std::endl;
        
        Data* ptrData = Serializer::deserialize(ptr);
        std::cout << GRAY "Deserialized value: " GREEN << ptrData->getValue() << RES << std::endl;
        delete data;
    }

    std::cout << BLUE "\nExample raw reinterpret_cast usage" RES << std::endl;
    {
        int  x = 42;
        int *p = &x;
        uintptr_t ptr = reinterpret_cast<uintptr_t>(p);
        std::cout << GRAY "ptr:         " YELLOW << ptr << RES << std::endl;

        int *q = reinterpret_cast<int *>(ptr);
        std::cout << GRAY "int * addr:  " YELLOW << q << RES << std::endl;
        std::cout << GRAY "int * value: " GREEN << *q << RES << std::endl;
    }

    return 0;
}

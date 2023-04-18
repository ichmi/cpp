#include "Array.hpp"

#define MAX_VAL 750

int testSubjectExample(void) {
    Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    return 0;
}

int main(void) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    if (testSubjectExample()) {
        return 1;
    }

    std::cout << BLUE "\nint Array" RES << std::endl;
    {
        Array<int> arr(5);
        std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
        arr.randomInit();
        arr.printArray();
    }

    std::cout << BLUE "\nconst int Array" RES << std::endl;
    {
        Array<int> const arr(10);
        std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
        arr.printArray();
    }

    std::cout << BLUE "\ndouble Array" RES << std::endl;
    {
        Array<double> arr(3);
        std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
        arr[0] = 3.141;
        arr[1] = .123123;
        arr[2] = 42.001;
        arr.printArray();
    }

    std::cout << BLUE "\nchar Array" RES << std::endl;
    {
        Array<char> arr(5);
        std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
        arr[0] = 'a';
        arr[1] = 'e';
        arr[2] = 'i';
        arr[3] = 'o';
        arr[4] = 'u';
        arr.printArray();
    }

    std::cout << BLUE "\nC-string Array" RES << std::endl;
    {
        Array<const char *> arr(3);
        std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
        arr[0] = "foo";
        arr[1] = "bar";
        arr[2] = "baz";
        arr.printArray();
    }

    std::cout << BLUE "\nException handling" RES << std::endl;
    {
        try {
            Array<int> arr(3);
            std::cout << GRAY "size:   " YELLOW << arr.size() << RES << std::endl;
            std::cout << GRAY "arr[2]: " GREEN << arr[2] << RES << std::endl;
            arr[3] = -42;
        } catch (std::exception const &e) {
            std::cerr << GRAY "arr[3]:  " RED << e.what() << RES << std::endl;
        }

        try {
            Array<int> arr(3);
            std::cout << GRAY "size: " YELLOW << arr.size() << RES << std::endl;
            std::cout << arr[-1];
        } catch (std::exception const &e) {
            std::cerr << GRAY "arr[-1]: " RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}

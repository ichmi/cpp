#include "Point.hpp"

int main(void) {
    struct s_tt {
		Point A;
		Point B;
		Point C;
		Point P;
        std::string const name;
	} tt[] = {
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0, 0), "Test 1"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4, 0), "Test 2"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4, 6), "Test 3"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(2, 2), "Test 4"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(1, 1), "Test 5"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(5, 4), "Test 6"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0.1f, 0.1f), "Test 7"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(-1, 0), "Test 8"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0, -2), "Test 9"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(3, 7), "Test 10"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0, 2), "Test 11"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(2, 4), "Test 12"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(-0.1f, 0), "Test 13"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0, -0.01f), "Test 14"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(6, 1), "Test 15"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4.01f, 2), "Test 16"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0, 6.001f), "Test 17"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4.0f, 6.01f), "Test 18"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4.0001f, 6.01f), "Test 19"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(3.99f, 5.99f), "Test 20"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(4.0f, 2.53214f), "Test 21"},
	    {Point(0, 0), Point(4, 0), Point(4, 6), Point(0.0f, 0.01f), "Test 22"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        std::cout << BLUE << tt[i].name <<  RES ": ";
        bool const inside = bsp(tt[i].A, tt[i].B, tt[i].C, tt[i].P);
        if (inside) {
            std::cout << GREEN "inside" RES << std::endl;
        } else {
            std::cout << RED "outside" RES << std::endl;
        }
	}

    return 0;
}

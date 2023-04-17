#include "ScalarConverter.hpp"

int testDefault(void) {
    struct s_tt {
		std::string testcase;
		std::string literal;
	} tt[] = {
	    {"\n=========== CHAR Casting ===========\ninvalid ('\\0')", "\0"},
	    {"invalid ('')", ""},
	    {"a", "a"},
	    {"A", "A"},
	    {"97", "97"},
	    {"32", "32"},
	    {"42.0f", "42.0f"},
	    {"59.", "59."},
	    {"whitespace (' ')", " "},
	    {"non-printable ('\\r')", "\r"},
	    {"non-printable ('\\t')", "\t"},
	    {"non-printable ('\\n')", "\n"},
	    {"non-printable ('\\f')", "\f"},

	    {"\n============ INT Casting ============\n0", "0"},
	    {"0", "0"},
	    {"-0", "-0"},
	    {"+0", "+0"},
	    {"1", "1"},
	    {"-1", "-1"},
	    {"+1", "+1"},
	    {"97", "97"},
	    {"127", "127"},
	    {"128", "128"},
	    {"-128", "-128"},
	    {"-129", "-129"},
	    {"123123123", "123123123"},
	    {"-123123123", "-123123123"},
	    {"12312312312312312", "12312312312312312"},
	    {"-12312312312312312", "-12312312312312312"},

	    {"\n============ FLOAT Casting ============\n0", "0"},
	    {"0.f", "0.f"},
	    {"+0.f", "+0.f"},
	    {"-0.f", "-0.f"},
	    {"+0.0f", "+0.0f"},
	    {"0.0f", "0.0f"},
	    {"-0.0f", "-0.0f"},
	    {"0.1f", "0.1f"},
	    {"0.001f", "0.001f"},
	    {"-0.001f", "-0.001f"},
	    {".f", ".f"},
	    {"3.141f", "3.141f"},
	    {"-3.141f", "-3.141f"},
	    {".42f", ".42f"},
	    {"112233.12f", "112233.12f"},
	    {"-112233.12f", "-112233.12f"},
	    {"float max value", "340282346638528859811704183484516925440.0f"},
	    {"float min value", "-340282346638528859811704183484516925440.0f"},
	    {"float overflow", "350282346638528859811704183484516925440.0f"},
	    {"float underflow", "-350282346638528859811704183484516925440.0f"},

	    {"\n============ DOUBLE Casting ============\n0", "0"},
	    {"0.", "0."},
	    {"+0.", "+0."},
	    {"-0.", "-0."},
	    {"+0.0", "+0.0"},
	    {"0.0", "0.0"},
	    {"-0.0", "-0.0"},
	    {"0.1", "0.1"},
	    {"0.001", "0.001"},
	    {"-0.001", "-0.001"},
	    {".", "."},
	    {"3.141", "3.141"},
	    {"-3.141", "-3.141"},
	    {".42", ".42"},
	    {"112233.12", "112233.12"},
	    {"-112233.12", "-112233.12"},
	    {"Double max value", "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"},
	    {"Double min value", "-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"},
	    {"Double overflow", "199769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"},
	    {"Double underflow", "-199769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"},

	    {"\n============ INFINITY Casting ============\n0", "0"},
	    {"+inff", "+inff"},
	    {"-inff", "-inff"},
	    {"+inf", "+inf"},
	    {"-inf", "-inf"},

	    {"\n============ NAN Casting ============\n0", "0"},
	    {"nanf", "nanf"},
	    {"nan", "nan"},

	    {"\n============ Invalid cast literals ============\n0", "0"},
	    {"foo", "foo"},
	    {"&^@312", "&^@312"},
	    {"'     '", "     "},
	    {"'\\t\\t'", "\t\t"},
	    {"42.42.42", "42.42.42"},
	    {"42f", "42f"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        std::cout << std::endl << BLUE << tt[i].testcase <<  RES << std::endl;
        ScalarConverter::convert(tt[i].literal);
	}

	return 0;
}

int main(int ac, char **av) {
	if (ac == 1) {
		return testDefault();
	}
	if (ac > 2) {
		std::cerr << RED "invalid number of arguments" RES << std::endl;
		return 1;
	}
	std::string s = av[1];
	ScalarConverter::convert(s);

    return 0;
}
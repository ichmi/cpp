#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

/* Contact */
TEST_CASE("Single insert") {
    PhoneBook phoneBook;

    CHECK_EQ(phoneBook.getSize(), 0);

    phoneBook.add(Contact("a", "a", "a", "a", "a"));

    CHECK_EQ(phoneBook.getSize(), 1);
}
 
TEST_CASE("8 inserts") {
    PhoneBook phoneBook;

    for (int i = 0; i < 8; i++) {
        phoneBook.add(Contact("a", "a", "a", "a", "a"));
    }

    CHECK(phoneBook.getSize() == 8);
}

TEST_CASE("10 inserts") {
    PhoneBook phoneBook;

    for (int i = 0; i < 10; i++) {
        phoneBook.add(Contact("a", "a", "a", "a", "a"));
    }

    CHECK_EQ(phoneBook.getSize(), 8);
}

TEST_CASE("9 inserts, check if oldest value was updated") {
    PhoneBook phoneBook;

    for (int i = 0; i < 8; i++) {
        phoneBook.add(Contact("a", "a", "a", "a", "a"));
    }

    phoneBook.add(Contact("x", "x", "x", "x", "x"));
    Contact contact = phoneBook.getContacts()[0];
    CHECK_EQ(contact.getFirst(), "x");
}

TEST_CASE("10 inserts, check if oldest value was updated") {
    PhoneBook phoneBook;

    for (int i = 0; i < 8; i++) {
        phoneBook.add(Contact("a", "a", "a", "a", "a"));
    }

    CHECK_EQ(phoneBook.getSize(), 8);

    phoneBook.add(Contact("x", "a", "a", "a", "a"));
    Contact contact = phoneBook.getContacts()[0];
    CHECK_EQ(contact.getFirst(), "x");

    phoneBook.add(Contact("y", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[1];
    CHECK_EQ(contact.getFirst(), "y");

    phoneBook.add(Contact("z", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[2];
    CHECK_EQ(contact.getFirst(), "z");

    phoneBook.add(Contact("foo", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[3];
    CHECK_EQ(contact.getFirst(), "foo");

    phoneBook.add(Contact("bar", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[4];
    CHECK_EQ(contact.getFirst(), "bar");

    phoneBook.add(Contact("baz", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[5];
    CHECK_EQ(contact.getFirst(), "baz");

    phoneBook.add(Contact("z", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[6];
    CHECK_EQ(contact.getFirst(), "z");

    phoneBook.add(Contact("y", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[7];
    CHECK_EQ(contact.getFirst(), "y");

    phoneBook.add(Contact("a", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[0];
    CHECK_EQ(contact.getFirst(), "a");

    phoneBook.add(Contact("b", "x", "x", "x", "x"));
    contact = phoneBook.getContacts()[1];
    CHECK_EQ(contact.getFirst(), "b");
    CHECK_EQ(phoneBook.getSize(), 8);
}

/* Utils */
TEST_CASE("Testing input first/last name validation") {
    struct s_tt
	{
		std::string arg;
		std::string expected;
	} tt[] = {
	    {"foo", "foo"},
	    {"foo bar", "foo"},
	    {"foo123", "foo123"},
	    {"123foo", "123foo"},
	    {"foo-bar", "foo-bar"},
	    {"foo-bar-baz", "foo-bar-baz"},
	    {" foo", "foo"},
	    {"foo ", "foo"},
	    {"     foo", "foo"},
	    {" foo ", "foo"},
	    {"\t\t\tfoo\t\t", "foo"},
	    {"\tf-oo", "f-oo"},
	    {"  f-oo\t12-3", "f-oo"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initName(tt->arg), tt->expected);
	}
}

TEST_CASE("Testing invalid first/last name input validation") {
    struct s_tt
	{
		std::string arg;
	} tt[] = {
	    {"\"foo\""},
	    {"\'foo\'"},
	    {"foo!"},
	    {""},
	    {"\n"},
	    {".foo bar"},
	    {"foo bar."},
	    {"        "},
	    {"\t\t\t\t"},
	    {"f#o"},
	    {"foo\t\t\t\t\t#"},
	    {"foo          #"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initName(tt->arg).empty(), true);
	}
}

TEST_CASE("Testing valid nickname/secret input validation") {
    struct s_tt
	{
		std::string arg;
		std::string expected;
	} tt[] = {
	    {"foo bar baz", "foo bar baz"},
	    {"    foo bar baz", "foo bar baz"},
	    {"foo bar baz    ", "foo bar baz    "},
	    {"foo123 bar321 baz42", "foo123 bar321 baz42"},
	    {"darkest-secret ever", "darkest-secret ever"},
	    {"\t\tfoo-bar-baz", "\t\tfoo-bar-baz"},
	    {"1", "1"},
	    {"foo#123", "foo#123"},
	    {"   f3rZ4l!0.", "f3rZ4l!0."},
	    {"@f3rZ4l-!0.", "@f3rZ4l-!0."},
	    {"\t@f3rZ4l-!0\t.", "@f3rZ4l-!0\t."},
	    {"    foo ,bar baz", "    foo ,bar baz"},
	    {"foo bar baz?    ", "foo bar baz?    "},
	    {"foo123 bar321 baz42@", "foo123 bar321 baz42@"},
	    {"...darkest-s.ecret ever", "...darkest-s.ecret ever"},
	    {"\t&\tfoo-bar-baz", "\t&\tfoo-bar-baz"},
	    {"          ?", "          ?"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initMessage(tt->arg), tt->expected);
	}
}

TEST_CASE("Testing invalid nickname/secret input validation") {
    struct s_tt
	{
		std::string arg;
	} tt[] = {
	    {"\"foo bar baz\""},
	    {""},
	    {"\n\n"},
	    {"\t"},
	    {"          "},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initMessage(tt->arg).empty(), true);
	}
}

TEST_CASE("Testing valid phone number input validation") {
    struct s_tt
	{
		std::string arg;
		std::string expectedStr;
        int expectedSize;
	} tt[] = {
	    {"123456789", "123456789", 9},
	    {"51123456789", "123456789", 11},
	    {"5551123456789", "123456789", 13},
	    {"    123456789", "123456789", 9},
	    {"123456789    ", "123456789", 9},
	    {"    123456789    ", "123456789", 9},
	    {"1 23456789", "123456789", 9},
	    {"1 2345 6789", "123456789", 9},
	    {"1\t2345\t\t\t\t6789", "123456789", 9},
	    {"\t55 51      12345 6789", "123456789", 13},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initPhoneNumber(tt->arg), tt->expectedStr);
        CHECK_EQ(initPhoneNumber(tt->arg).size(), tt->expectedSize);
	}
}

TEST_CASE("Testing invalid phone number input validation") {
    struct s_tt
	{
		std::string arg;
	} tt[] = {
	    {"12345678"},
	    {""},
	    {"\n"},
	    {"     "},
	    {"\t\t\t"},
	    {"1"},
	    {"05551123456789"},
	    {"000000005551123456789"},
	    {"+5551123456789"},
	    {"\"5551123456789\""},
	    {"#51123456789"},
	    {"5112?3456789"},
	    {"51123456789?"},
	    {"1234-5678"},
	    {"51 1234-5678"},
	    {"+55 51 1234-5678"},
	    {"55 (51) 12345678"},
	};
	size_t n = sizeof(tt) / sizeof(tt[0]);

	size_t i = -1;
	while (++i < n) {
        CHECK_EQ(initPhoneNumber(tt->arg).empty(), true);
	}
}

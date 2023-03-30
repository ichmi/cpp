#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define RED "\x1b[38;5;88m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define RES "\x1b[0m"

#define _ERROR RED "[-] " RES

typedef std::ifstream t_ifs;
typedef std::ofstream t_ofs;
typedef std::string::iterator t_it;

class Replacer {
    private:
        void __replace(t_it &it, t_it end, std::string &buff);

    public:
        std::string strToFind;
        std::string strToReplace;
        std::string infile;
        std::string outfile;

        Replacer(void);
        ~Replacer(void);

        bool validateInput(int ac, char **av);
        bool initStreams(char **av, t_ifs &ifs, t_ofs &ofs);
        bool validateInfile(t_ifs &ifs, t_ofs &ofs);
        void replace(t_ifs &ifs, t_ofs &ofs);
};

#endif


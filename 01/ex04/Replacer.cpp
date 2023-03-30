#include "Replacer.hpp"

Replacer::Replacer(void) {}

Replacer::~Replacer(void) {}

bool Replacer::validateInput(int ac, char **av) {
    if (ac != 4) {
        std::cout << _ERROR "invalid number of arguments, try: " 
        << GRAY " ./replace " << YELLOW "<filename> <s1> <s2>" RES << std::endl;
        return true;
    }

    std::string const strToFind = av[2];
    if (strToFind.empty()) {
        std::cout << _ERROR "<s1> must not be empty" << std::endl;
        return true;
    }
    this->strToFind = strToFind;

    std::string const strToReplace = av[3];
    // if (strToReplace.empty()) {
    //     std::cout << _ERROR "<s2> must not be empty" << std::endl;
    //     return true;
    // }
    this->strToReplace = strToReplace;

    return false;
}

bool Replacer::initStreams(char **av, t_ifs &ifs, t_ofs &ofs) {
    std::string infile = av[1];
    ifs.open(infile.c_str());
    if (!ifs) {
        std::cout << _ERROR "invalid filename/permissions" << std::endl;
        return true;
    }
    this->infile = infile;

    std::string outfile = std::string(av[1]) + ".replace";
    ofs.open(outfile.c_str());
    if (!ofs) {
        std::cout << _ERROR "could not open the output file " << outfile << std::endl;
        ifs.close();
        return true;
    }
    this->outfile = outfile;

    return false;
}

bool Replacer::validateInfile(t_ifs &ifs, t_ofs &ofs) {
    bool isStrFound = false;
    std::string buff;
    while (std::getline(ifs, buff)) {
        if (buff.find(this->strToFind) != std::string::npos) {
            isStrFound = true;
            break ;
        }
    }
    if (!isStrFound) {
        ifs.close();
        ifs.open(this->infile.c_str());
        ofs << ifs.rdbuf();
        ifs.close();
        ofs.close();
        return true;
    }
    ifs.close();

    return false;
}

void Replacer::replace(t_ifs &ifs, t_ofs &ofs) {
    ifs.open(this->infile.c_str());
    std::string line;
    while (std::getline(ifs, line)) {

        std::string buff;
        std::string::iterator it = line.begin();
        std::string::iterator end = line.end();
        this->__replace(it, end, buff);

        if (!ifs.eof()) {
            ofs << buff << std::endl;
        } else {
            ofs << buff;
        }
    }
}

void Replacer::__replace(t_it &it, t_it end, std::string &buff) {
    std::string line = it.base();
    size_t i = line.find(this->strToFind);

    if (i != std::string::npos) {
        size_t j = -1;
        while (++j < i && it != end) {
            buff += *it;
            it++;
        }

        size_t size = this->strToFind.size();
        buff += this->strToReplace;
        j = -1;
        while (++j < size) {
            it++;
        }
        this->__replace(it, end, buff);
    } else {
        buff += line;
    }
}

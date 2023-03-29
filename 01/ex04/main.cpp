#include "Replacer.hpp"

void fn(std::string::iterator &it, std::string::iterator end, std::string const strToFind, std::string const strToReplace, std::string &buff) {
    std::string line = it.base();
    size_t i = line.find(strToFind);

    if (i != std::string::npos) {
        size_t j = -1;
        while (++j < i && it != end) {
            buff += *it;
            it++;
        }

        size_t size = strToFind.size();
        buff += strToReplace;
        j = -1;
        while (++j < size) {
            it++;
        }
        fn(it, end, strToFind, strToReplace, buff);
    } else {
        buff += line;
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << _ERROR "invalid number of arguments, try: " 
        << GRAY " ./replace " << YELLOW "<filename> <s1> <s2>" RES << std::endl;
        return 1;
    }

    std::string const strToFind = av[2];
    if (strToFind.empty()) {
        std::cout << _ERROR "<s1> must not be empty" << strToFind << std::endl;
        return 2;
    }

    std::string const strToreplace = av[3];
    if (strToreplace.empty()) {
        std::cout << _ERROR "<s2> must not be empty" << strToFind << std::endl;
        return 2;
    }


    std::string infile = av[1];
    std::ifstream ifs(infile.c_str());
    if (!ifs) {
        std::cout << _ERROR "invalid filename/permissions" << std::endl;
        return 1;
    }

    std::string outfile = std::string(av[1]) + ".replace";
    std::ofstream ofs;
    ofs.open(outfile.c_str());
    if (!ofs) {
        std::cout << _ERROR "could not open the output file " << outfile << std::endl;
        ifs.close();
        return 1;
    }



    bool isStrFound = false;
    std::string buff;
    while (std::getline(ifs, buff)) {
        if (buff.find(strToFind) != std::string::npos) {
            isStrFound = true;
            break ;
        }
    }
    if (!isStrFound) {
        ifs.close();
        ifs.open(infile.c_str());
        ofs << ifs.rdbuf();
        ifs.close();
        ofs.close();
        return 0;
    }
    ifs.close();



    ifs.open(infile.c_str());
    std::string line;
    while (std::getline(ifs, line)) {

        std::string buff;
        std::string::iterator it = line.begin();
        std::string::iterator end = line.end();
        fn(it, end, strToFind, strToreplace, buff);

        if (!ifs.eof()) {
            ofs << buff << std::endl;
        } else {
            ofs << buff;
        }
    }

    ifs.close();
    ofs.close();

    return 0;
}

#include "Replacer.hpp"

int main(int ac, char **av) {
    Replacer data;
    bool err;

    err = data.validateInput(ac, av);
    if (err) {
        return 1;
    }

    t_ifs ifs;
    t_ofs ofs;
    err = data.initStreams(av, ifs, ofs);
    if (err) {
        return 1;
    }

    err = data.validateInfile(ifs, ofs);
    if (err) {
        return 0;
    }

    data.replace(ifs, ofs);

    ifs.close();
    ofs.close();

    return 0;
}

#!/bin/bash

ARG=$1
CNAME=${ARG,,}

echo "#ifndef ${CNAME^}_HPP
#define ${CNAME^}_HPP

#include <iostream>

class ${CNAME^} {
   private:
   public:
    ${CNAME^}(void);
    ~${CNAME^}();
};

#endif" > ${CNAME^}.hpp

echo "#include \"${CNAME^}.hpp\"

${CNAME^}::${CNAME^}(void) {}

${CNAME^}::~${CNAME^}() {}" > ${CNAME^}.cpp

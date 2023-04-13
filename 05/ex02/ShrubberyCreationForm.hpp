#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define ASCII_TREE "\n\
              _{\\ _{\\{\\/}/}/}__\n\
             {/{/\\}{/{/\\}(\\}{/\\} _\n\
            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n\
         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n\
       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n\
      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n\
      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n\
     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n\
      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n\
       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n\
      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n\
       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n\
         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n\
          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n\
            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n\
             {/{\\{\\{\\/}/}{\\{\\}/}\n\
              {){/ {\\/}{\\/} \\}\\}\n\
              (_)  \\.-'.-/\n\
          __...--- |'-.-'| --...__\n\
   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n\
 -\"    ' .  . '    |.'-._| '  . .  '   \n\
 .  '-  '    .--'  | '-.'|    .  '  . '\n\
          ' ..     |'-_.-|\n\
  .  '  .       _.-|-._ -|-._  .  '  .\n\
              .'   |'- .-|   '.\n\
  ..-'   ' .  '.   `-._.--   .'  '  - .\n\
   .-' '        '-._______.-'     '  .\n\
        .      ~,\n\
    .       .   .,- -..   .    ' '-.\n\
"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const &obj);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        ShrubberyCreationForm(std::string const target);

        class FileManagementException : public std::exception {
            char const *what(void) const throw();
        };

        virtual void execute(Bureaucrat const &executor) const;
};

typedef ShrubberyCreationForm Shrubbery;

#endif

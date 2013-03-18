/*
** BF_Translator.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d16-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 24 17:01:13 2013 maxime ginters
** Last update Thu Jan 24 18:01:02 2013 maxime ginters
*/

#include "BF_Translator.h"

BF_Translator::BF_Translator()
{
    _map['+'] = "++t[i];";
    _map['-'] = "--t[i];";
    _map['>'] = "++i;";
    _map['<'] = "--i;";
    _map['.'] = "write(1, &t[i], 1);";
    _map[','] = "read(0, &t[i], 1);";
    _map['['] = "while (t[i]) {";
    _map[']'] = "}";
}

int BF_Translator::translate(std::string const& in, std::string const& out)
{
    std::ofstream output;
    output.open(out.c_str());
    if (!output.is_open())
    {
        std::cout << "Fail to open " << out << std::endl;
        return 1;
    }
    std::ifstream input;
    input.open(in.c_str());
    if (!input.is_open())
    {
        std::cout << "Fail to open " << in << std::endl;
        return 1;
    }

    output << "#include <stdio.h>" << std::endl;
    output << "#include <stdlib.h>" << std::endl;
    output << "#include <string.h>" << std::endl;
    output << "int main() { ";
    output << "char t[60 * 1024];";
    output << "memset(t, 0, 60 * 1024);";
    output << "int i = 0;";

    char c;
    while (input.good())
    {
        input.get(c);
        output << _map[c] << std::endl;
    }
    output << "return 0; }" << std::endl;
    output.close();
    input.close();
    return 0;
}



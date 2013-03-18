/*
** Config.cpp for Params in /Storage/Epitech/Params
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Feb 20 15:49:32 2013 maxime ginters
** Last update Fri Feb 22 12:46:58 2013 maxime ginters
*/

#include <iostream>
#include <stdlib.h>
#include "Config.h"

t_param& t_param::operator=(t_param const& other)
{
    flag_short = other.flag_short;
    flag_long = other.flag_long;
    desc = other.desc;
    type = other.type;
    have_flag = other.have_flag;
    defaut = other.defaut;
    value = other.value;
    return *this;
}

t_param::t_param(t_param const& other) : flag_short(other.flag_short), flag_long(other.flag_long), desc(other.desc),
    type(other.type), have_flag(other.have_flag), defaut(other.defaut), value(other.value)
{}

t_param::t_param() : flag_short(NULL), flag_long(NULL), desc(NULL),
    type(TYPE_NONE), have_flag(false), defaut(NULL), value()
{}

ConfigExcept::ConfigExcept(std::string const& msg) : _msg(msg)
{}

const char* ConfigExcept::what() const throw()
{
    return _msg.c_str();
}

Config::Config() : _params(), _paramValue(), _progName(), _canTakeFile(false)
{
    addParam("-h", "--help", "Display this help", TYPE_FLAG, NULL);
}

Config::~Config()
{
    for (ParamList::iterator itr = _params.begin(); itr != _params.end();)
    {
        t_param* curr = *itr;
        _params.erase(itr++);
        delete curr;
    }
}

Config* Config::instance()
{
    static Config* instance = NULL;
    if (!instance)
        instance = new Config;
    return instance;
}

void Config::addParam(const char* flag_short, const char* flag_long, const char* desc, ParamTypes type, const char* def)
{
    t_param* param = new t_param;
    param->flag_short = flag_short;
    param->flag_long = flag_long;
    param->desc = desc;
    param->type = type;
    param->have_flag = false;
    param->defaut = def;
    param->value = (def == NULL ? "" : def);
    _params.push_back(param);
}

StringList const& Config::getValuesList()
{
    return _paramValue;
}

bool Config::hasFlag(std::string const& flag) const
{
    for (ParamList::const_iterator itr = _params.begin(); itr != _params.end(); ++itr)
    {
        if (t_param* param = *itr)
        {
            if (param->flag_short == flag || param->flag_long == flag)
                return param->have_flag;
        }
    }
    throw ConfigExcept("Error: flag " + flag + " no found");
}

std::string const& Config::getFlagValue(std::string const& flag) const
{
    for (ParamList::const_iterator itr = _params.begin(); itr != _params.end(); ++itr)
    {
        if (t_param* param = *itr)
        {
            if (param->flag_short == flag || param->flag_long == flag)
                return param->value;
        }
    }
    throw ConfigExcept("Error: flag " + flag + " no found");
}

t_param* Config::getParam(std::string const& flag)
{
    size_t pos = flag.find("=");
    for (ParamList::iterator itr = _params.begin(); itr != _params.end(); ++itr)
        if (t_param* param = *itr)
        {
            if (param->flag_short == flag ||
                    (param->type == TYPE_FLAG && param->flag_long == flag) ||
                    (param->type == TYPE_FLAG_AND_VALUE && pos != std::string::npos && param->flag_long == flag.substr(0, pos)))
                return param;
        }
    return NULL;
}

void Config::parseParam(int argc, char** argv)
{
    std::string* ss = new std::string[argc];
    for (int i = 1; i < argc; ++i)
        ss[i - 1] = argv[i];
    _paramValue.clear();
    _progName = argv[0];

    for (int i = 0; i < argc - 1; ++i)
    {
        if (t_param* param = getParam(ss[i]))
        {
            if (param->type == TYPE_FLAG)
                param->have_flag = true;
            else
            {
                if (ss[i].find(param->flag_long) != std::string::npos)
                {
                    size_t pos = ss[i].find("=");
                    if (pos == std::string::npos)
                        throw ConfigExcept("Error: flag " + ss[i] + " have no value");
                    param->value = ss[i].substr(pos + 1);
                    param->have_flag = true;
                    continue;
                }
                else if (i + 1 >= (argc - 1))
                    throw ConfigExcept("Error: flag " + ss[i] + " have no value");
                param->value = ss[++i];
                param->have_flag = true;
            }
        }
        else if (ss[i][0] == '-')
            throw ConfigExcept("Error: unknow flag " + ss[i]);
        else
            _paramValue.push_back(ss[i]);
    }
    if (hasFlag("-h"))
    {
        printHelp();
        exit(0);
    }
}

void Config::printHelp() const
{
    std::cout << "Usage: " << _progName << " " << (_canTakeFile ? "[file] " : " ") << "[options]" << std::endl << std::endl;
    std::cout << "options:" << std::endl;
    for (ParamList::const_iterator itr = _params.begin(); itr != _params.end(); ++itr)
    {
        if (t_param* param = *itr)
        {
            std::cout << "\t" << param->flag_short << ", " << param->flag_long << "\t\t" << param->desc << std::endl;
            if (param->defaut)
                std::cout << "\t\tDefault : " << param->defaut << std::endl;
        }
    }

}

void Config::setCanTakeFile(bool value)
{
    _canTakeFile = value;
}

/*
** Config.h for Params in /Storage/Epitech/Params
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Feb 20 15:49:32 2013 maxime ginters
** Last update Fri Feb 22 12:46:00 2013 maxime ginters
*/

#ifndef CONFIG_H_
# define CONFIG_H_

#include <string>
#include <list>
#include <exception>

enum ParamTypes
{
    TYPE_NONE           = 0,
    TYPE_FLAG           = 1,
    TYPE_FLAG_AND_VALUE = 2
};

struct t_param
{
    const char* flag_short;
    const char* flag_long;
    const char* desc;
    ParamTypes type;
    bool have_flag;
    const char* defaut;
    std::string value;
    t_param& operator=(t_param const& other);
    t_param(t_param const& other);
    t_param();
};

class ConfigExcept : public std::exception
{
public:
    explicit ConfigExcept(std::string const& msg);
    virtual ~ConfigExcept() throw() {}
    const char* what() const throw();
private:
    std::string _msg;
};

typedef std::list<t_param*> ParamList;
typedef std::list<std::string> StringList;

class Config
{
public:
    static Config* instance();
    void addParam(const char* flag_short, const char* flag_long, const char* desc, ParamTypes type, const char* def);
    bool hasFlag(std::string const& flag) const;
    std::string const& getFlagValue(std::string const& flag) const;
    StringList const& getValuesList();
    void setCanTakeFile(bool value);

    void parseParam(int argc, char** argv);
private:
    Config();
    ~Config();

    void printHelp() const;

    t_param* getParam(std::string const& flag);

    ParamList _params;
    StringList _paramValue;
    std::string _progName;
    bool _canTakeFile;
};

#define sConfig Config::instance()

#endif /* !CONFIG_H_ */

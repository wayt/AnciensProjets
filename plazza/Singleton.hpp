/*
** Singleton.hpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Apr 17 11:51:43 2013 maxime ginters
** Last update Wed Apr 17 15:41:53 2013 maxime ginters
*/

#ifndef SINGLETON_H_
# define SINGLETON_H_

#ifndef NULL
# define NULL 0x0
#endif

template<class T>
class Singleton
{
public:
    static T* instance()
    {
        static T* instance = NULL;
        if (!instance)
            instance = new T();
        return instance;
    }
};

#endif /* !SINGLETON_H_ */

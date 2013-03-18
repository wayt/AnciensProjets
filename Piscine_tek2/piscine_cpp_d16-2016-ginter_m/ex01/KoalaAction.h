/*
** KoalaAction.h for ex01 in /home/leroy_v/Epitech/projet_tek2/piscine/Jour_16/ex01
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Thu Jan 24 12:19:56 2013 vincent leroy
** Last update Thu Jan 24 12:24:25 2013 vincent leroy
*/

#ifndef KOALAACTION_H_
# define KOALAACTION_H_

#include <iostream>
#include <string>

class KoalaAction
{
    public:
        KoalaAction();
        virtual ~KoalaAction();

        void eat(const std::string &str);
        void sleep(const std::string &str);
        void goTo(const std::string &str);
        void reproduce(const std::string &str);

    protected:

    private:
};

#endif /* !KOALAACTION_H_ */

/*
** KreogCom.h for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 23:06:22 2013 maxime ginters
** Last update Wed Jan 16 01:37:56 2013 maxime ginters
*/

#ifndef KREOGCOM_H_
# define KREOGCOM_H_

#include <iostream>

class KreogCom
{
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();

    void addCom(int x, int y, int serial);
    KreogCom* getCom();
    void removeCom();

    void ping() const;
    void locateSquad() const;

private:
    KreogCom* _next;
    int _x;
    int _y;
    const int m_serial;
};

#endif /* !KREOGCOM_H_ */

/*
** Setting.h for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 11:15:36 2013 vincent leroy
** Last update Sun Mar 10 07:52:34 2013 vincent leroy
*/

#ifndef SETTING_H_
# define SETTING_H_

#include <QSettings>
#include <QString>

class Setting
{
    public:
        explicit Setting();
        virtual ~Setting();

        QString getIpReceveur() const;
        int getPortReceveur() const;
        QString getProtocol() const;
        QString getIpSender() const;
        int getPortSender() const;
        QString getLogin() const;
        QString getMdp() const;

        void setReceveur(const QString&, int, const QString&);
        void setSender(const QString&, int);
        void setUser(const QString&, const QString&);

    private:
        void _addInfo(const QString&, int);

        QSettings _setting;
};

#endif /* !SETTING_H_ */

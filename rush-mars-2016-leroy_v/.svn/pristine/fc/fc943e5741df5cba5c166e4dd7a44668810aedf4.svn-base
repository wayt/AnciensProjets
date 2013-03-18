/*
** EditAccount.h for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Mar 10 00:08:30 2013 vincent leroy
** Last update Sun Mar 10 01:20:50 2013 vincent leroy
*/

#ifndef EDITACCOUNT_H_
# define EDITACCOUNT_H_

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class EditAccount : public QDialog
{
    Q_OBJECT

    public:
        explicit EditAccount();
        virtual ~EditAccount();

    private:
        QLineEdit *_ipReceveur;
        QComboBox *_portReceveur;
        QLineEdit *_ipSender;
        QComboBox *_portSender;
        QLineEdit *_login;
        QLineEdit *_mdp;
        QFormLayout *_lay;
        QVBoxLayout *_layV;
        QHBoxLayout *_layH;
        QPushButton *_pbOk;
        QPushButton *_pbCancel;

    public slots:
        void show();

    protected slots:
        void _pbOk_clicked();
};

#endif /* !EDITACCOUNT_H_ */

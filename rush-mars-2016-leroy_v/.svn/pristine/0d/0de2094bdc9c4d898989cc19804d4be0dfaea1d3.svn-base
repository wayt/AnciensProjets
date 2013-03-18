/*
** NewMsg.h for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 16:12:41 2013 vincent leroy
** Last update Sat Mar 09 17:07:49 2013 vincent leroy
*/

#ifndef NEWMSG_H_
# define NEWMSG_H_

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class NewMsg : public QDialog
{
    Q_OBJECT

    public:
        explicit NewMsg(QWidget *parent = 0);
        virtual ~NewMsg();

    private:
        QLineEdit *_to;
        QLineEdit *_subject;
        QTextEdit *_mail;
        QLabel *_labelTo;
        QLabel *_labelSubject;
        QHBoxLayout *_layTo;
        QHBoxLayout *_laySubject;
        QVBoxLayout *_layh;
        QPushButton *_pbSend;
        QPushButton *_pbCancel;
        QHBoxLayout *_layButton;

    protected slots:
        void _pbSend_clicked();
};

#endif /* !NEWMSG_H_ */

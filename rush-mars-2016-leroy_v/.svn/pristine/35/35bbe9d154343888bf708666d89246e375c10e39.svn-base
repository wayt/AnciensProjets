/*
** NewMsg.cpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 16:12:38 2013 vincent leroy
** Last update Sun Mar 10 07:48:35 2013 vincent leroy
*/

#include "CMainWindow.h"
#include "NewMsg.h"

extern CMainWindow *w;

NewMsg::NewMsg(QWidget *parent) :
    QDialog(parent),
    _to(new QLineEdit),
    _subject(new QLineEdit),
    _mail(new QTextEdit),
    _labelTo(new QLabel("To :")),
    _labelSubject(new QLabel("Subject :")),
    _layTo(new QHBoxLayout),
    _laySubject(new QHBoxLayout),
    _layh(new QVBoxLayout),
    _pbSend(new QPushButton("Send")),
    _pbCancel(new QPushButton("Cancel")),
    _layButton(new QHBoxLayout)
{
    _layTo->addWidget(_labelTo);
    _layTo->addWidget(_to);
    _laySubject->addWidget(_labelSubject);
    _laySubject->addWidget(_subject);
    _layButton->addWidget(_pbSend);
    _layButton->addWidget(_pbCancel);
    _layh->addLayout(_layTo);
    _layh->addLayout(_laySubject);
    _layh->addWidget(_mail);
    _layh->addLayout(_layButton);
    setLayout(_layh);
    setFixedSize(400, 500);
    setModal(Qt::WindowModal);

    QObject::connect(_pbSend, SIGNAL(clicked()), this, SLOT(_pbSend_clicked()));
    QObject::connect(_pbCancel, SIGNAL(clicked()), this, SLOT(close()));
}

NewMsg::~NewMsg()
{
}

void NewMsg::_pbSend_clicked()
{
    if (!_to->text().contains('@'))
    {
        QMessageBox::critical(this, "Adresse", "The email address " + _to->text() + " isn't valid");
        return ;
    }

    w->sendMsg(_to->text(), _subject->text(), _mail->toPlainText());
    close();
}

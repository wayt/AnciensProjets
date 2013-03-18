/*
** EditAccount.cpp for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sun Mar 10 00:08:24 2013 vincent leroy
** Last update Sun Mar 10 09:49:56 2013 vincent leroy
*/

#include "CMainWindow.h"
#include "EditAccount.h"

extern CMainWindow *w;

EditAccount::EditAccount() :
    QDialog(),
    _ipReceveur(new QLineEdit),
    _portReceveur(new QComboBox),
    _ipSender(new QLineEdit),
    _portSender(new QComboBox),
    _login(new QLineEdit),
    _mdp(new QLineEdit),
    _lay(new QFormLayout),
    _layV(new QVBoxLayout),
    _layH(new QHBoxLayout),
    _pbOk(new QPushButton("Ok")),
    _pbCancel(new QPushButton("Cancel"))
{
    _portReceveur->addItem("143");
    _portReceveur->addItem("110");
    _portSender->addItem("25");
    _ipReceveur->setInputMask("999.999.999.999");
    _ipSender->setInputMask("999.999.999.999");
    _mdp->setEchoMode(QLineEdit::Password);

    _lay->addRow("Ip receveur:", _ipReceveur);
    _lay->addRow("Port receveur:", _portReceveur);
    _lay->addRow("Ip sender:", _ipSender);
    _lay->addRow("Port sender:", _portSender);
    _lay->addRow("Login:", _login);
    _lay->addRow("Mdp:", _mdp);
    _layH->addWidget(_pbOk);
    _layH->addWidget(_pbCancel);
    _layV->addLayout(_lay);
    _layV->addLayout(_layH);
    setLayout(_layV);

    QObject::connect(_pbOk, SIGNAL(clicked()), this, SLOT(_pbOk_clicked()));
    QObject::connect(_pbCancel, SIGNAL(clicked()), this, SLOT(close()));
}

EditAccount::~EditAccount()
{
}

void EditAccount::show()
{
    _ipReceveur->setText(w->getSetting()->getIpReceveur());
    _portReceveur->setCurrentIndex(w->getSetting()->getProtocol() == "IMAP" ? 0 : 1);
    _ipSender->setText(w->getSetting()->getIpSender());
    _login->setText(w->getSetting()->getLogin());
    _mdp->setText(w->getSetting()->getMdp());

    QDialog::show();
}

void EditAccount::_pbOk_clicked()
{
    int port = _portReceveur->currentText().toInt();
    w->getSetting()->setReceveur(_ipReceveur->text(), port, port == 110 ? "POP3" : "IMAP");
    port = _portSender->currentText().toInt();
    w->getSetting()->setSender(_ipSender->text(), port);
    w->getSetting()->setUser(_login->text(), _mdp->text());
    w->reconnect();
    close();
}

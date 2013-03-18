/*
** CMainWindow.h for bmail in /home/leroy_v/Epitech/projet_tek2/bmail
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 12:04:15 2013 vincent leroy
** Last update Sun Mar 10 11:48:19 2013 vincent leroy
*/

#ifndef CMAINWINDOW_H_
# define CMAINWINDOW_H_

#include <QMainWindow>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QToolBar>
#include <QAction>
#include <QTableWidget>
#include <QHeaderView>
#include <QTimer>
#include "NewMsg.h"
#include "EditAccount.h"
#include "Setting.h"
#include "ASocket.h"
#include "AReceveur.h"
#include "Exception.hpp"
#include "IMAP.h"
#include "POP3.h"
#include "SMTP.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit CMainWindow();
        virtual ~CMainWindow();

        void reconnect();
        void majDir();
        Setting* getSetting();
        void sendMsg(const QString&, const QString&, const QString&);

    private:
        void _init();

        QListWidget *_listDir;
        QTableWidget *_listMail;
        QHBoxLayout *_hlay;
        QVBoxLayout *_vlay;
        QTextEdit *_textMail;
        QToolBar *_toolBar;
        QAction *_refresh;
        QAction *_new;
        QAction *_edit;
        QAction *_delete;
        NewMsg *_newMsg;
        Setting *_setting;
        EditAccount *_editAccount;
        QTimer *_timerRefresh;
        Protocol::AReceveur *_socket;
        Protocol::SMTP *_smtp;

    protected slots:
        void _delete_triggered();
        void _refresh_triggered();
        void _new_triggered();
        void _edit_triggered();
        void _listDir_currentRowChanged(int);
        void _listMail_itemPressed(QTableWidgetItem*);
};

#endif /* !CMAINWINDOW_H_ */

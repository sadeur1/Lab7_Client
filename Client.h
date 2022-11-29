#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QSslSocket>
//#include <QMenu>
#include <QMenuBar>
#include <QAction>
//#include <QFile>
#include <QSslKey>
//#include <QByteArray>
//#include <QSslCertificate>
//#include <QSslConfiguration>
//#include <QSslSocket>

#include <QTextEdit>


#include <QDebug>
#include <QMessageBox>
#include <QListWidget>
#include <QSound>
#include <QToolButton>
#include <QtXml>
#include <QFileDialog>
#include <QColorDialog>
//#include <QSettings>


#include "ServerSettingsDialog.h"
#include "savetoxml.h"

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);

private slots:
    void onConnection();
    void onDisconnection();
    void saveXML();
    void onExit();
    void server();
    void userName();
    void isOnline();
    void isOffline();
    void isNotActive();
    void statusYour();
    void aboutMe();
    void Error(QAbstractSocket::SocketError err);
    void sendToServer();
    void sendPic();
    void ready2Read();
    void sslError(QList<QSslError> errors);
    void showContextMenu(const QPoint &pos);
    void disconnected();
    void ContextMenuTextInfo(const QPoint& pos);
    void setAvatar();
    void ChangeBgColor();
    void sendFile();
    void shIP(bool isChecked);
    void shTime(bool isChecked);
    void ChangeMessageColor();

private:
    QList<QPixmap> pictures;
    QPixmap forsave;
    bool fromdisocnnect = false;
    quint64 _nextBlockSize;
    QString _ip = "127.0.0.1";
    int _port = 45678;
    bool isconnect = false;
    QString _status = "Offline";
    QSslCertificate _cert;
    QSslSocket* _socket;
    QWidget* _widget;
    QListWidget* _info;
    QLineEdit* _input;
    QString _username="user";
    QToolButton* _button;
    QListWidget* _users;
    QVector<QString> usersname;
    QVector<QString> usersIP;
    QVector<QString> usersTime;
    QVector<QString> usersStatus;
    QVector<QString> usersMessageTime;
    QSettings* _settings = new QSettings("./Settings.ini", QSettings::IniFormat);
    QAction* yourStatus;
    QList<QAction*> _actions;
    QString avatarChangeName = "";
    bool _showIP = true;
    bool _showTime = true;
    QColor* _color = nullptr;
    void sendname();
    void sendstatus();
    enum arguments{
        comAutchReq = (quint8)1,
        comUsersOnline = (quint8)2,
        comUserRename = (quint8)3,
        comUserLeft = (quint8)4,
        comMessageToAll = (quint8)5,
        comMessageToUsers = (quint8)6,
        comUserStatus = (quint8)7,
        comMessagePic = (quint8)8,
        comUserAvatar = (quint8)9,
        comUserAvatarName = (quint8)201,
        comReconnect = (quint8)202
    };
};
#endif // CLIENT_H

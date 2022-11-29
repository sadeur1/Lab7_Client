#ifndef SERVERSETTINGSDIALOG_H
#define SERVERSETTINGSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class ServerSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    ServerSettingsDialog(QString IP, int Port);
    QString _ip = "127.0.0.1";
    int _port = 45678;
    bool isSaved = 0;
private slots:
    void saveServerProperyies();
    void closeDialog();
private:
    void showDialog();
    QLineEdit* ip;
    QInputDialog* port;
};

#endif // SERVERSETTINGSDIALOG_H

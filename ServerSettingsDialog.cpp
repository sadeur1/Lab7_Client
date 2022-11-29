#include "ServerSettingsDialog.h"

ServerSettingsDialog::ServerSettingsDialog(QString IP, int Port)
{
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    QLabel* label = new QLabel("IP:");
    ip = new QLineEdit;

    port = new QInputDialog;
    QPushButton* saveButton = new QPushButton("Save");
    connect(saveButton, SIGNAL(clicked()),this, SLOT(saveServerProperyies()));
    connect(saveButton, SIGNAL(clicked()),this, SLOT(closeDialog()));
    QPushButton* cancelButton = new QPushButton("Cancel");
    connect(cancelButton, SIGNAL(clicked()),this, SLOT(closeDialog()));

    ip->setText(IP);

    port->setInputMode(QInputDialog::IntInput);
    port->setLabelText("Port:");
    port->setOptions(QInputDialog::NoButtons);
    port->setIntRange(1025, 65535);
    port->setIntValue(Port);

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(label, 0, 0, 1, 1);
    layout->addWidget(ip, 1, 0, 1, 2);
    layout->addWidget(port, 2, 0, 1, 2);
    layout->addWidget(saveButton, 3, 0);
    layout->addWidget(cancelButton, 3, 1);
    setLayout(layout);
    showDialog();
}

void ServerSettingsDialog::saveServerProperyies()
{
    _ip = ip->text();
    _port = port->intValue();
    isSaved = true;
}

void ServerSettingsDialog::showDialog()
{
    this->exec();
}

void ServerSettingsDialog::closeDialog()
{
    this->close();
}

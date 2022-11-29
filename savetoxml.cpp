#include "savetoxml.h"

SaveToXML::SaveToXML(QWidget *parent)
: QDialog(parent)
{
    QGridLayout* lay = new QGridLayout();
    QLabel* label = new QLabel("Filename: messages.xml");
    password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    QCheckBox* show = new QCheckBox("Show");
    connect(show, SIGNAL(stateChanged(int)), SLOT(stateChanged(int)));
    QPushButton* ok = new QPushButton("Ok");
    QPushButton* cancel = new QPushButton("Cancel");
    connect(ok, SIGNAL(clicked()), SLOT(saveResults()));
    connect(cancel, SIGNAL(clicked()), SLOT(cancel()));
    lay->addWidget(label, 0 , 1, 1, 2,Qt::AlignCenter);
    lay->addWidget(password, 1 , 1);
    lay->addWidget(show, 1 , 2);
    lay->addWidget(ok, 2 , 1);
    lay->addWidget(cancel, 2 , 2);
    setLayout(lay);
    exec();
}

void SaveToXML::stateChanged(int i)
{
    if (i==2)
    {
        password->setEchoMode(QLineEdit::Normal);

    }
    else
    {
        password->setEchoMode(QLineEdit::Password);
    }
}

void SaveToXML::saveResults()
{
   isok = true;
   close();
}

void SaveToXML::cancel()
{
   close();
}

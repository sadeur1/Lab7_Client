#ifndef SAVETOXML_H
#define SAVETOXML_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class SaveToXML : public QDialog
{
    Q_OBJECT
public:
    SaveToXML(QWidget *parent = nullptr);
    QLineEdit* password;
    bool isok = false;
private slots:
    void stateChanged(int i);
    void saveResults();
    void cancel();
};

#endif // SAVETOXML_H

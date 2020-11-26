
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>


QT_BEGIN_NAMESPACE
class QLineEdit;

QT_END_NAMESPACE

class Window : public QWidget
{
Q_OBJECT

public:
Window(QWidget *parent = nullptr);
void echoChanged(int);
QPushButton *B1 = new QPushButton ("1");
QPushButton *B2 = new QPushButton ("2");
QPushButton *B3= new QPushButton ("3");
QPushButton *B4 = new QPushButton ("4");
QPushButton *B5 = new QPushButton ("5");
QPushButton *B6 = new QPushButton ("6");
QPushButton *B7 = new QPushButton ("7");
QPushButton *B8 = new QPushButton ("8");
QPushButton *B9 = new QPushButton ("9");
QPushButton *B10 = new QPushButton ("0");

QPushButton *B11 = new QPushButton ("✔");
//QPushButton * Connexion= new QPushButton("Connexion");


QCheckBox *checkbox = new QCheckBox("Masquer",this);

QCheckBox *checkbox1 = new QCheckBox("Masquer",this);




public slots:
void Button();
void Checkbox();
void Valider();
void Message();


private:
QLineEdit *echoLineEdit;
QLineEdit *echoLineEdit1;

QString  Identifiant = "123456789";
QString  Mot_de_passe = "1234";

};
//! [0]

#endif

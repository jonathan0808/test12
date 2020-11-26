#include "Window.h"
#include "ui_Window.h"

#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QCheckBox>
#include <QMessageBox>

#include <QComboBox>


Window::Window(QWidget *parent)
: QWidget(parent)
{

QGroupBox *echoGroup = new QGroupBox(tr("Authentification"));

echoLineEdit = new QLineEdit;
echoLineEdit->setPlaceholderText("Identifiant");

echoLineEdit1= new QLineEdit;
echoLineEdit1->setPlaceholderText("Mot de passe");
echoLineEdit->setMaxLength(9);
echoLineEdit1->setMaxLength(4);
//B11->setStyleSheet("background-color: rgb(0, 255, 0)");

QGridLayout *layout = new QGridLayout;
layout->addWidget(echoGroup, 0, 0);// 0,0 définit la position de notre layout
setLayout(layout);
setWindowTitle(tr("Line Edits"));// définit le titre de l'application


QGridLayout *echoLayout = new QGridLayout;

echoLayout->addWidget(echoLineEdit, 1, 1, 1, 2);
echoLayout->addWidget(echoLineEdit1, 2, 1, 1, 2);
echoGroup->setLayout(echoLayout);

echoLayout->addWidget(B1 , 3 , 1);
echoLayout->addWidget(B2 , 3 , 2);
echoLayout->addWidget(B3 , 3 , 3);
echoLayout->addWidget(B4 , 4, 1);
echoLayout->addWidget(B5 , 4 ,2);
echoLayout->addWidget(B6 , 4 , 3);
echoLayout->addWidget(B7 , 5 , 1);
echoLayout->addWidget(B8 , 5 , 2);
echoLayout->addWidget(B9 , 5 , 3);
echoLayout->addWidget(B10 , 6 , 2);
echoLayout->addWidget(B11 , 6 , 3);


connect(B1, SIGNAL(clicked()), this, SLOT(Button()));
connect(B2, SIGNAL(clicked()), this, SLOT(Button()));
connect(B3, SIGNAL(clicked()), this, SLOT(Button()));
connect(B4, SIGNAL(clicked()), this, SLOT(Button()));
connect(B5, SIGNAL(clicked()), this, SLOT(Button()));
connect(B6, SIGNAL(clicked()), this, SLOT(Button()));
connect(B7, SIGNAL(clicked()), this, SLOT(Button()));
connect(B8, SIGNAL(clicked()), this, SLOT(Button()));
connect(B9, SIGNAL(clicked()), this, SLOT(Button()));


connect(checkbox, SIGNAL(clicked()), this, SLOT(Checkbox()));
connect(checkbox1, SIGNAL(clicked()), this, SLOT(Checkbox()));

connect(B11, SIGNAL(clicked()), this, SLOT(Valider()));
//connect(Connexion, SIGNAL(clicked()), this, SLOT(Message()));


//echoLayout->addWidget(Connexion , 7, 2);
echoLayout->addWidget(checkbox ,1,3);
echoLayout->addWidget(checkbox1 ,2,3);


echoLineEdit1->setDisabled(true);


}

void Window::Button()
{
  QPushButton *button = (QPushButton *)sender();

  int N_bouton= (button->text()[0].digitValue());

  if(echoLineEdit1->focusWidget()){
    echoLineEdit1->setText(echoLineEdit1->text()+ QString::number(N_bouton));
  }else if(echoLineEdit->focusWidget()){
    echoLineEdit->setText(echoLineEdit->text()+ QString::number(N_bouton));
}

 }





void Window::Checkbox()
{ if (checkbox->isChecked())
    {
      echoLineEdit->setEchoMode(QLineEdit::Password);
    }else if(!checkbox->isChecked())

    { echoLineEdit->setEchoMode(QLineEdit::Normal);
    }
    if (checkbox1->isChecked())
        {
          echoLineEdit1->setEchoMode(QLineEdit::Password);
        }else if(!checkbox1->isChecked())

        { echoLineEdit1->setEchoMode(QLineEdit::Normal);
        }
}


void Window::Valider(){


    echoLineEdit1->setDisabled(false);

    if(echoLineEdit ->text() == "123456789")
       { echoLineEdit1->setEnabled(true);
       if (echoLineEdit1->text() == "1234"){
            Message();
}
}
    else {

echoLineEdit1->setDisabled(true);
QMessageBox msgBox;
msgBox.setText("ERREUR");
msgBox.exec();

}
}


void Window::Message(){



if (echoLineEdit1->text() == "1234"){
    QMessageBox msgBox;
    msgBox.setText("Connexion reussie");
    msgBox.exec();

  }

}


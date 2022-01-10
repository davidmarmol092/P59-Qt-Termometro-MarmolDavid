#include "termometro.h"
#include "ui_termometro.h"

#include <QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);
    // Conecto dialCent ---> cent2fahr
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));
    // Conectar dialFahr ---> fahr2cent
    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    //conectar dialKelv ---> cent2fahr//
    connect(ui->cmdKelv, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kelv(int)));
}

Termometro::~Termometro()
{
    delete ui;
}

//cent a fahr
void Termometro::cent2fahr(int valor)
{
    if (ui->cmdCent->hasFocus()){
        float f = valor * (9.0/5) + 32;
        ui->cmdFahr->setValue(f);
        float ck = valor + 273.15;
        ui->cmdKelv->setValue(ck);
        qDebug()<<f<<"-"<<valor;

    }
}

//far a cent
void Termometro::fahr2cent(int valor)
{
    if (ui->cmdFahr->hasFocus()){
        float c = (valor - 32) * (5.0/9);
        ui->cmdCent->setValue(c);

        float fk = (valor - 32) + (5.0/9);
        ui->cmdKelv->setValue(fk);
        qDebug()<<""<<fk<<"-"<<c;
    }
}


void Termometro::cent2kelv(int valor)
{

    if (ui->cmdKelv->hasFocus()){
        float ck = valor - 273.15;

        ui->cmdCent->setValue(ck);
        float fk=(valor-32)*5.0/9+273.15;
        ui->cmdFahr->setValue(fk);


        qDebug()<<ck<<"-"<<fk<<"-"<<valor;
    }
}




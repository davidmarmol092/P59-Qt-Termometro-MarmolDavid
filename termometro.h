#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro; }
QT_END_NAMESPACE

class Termometro : public QMainWindow
{
    Q_OBJECT

public:
    Termometro(QWidget *parent = nullptr);
    ~Termometro();

public slots:
    void cent2fahr(int);
    void fahr2cent(int);
    void cent2kelv(int);

private:
    Ui::Termometro *ui;
};
#endif // TERMOMETRO_H

#ifndef GESTION_COMMANDE_H
#define GESTION_COMMANDE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_commande; }
QT_END_NAMESPACE

class Gestion_commande : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_commande(QWidget *parent = nullptr);
    ~Gestion_commande();

private:
    Ui::Gestion_commande *ui;
};
#endif // GESTION_COMMANDE_H

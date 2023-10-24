#include "gestion_commande.h"
#include "ui_gestion_commande.h"

Gestion_commande::Gestion_commande(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_commande)
{
    ui->setupUi(this);
}

Gestion_commande::~Gestion_commande()
{
    delete ui;
}


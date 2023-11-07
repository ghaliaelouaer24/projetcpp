#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class commande
{public:
    commande();
    commande (int id,QString datec,int total, int qte);
    QString get_datec();
    int get_id();
    int get_total();
    int get_qte();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id, QString datec);
    QSqlQueryModel * chercher_commande (int id);
private:
    int id;
    QString datec;
    int total;
    int qte;
};
#endif // COMMANDE_H

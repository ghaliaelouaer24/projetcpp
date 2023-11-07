#include "commande.h"
#include <QDebug>
commande::commande()
{
id=0;
datec="01/02/2023";
total=0;
qte=0;


}
commande::commande (int id,QString datec,int total,int qte)
{
  this->id=id;
  this->datec=datec;
  this->total=total;
  this->qte=qte;
}

QString commande::get_datec(){return  datec;}
int commande::get_id(){return  id;}
int commande::get_total(){return total;}
int commande::get_qte(){return qte;}


bool commande::ajouter()
{
QSqlQuery query;
QString ch_id= QString::number(id);
QString ch_total=QString::number(total);
QString ch_qte=QString::number(qte);

query.prepare("insert into COMMANDE (id,datec,total,qte)""values (:id, :datec, :total, :qte)");
query.bindValue(":id", ch_id);
query.bindValue(":datec", datec);
query.bindValue(":total", ch_total);
query.bindValue(":qte", ch_qte);
return    query.exec();
}

QSqlQueryModel * commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEC"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QTE"));

    return model;
}

bool commande::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from commande where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool commande::modifier(int id, QString datec)
{
    QSqlQuery query;
        query.prepare("UPDATE COMMANDE SET datec = :datec WHERE id = :id");
        query.bindValue(":datec", datec);
        query.bindValue(":id", id);
        return query.exec();


}
QSqlQueryModel * commande::chercher_commande(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
          QSqlQuery query;
          query.prepare("SELECT * FROM COMMANDE WHERE ID = :id");
          query.bindValue(":id", id);
          query.exec();

          model->setQuery(query);

           return model;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include "commande.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    commande c;
ui->setupUi(this);
ui->tabcommande->setModel(c.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    commande c1;
    int id_commande=ui->lineEdit_id->text().toInt();
    QString datec_commande=ui->lineEdit_datec->text();
    int total_commande=ui->lineEdit_total->text().toInt();
    int qte_commande=ui->lineEdit_qte->text().toInt();
  commande c(id_commande,datec_commande,total_commande,qte_commande);
  bool test=c.ajouter();
  if(test)
{ui->tabcommande->setModel(c1.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("commande ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpcommande.supprimer(id);
if(test)
{ui->tabcommande->setModel(tmpcommande.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                QObject::tr("commande supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_modif_clicked()
{
    commande cm;
    int id = ui->lineEdit_id->text().toInt();
            QString datec = ui->lineEdit_datec->text();

            bool test = cm.modifier(id, datec);

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Modification effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabcommande->setModel(cm.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Modification non effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_chercher_clicked()
{
    commande c;
    int id=ui->lineEdit_id_recherche->text().toInt();
        ui->tableView_rech->setModel(c.chercher_commande(id));
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
            query.exec("SELECT * FROM COMMANDE");

            QPdfWriter pdfWriter("exported_data.pdf");
            pdfWriter.setPageSize(QPageSize(QPageSize::A4));

            pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20));

            QTextDocument pdfDoc;
            pdfWriter.setPageSize(QPageSize(QPageSize::A4));

            pdfDoc.setDocumentMargin(20);

            QTextCursor cursor(&pdfDoc);

            while (query.next()) {
                int id = query.value("id").toInt();
                QString datec = query.value("datec").toString();
                int total = query.value("total").toInt();
                int qte = query.value("qte").toInt();


                cursor.insertText("Identifiant de la commande: "  + QString::number(id) +"\n");
                cursor.insertText("date de la commande: " + datec + "\n");
                cursor.insertText("total de la commande : " + QString::number(total) +"\n");
                cursor.insertText("quantité de la commande : " + QString::number(qte) + "\n");

                cursor.insertText("\n");
            }

            pdfDoc.print(&pdfWriter);

            QDesktopServices::openUrl(QUrl("exported_data.pdf"));
}

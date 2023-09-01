#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QTime>
#include <QDialog>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillTableRandomly();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Функції
void MainWindow::fillTableRandomly()
{
    QTableWidget *tableWidget = ui->tableWidget;
    tableWidget->setRowCount(4);
    tableWidget->setColumnCount(4);

    QRandomGenerator *generator = QRandomGenerator::global();

    int xCount = 0; // Кількість хрестиків
    int oCount = 0; // Кількість нуликів

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int randomValue = generator->bounded(3);
            QString cellValue;

            if ((xCount < 8 && randomValue == 0) || oCount == 8) {
                cellValue = "X"; // Хрестик
                xCount++;
            } else if (oCount < 8) {
                cellValue = "O"; // Нулик
                oCount++;
            } else {
                cellValue = ""; // Пробіл
            }

            QTableWidgetItem *item = new QTableWidgetItem(cellValue);
            tableWidget->setItem(row, col, item);
        }
    }
}

void MainWindow::replaceCharacters()
{
    QTableWidget *tableWidget = ui->tableWidget;
    int rowCount = tableWidget->rowCount();
    int colCount = tableWidget->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            if (item) {
                QString cellValue = item->text();
                if (cellValue == "X") {
                    cellValue = "O"; // Замінити X на O
                } else if (cellValue == "O") {
                    cellValue = "X"; // Замінити O на X
                }
                item->setText(cellValue);
            }
        }
    }
}




//Кнопки
void MainWindow::on_btnTranspose_clicked()
{
    QTableWidget *tableWidget = ui->tableWidget;
    int rowCount = tableWidget->rowCount();
    int colCount = tableWidget->columnCount();


    QTableWidget *newTableWidget = new QTableWidget(colCount, rowCount);


    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            if (item) {
                QString cellValue = item->text();
                QTableWidgetItem *newItem = new QTableWidgetItem(cellValue);
                newTableWidget->setItem(col, row, newItem);
            }
        }
    }


    newTableWidget->show();
}

void MainWindow::on_pushButton_clicked()
{
    replaceCharacters();
}


void MainWindow::on_pushButton_2_clicked()
{
    QTableWidget *tableWidget = ui->tableWidget;
    tableWidget->setRowCount(4);
    tableWidget->setColumnCount(4);

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem("");
            tableWidget->setItem(row, col, item);
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    fillTableRandomly();
}


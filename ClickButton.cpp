#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	qDebug() << "Connect sie powiodl?" << connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonOK_clicked()
{
	qDebug() << "Wcisnałes przycisk OK";
}

void MainWindow::myCustomSlot()
{
	qDebug() << "Wcisnales przycisk Test i wykorzystales mechanizm sygnalow i slotow";
}

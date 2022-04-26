#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionFile_triggered()
{

}



void MainWindow::on_actionNew_triggered()
{
    f_path_ = "";
    ui->textEdit->setText("");
}



void MainWindow::on_actionOpen_triggered()
{
    QString f_name = QFileDialog::getOpenFileName(this,"Open");
    QFile file(f_name);
    f_path_ = f_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not Open");
        return;
    }
    QTextStream x(&file);
    QString text = x.readAll();
    ui->textEdit->setText(text);
    file.close();
}




void MainWindow::on_actionSave_triggered()
{
    QFile file(f_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not Open");
        return;
    }
    QTextStream x(&file);
    QString text = ui->textEdit->toPlainText();
    x << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString f_name = QFileDialog::getSaveFileName(this,"Open");
    QFile file(f_name);
    f_path_ = f_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not Open");
        return;
    }
    QTextStream x(&file);
    QString text = ui->textEdit->toPlainText();
    x << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
       ui->textEdit->setFontWeight(1000);
}


void MainWindow::on_actionSuper_Script_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Name : Tirtha Ghosh\nCollege : RKMGEC\nMajor : B.Tech in CSE\nSkills : C++,JS,HTML,CSS,Python,Node.js\nProjects : Web Game and Food Delivary Website\nAchievements : Google Kickstart- 10000 rank\nHackerrank Certified\nWon Hackathons");
    msgBox.exec();
}


void MainWindow::on_actionFonts_triggered()
{
    bool fontSelected;
        QFont font = QFontDialog::getFont(&fontSelected, this);
        if (fontSelected)
            ui->textEdit->setFont(font);
}


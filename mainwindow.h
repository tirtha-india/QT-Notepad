#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionFile_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionSuper_Script_triggered();

    void on_actionSubscript_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionAbout_triggered();

    void on_actionFonts_triggered();

private:
    Ui::MainWindow *ui;
    QString f_path_;
};
#endif // MAINWINDOW_H

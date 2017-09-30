#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

enum ActionFlag {
    NoAction,
    AdditionFlag,
    SubtractionFlag,
    MultiplicationFlag,
    DivisionFlag
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ActionFlag currentAction;
    QString lastNumber;
    QString currentNumber;
    bool isEmpty;

    QDialog *selectDialog;
    QComboBox *selectCombo;

public slots:
    void clear();
    void actionChanged();
    void inputNumber();
    void displayNumber();
    void negationClicked();
    void percentageClicked();
    void decimalPointClicked();
    void evaluationClicked();
    
    void aboutApp();

    void unitSelect();
    void unitCalc();
};

#endif // MAINWINDOW_H

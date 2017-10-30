#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QComboBox>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentAction(NoAction),
    isEmpty(false)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint);

    connect(ui->btnClear,           SIGNAL(clicked(bool)),this,SLOT(clear()));
    //connect(ui->btnClear,           &QPushButton::click,this,&MainWindow::clear);
    connect(ui->btnNegativity,      SIGNAL(clicked(bool)),this,SLOT(negationClicked()));
    connect(ui->btnPercentage,      SIGNAL(clicked(bool)),this,SLOT(percentageClicked()));
    connect(ui->btnDecimalPoint,    SIGNAL(clicked(bool)),this,SLOT(decimalPointClicked()));
    connect(ui->btnEvaluation,      SIGNAL(clicked(bool)),this,SLOT(evaluationClicked()));

    connect(ui->btnAddition,        SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnSubtraction,     SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnMultiplication,  SIGNAL(clicked(bool)),this,SLOT(actionChanged()));
    connect(ui->btnDivision,        SIGNAL(clicked(bool)),this,SLOT(actionChanged()));

    connect(ui->btnNum0,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum1,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum2,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum3,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum4,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum5,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum6,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum7,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum8,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));
    connect(ui->btnNum9,            SIGNAL(clicked(bool)),this,SLOT(inputNumber()));

    connect(ui->actionAboutQt,      SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));
    connect(ui->actionAbout,        SIGNAL(triggered(bool)),this,SLOT(aboutApp()));

    connect(ui->actionUnitSelect,   SIGNAL(triggered(bool)),this,SLOT(unitSelect()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clear()
{
    if(ui->btnClear->text() == "AC")
    {
        currentAction = NoAction;
        lastNumber = "0";
        currentNumber = "0";
        isEmpty = true;
    }
    else if(ui->btnClear->text() == "C") {
        ui->btnClear->setText("AC");
        currentNumber = "0";
        isEmpty = true;
    }
    displayNumber();
}
void MainWindow::actionChanged()
{
    QPushButton *button = qobject_cast<QPushButton *>(this->sender());
    if(button)
    {
        isEmpty = false;

        if(button == ui->btnAddition)
        {
            currentAction = AdditionFlag;
            statusBar()->showMessage("Addition Selected",3000);
        }
        else if (button == ui->btnSubtraction) {
            currentAction = SubtractionFlag;
            statusBar()->showMessage("Subtraction Selected",3000);
        }
        else if (button == ui->btnMultiplication) {
            currentAction = MultiplicationFlag;
            statusBar()->showMessage("Multiplication Selected",3000);
        }
        else if (button == ui->btnDivision) {
            currentAction = DivisionFlag;
            statusBar()->showMessage("Division Selected",3000);
        }
        else {
            currentAction = NoAction;
        }
    }
}

void MainWindow::inputNumber()
{
    QPushButton *button = qobject_cast<QPushButton *>(this->sender());
    if(button)
    {
        ui->btnClear->setText("C");

        if(!isEmpty)
        {
            lastNumber = currentNumber;
            currentNumber.clear();
            isEmpty = true;
        }
        if(currentNumber == "0") //clear the zero when new numbers are input.
        {
            currentNumber.clear();
        }
        if(button == ui->btnNum0)
        {
            currentNumber.append("0");
            statusBar()->showMessage("You input 0",3000);
        }
        if(button == ui->btnNum1)
        {
            currentNumber.append("1");
            statusBar()->showMessage("You input 1",3000);
        }
        if(button == ui->btnNum2)
        {
            currentNumber.append("2");
            statusBar()->showMessage("You input 2",3000);
        }
        if(button == ui->btnNum3)
        {
            currentNumber.append("3");
            statusBar()->showMessage("You input 3",3000);
        }
        if(button == ui->btnNum4)
        {
            currentNumber.append("4");
            statusBar()->showMessage("You input 4",3000);
        }
        if(button == ui->btnNum5)
        {
            currentNumber.append("5");
            statusBar()->showMessage("You input 5",3000);
        }if(button == ui->btnNum6)
        {
            currentNumber.append("6");
            statusBar()->showMessage("You input 6",3000);
        }if(button == ui->btnNum7)
        {
            currentNumber.append("7");
            statusBar()->showMessage("You input 7",3000);
        }if(button == ui->btnNum8)
        {
            currentNumber.append("8");
            statusBar()->showMessage("You input 8",3000);
        }if(button == ui->btnNum9)
        {
            currentNumber.append("9");
            statusBar()->showMessage("You input 9",3000);
        }

        displayNumber();
    }
}
void MainWindow::displayNumber()
{
    ui->label->setText(currentNumber);
}
void MainWindow::negationClicked()
{
    if(!isEmpty || (currentNumber.size() == 0))
    {
        isEmpty = true;
        currentNumber = "0";
    }
    else {
        if(currentNumber.at(0) == '-')
        {
            currentNumber.remove(0,1);
        }
        else {
            currentNumber.push_front("-");
        }
    }
    statusBar()->showMessage("Sign Modified",3000);
    displayNumber();
}

void MainWindow::percentageClicked()
{
    if(!isEmpty)
    {
        isEmpty = true;
        currentNumber = "0";
    }
    else
    {
        double number = currentNumber.toDouble() / 100.0;
        currentNumber = QString::number(number);
    }
    statusBar()->showMessage("Percentage",3000);
    displayNumber();
}
void MainWindow::decimalPointClicked()
{
    if(!isEmpty)
    {
        currentNumber = "0.";
        isEmpty = true;
    }
    else if(currentNumber.indexOf(".") == -1)
    {
        currentNumber.push_back(".");
    }

    statusBar()->showMessage("Decimal Point",3000);
    displayNumber();
}

void MainWindow::evaluationClicked()
{
    if(currentAction == NoAction)
    {
        statusBar()->showMessage("Please select a operation",3000);
        return;
    }
    switch (currentAction) {
    case AdditionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() + currentNumber.toDouble());
        break;
    }
    case SubtractionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() - currentNumber.toDouble());
        break;
    }
    case MultiplicationFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() * currentNumber.toDouble());
        break;
    }
    case DivisionFlag:
    {
        currentNumber = QString::number(lastNumber.toDouble() / currentNumber.toDouble());
        break;
    }
    default:
        break;
    }
    statusBar()->showMessage("Finished",3000);
    currentAction = NoAction;
    displayNumber();
}

void MainWindow::aboutApp()
{
    QMessageBox::about(this,"About","Demo");
}
void MainWindow::unitSelect()
{
    selectDialog = new QDialog(this);

    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *displayLabel;

    selectDialog->resize(400, 150);

    buttonBox = new QDialogButtonBox(selectDialog);
    buttonBox->setGeometry(30, 100, 341, 32);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    groupBox = new QGroupBox(selectDialog);
    groupBox->setGeometry(10, 10, 180, 80);
    groupBox->setTitle("Value");
    groupBox_2 = new QGroupBox(selectDialog);
    groupBox_2->setGeometry(210, 10, 180, 80);
    groupBox_2->setTitle("Unit");

    displayLabel = new QLabel(ui->label->text(),groupBox);
    displayLabel->setGeometry(10, 40, 120, 16);

    selectCombo = new QComboBox(groupBox_2);
    selectCombo->setGeometry(10, 40, 120, 26);
    selectCombo->clear();
    selectCombo->insertItem(0,"Metre->Centimetre");
    selectCombo->insertItem(1,"Metre->Square metre");

    connect(buttonBox,SIGNAL(rejected()),selectDialog,SLOT(deleteLater()));
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(unitCalc()));

    selectDialog->exec();
}
void MainWindow::unitCalc()
{
    switch (selectCombo->currentIndex()) {
    case 0:
        currentNumber = QString::number(currentNumber.toDouble() * 100);
        break;
    case 1:
        currentNumber = QString::number(pow(currentNumber.toDouble(),2));
    default:
        break;
    }
    selectDialog->deleteLater(); //  close and delete the selectDialog after calculations.
    displayNumber();
}

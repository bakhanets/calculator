#include "mainwindow.h"
#include "ui_mainwindow.h"


double num_first;
const double pi=3.141592653589793238463;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_tg,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ctg,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_rad,SIGNAL(clicked()),this,SLOT(operations()));




    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));


    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton * button = static_cast<QPushButton*>(sender());
   double all_numbers;
   QString new_label;
   if(ui->result_show->text().contains(".")&& button->text()=="0"){
       new_label=ui->result_show->text()+button->text();
   }else{



   all_numbers=(ui->result_show->text()+button->text()).toDouble();
   new_label = QString::number(all_numbers,'g',15);
}
   ui->result_show->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text()+".");
}
void MainWindow::operations() // для синуса косинуса тангенса котангенса +/- %
{
   QPushButton * button = static_cast<QPushButton*>(sender());
   double all_numbers;
   QString new_label;

   if(button->text()=="+/-"){

   all_numbers=(ui->result_show->text()).toDouble();
   all_numbers=all_numbers* -1;
   new_label = QString::number(all_numbers,'g',15);
   ui->result_show->setText(new_label);

   }else if(button->text()=="%"){

       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=all_numbers* 0.01;
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }else if (button->text()=="sin") {
       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=sin(all_numbers);
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }else if (button->text()=="cos") {
       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=cos(all_numbers);
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }else if (button->text()=="tg") {
       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=tan(all_numbers);
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }else if (button->text()=="ctg") {
       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=cos(all_numbers)/sin(all_numbers);
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }else if (button->text()=="rad->gr") {
       all_numbers=(ui->result_show->text()).toDouble();
       all_numbers=all_numbers*180/pi;
       new_label = QString::number(all_numbers,'g',15);
       ui->result_show->setText(new_label);
   }

}
void MainWindow::math_operations()// функция для +-*/
{
    QPushButton * button = static_cast<QPushButton*>(sender());
    button->setChecked(true);
    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");

}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_equally_clicked()
{

    double labelNumber,num_second;
    QString new_label;


    num_second = ui->result_show->text().toDouble();



    if(ui->pushButton_plus->isChecked()){
        labelNumber=num_first+num_second;

        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_minus->isChecked()){
        labelNumber=num_first-num_second;

        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    } else if (ui->pushButton_divide->isChecked()){

        if (num_second == 0){
            ui->result_show->setText("На ноль делить нельзя");
        }
        else{
        labelNumber=num_first/num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        }

        ui->pushButton_divide->setChecked(false);

    } else if (ui->pushButton_multiply->isChecked()){
        labelNumber=num_first*num_second;

        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
}

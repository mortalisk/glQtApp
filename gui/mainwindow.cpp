#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGLWidget>
#include <QPushButton>
#include "sketchglwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout * mainLayout = new QVBoxLayout();
    QHBoxLayout * menuLayout = new QHBoxLayout();
    centralWidget()->setLayout(mainLayout);
    QPushButton * makeSplineButton = new QPushButton("A Button");
    menuLayout->addWidget(makeSplineButton);
    mainLayout->addLayout(menuLayout);

    glFormat = new QGLFormat;
    // this means we can use the old fixed function pipeline
    glFormat->setProfile(QGLFormat::CompatibilityProfile);//CoreProfile);
    // this means we can only use the new programmambe pipeline
    //glFormat->setProfile(QGLFormat::CoreProfile);

    glFormat->setVersion(3,3);
    MyGLWidget * gl = new MyGLWidget(glFormat);
    mainLayout->addWidget(gl);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete glFormat;
}

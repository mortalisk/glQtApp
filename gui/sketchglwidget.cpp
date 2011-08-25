#include <GL/glew.h>
#include "sketchglwidget.h"
#include <iostream>
#include <QTimer>

MyGLWidget::MyGLWidget(QGLFormat * glf, QWidget *parent) :
        QGLWidget(*glf,parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    // To hide cursor
    // setCursor( QCursor( Qt::BlankCursor ) );
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));

    // aim for 25 fps
    timer->start(25);

}

void MyGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);


    glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.5,0.5);
    glVertex3f(-1.0,-1.0,0.0);
    glColor3f(0.5,0.8,0.5);
    glVertex3f(1.0,-1.0,0.0);
    glColor3f(0.5,0.5,0.8);
    glVertex3f(0.0,1.0,0.0);
    glEnd();
}

void MyGLWidget::initializeGL() {
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      std::cerr <<  "Error: " << glewGetErrorString(err) << std::endl;
    }

    glClearColor(0.7,0.7,1.0,1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

#ifndef SKETCHGLWIDGET_H
#define SKETCHGLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMap>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    // Handy to keep track of which buttons are pressed
    QMap<int,bool> keys;
    QMap<int,bool> mouse;
    float aspect;

public:
    explicit MyGLWidget(QGLFormat *glf,QWidget *parent = 0);
    void paintGL();
    void initializeGL();

    void enterEvent(QEvent *) {
        setFocus();
    }

    void keyPressEvent(QKeyEvent * e) {
        if (!e->isAutoRepeat()) {
            keys[e->key()] = true;
        }

    }

    void keyReleaseEvent(QKeyEvent * e) {
        if (!e->isAutoRepeat()) {
            keys[e->key()] = false;
        }

    }

    bool isKeyPressed(int key) {
        return keys[key];
    }

    void mousePressEvent(QMouseEvent * e) {
        mouse[e->button()] = true;
    }

    void mouseReleaseEvent(QMouseEvent * e) {
        mouse[e->button()] = false;
    }

    bool isMousePressed(int button) {
        return mouse[button];
    }

    void mouseMoveEvent(QMouseEvent *e) {

    }

    void resizeGL(int w, int h) {
       aspect = w/(float)h;
       glViewport(0,0,w,h);
    }

    void checkInput();

signals:

public slots:
    void animate() {
        updateGL();
    }

};

#endif // SKETCHGLWIDGET_H

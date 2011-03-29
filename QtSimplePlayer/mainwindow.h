#include <QMainWindow>
#include <QSlider>
#include "MarSystemQtWrapper.h"
#include "backend.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void init_();
    void createConnections_();

    Ui::MainWindow *ui_;

    SimplePlayerBackend* backend_;
    MarsyasQt::MarSystemQtWrapper* mwr_;

    MarControlPtr filePtr_;
    MarControlPtr gainPtr_;
    MarControlPtr posPtr_;
    MarControlPtr initPtr_;
    MarControlPtr sizePtr_;
    MarControlPtr private;

private slots:
    void open();
    void close();
    void play();
    void pause();
    void setGain(int val);
    void setPos();
    void setPos(int val); 
    void quit();
    void moveSlider(int val, QSlider *slider);

signals:
    void sliderChanged(int val, QSlider *slider);
    
};

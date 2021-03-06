#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QWidget>
#include <QtSql>
#include <QTableView>
#include <QSlider>
#include <QTimeEdit>
#include "MarSystemQtWrapper.h"
#include "backend.h"

namespace Ui {
    class Transport;
}

class Transport : public QWidget
{
    Q_OBJECT

public:
    static Transport* getInstance()
    {
        static Transport* instance = new Transport();
        return instance;
    }
    ~Transport();
    void open(QString fileName);
    void open();
    void close();
    void play();
    void pause();
    string getCollectionFile();
    int getCurrentFileId();
    QString getCurrentFile();
    
private:
    explicit Transport(QWidget *parent = 0);
    Transport(Transport const& copy);
    Transport& operator=(Transport const& copy);
    
    void init_();
    void createConnections_();
    void initPlayTable_(QString fileName);
    void populateDb_(QSqlDatabase db_, bool load = false);
    
    Ui::Transport *ui_;

    SimplePlayerBackend *backend_;
    MarsyasQt::MarSystemQtWrapper *mwr_;

    QSqlRelationalTableModel *stimuli_model_;
    QTableView *stimuli_table_;

    QTimer *timer_;

    bool playOnce_;
    mrs_string playOnceFile_;
    map<mrs_string, int> collectionFilesMap_;
    mrs_string currentFile_;

    MarControlPtr filenamePtr_;
    MarControlPtr posPtr_;
    MarControlPtr gainPtr_;
    MarControlPtr initAudioPtr_;
    MarControlPtr sizePtr_;
    MarControlPtr osratePtr_;

    MarControlPtr hasDataPtr_;
    MarControlPtr activePtr_;
    
    MarControlPtr numFilesPtr_;
    MarControlPtr allfilenamesPtr_;
    MarControlPtr currentlyPlayingPtr_;
    MarControlPtr previouslyPlayingPtr_; 
   
    MarControlPtr nLabelsPtr_;
    MarControlPtr labelNamesPtr_;
    MarControlPtr currentLabelPtr_;

    MarControlPtr advancePtr_;
    MarControlPtr cindexPtr_;
    MarControlPtr currentCollectionNewFilePtr_;
    MarControlPtr currentLastTickWithData_;

    MarControlPtr currentHasDataPtr_;
                           
                                              
public slots:
    void playOnce();

private slots:
    void togglePlay();
    void previous();
    void next();
    void setGain(int val);
    void update();
    void setPos(int val); 
    void moveSlider(int val, QSlider *slider);
    void setTime(int val, QTimeEdit *time);
    void setCurrentFile(mrs_string file, QTableView *table);

signals:
    void sliderChanged(int val, QSlider *slider);
    void timeChanged(int val, QTimeEdit *time);
    void fileChanged(mrs_string file, QTableView *table);
    void isPaused(bool flag);
};

#endif // TRANSPORT_

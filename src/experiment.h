#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QMainWindow>
#include <QTableView>
#include <QSqlTableModel>
#include <QtSql>

#include "transport.h"
#include "tagger.h"

namespace Ui {
    class Experiment;
}

class Experiment : public QMainWindow
{
    Q_OBJECT

public:
    static Experiment* getInstance()
    {
        static Experiment* instance = new Experiment();
        return instance;
    }
    ~Experiment();
    void init(QString fileName, bool overwrite);
    QSqlDatabase getDb();
    Transport* getTransport();
    Tagger* getTagger();
    int getCurrentSubjectId();
    int getValue(QString tag);
    bool rowExists(QString tag);
    map<QString, QString> getCurrentSubject();
    void addSubject(QString name, int age, bool paid, QString gender, bool nonmusician, QString country, bool active);

private:
    explicit Experiment(QWidget *parent = 0);
    Ui::Experiment *ui_;
    QSqlDatabase db_;
    Transport *transport_;
    Tagger *tagger_;
    QSqlRelationalTableModel *subjects_model_;
    QTableView *subjects_table_;
    
    void populateTagsTable_();
    void populateStimuliTable_();
    void populateSubjectsTable_();
    void createConnections_();

public slots:
    void openCollectionFile();
    void close();
    void updateValue(QString tag, int value, QString note = "");
    void updateNote(QString note);
    void addSubject();
    void removeSubject();

signals:
    void experimentConfigured();

};

#endif // EXPERIMENT_H

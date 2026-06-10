#ifndef MFORMWORKSTEP_H
#define MFORMWORKSTEP_H

#include <QWidget>
#include "MFormJLStation.h"

namespace Ui {
class MFormWorkStep;
}

class MFormWorkStep : public QWidget
{
    Q_OBJECT

public:
    explicit MFormWorkStep(QWidget *parent = nullptr);
    ~MFormWorkStep();
    Ui::MFormWorkStep *ui;
    void save_File_INI(const QString channel);
    short Load_Work_ChannelPars(QString channel);

    void download_Objects(const QString &arg1);
    void upload_Objects(const QString &arg1);
private slots:
    void on_Channel_currentTextChanged(const QString &arg1);

    void on_Btn_Sure_clicked();
    void on_Btn_Use_clicked();
private:

};

extern MFormWorkStep *m_MFormWorkStep;
#endif // MFORMWORKSTEP_H

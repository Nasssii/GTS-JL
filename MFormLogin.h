#ifndef MFORMLOGIN_H
#define MFORMLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "MFormJLStation.h"

namespace Ui {
class MFormLogin;
}

class MFormLogin : public QDialog
{
    Q_OBJECT

public:
    explicit MFormLogin(QWidget *parent = nullptr);
    ~MFormLogin();

    Ui::MFormLogin *ui;
    QString _passwrod = "111111";
    bool B_channgePassword = false;

    void load_INI_File();

    void upload_Objects(const QString &arg1);
    void download_Objects(const QString &arg1);
private slots:
    void on_BTN_OK_clicked();

private:

};
extern MFormLogin *m_FormLogin;

#endif // MFORMLOGIN_H

#ifndef MFORM_PRODUCTTIPS_H
#define MFORM_PRODUCTTIPS_H

#include <QDialog>
#include <QSettings>
#include <QTextCodec>
#include <QGroupBox>
#include <QPushButton>

namespace Ui {
class MForm_ProductTips;
}

class MForm_ProductTips : public QDialog
{
    Q_OBJECT

public:
    explicit MForm_ProductTips(QWidget *parent = nullptr);
    ~MForm_ProductTips();

    void upload_Objects(const QString &arg1);
    void download_Objects(const QString &arg1);
private:
    Ui::MForm_ProductTips *ui;
};
extern MForm_ProductTips *m_Form_ProductTips;
#endif // MFORM_PRODUCTTIPS_H

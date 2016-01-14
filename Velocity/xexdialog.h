#ifndef XEXDIALOG_H
#define XEXDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "qthelpers.h"

#include "Xex/Xex.h"
#include "Utils.h"

namespace Ui {
class XexDialog;
}

class XexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit XexDialog(Xbox360Executable *xex, QWidget *parent = 0);
    ~XexDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::XexDialog *ui;
    Xbox360Executable *xex;

    void AddExecutableProperty(QString name, DWORD value);

    void AddExecutableProperty(QString name, QString value);
};

#endif // XEXDIALOG_H

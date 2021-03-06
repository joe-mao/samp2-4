#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT
private:
    void iniSignalSlots();//关联信号与槽
private slots:
    //自定义槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize);//改变字体大小
    void on_comboFont_currentIndexChanged(const QString & arg1);//选择字体
public:
    explicit QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

private:
    Ui::QWMainWind *ui;
    QLabel * fLabCUrFile;//状态栏里显示当前文件的Label
    QProgressBar * progressBar1;//状态栏上的进度条
    QSpinBox * spinFontSize;//字体大小的spinBox
    QFontComboBox * comboFont;//字体名称comboBox
    void iniUI();//代码实现的UI初始化
};

#endif // QWMAINWIND_H

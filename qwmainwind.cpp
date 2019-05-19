#include "qwmainwind.h"
#include "ui_qwmainwind.h"

void QWMainWind::iniSignalSlots()
{
    //信号和槽的关联
    connect(spinFontSize, SIGNAL(valueChanged(int)), this, SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(on_comboFont_currentIndexChanged(const QString &)));

}

void QWMainWind::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    //改变字体大小的spinBox
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);//设置字体大小
    this->ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

void QWMainWind::on_comboFont_currentIndexChanged(const QString &arg1)
{
    //FontCombobox的响应，选择字体名称
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);//设置字体名称
    this->ui->txtEdit->mergeCurrentCharFormat(fmt);
}

QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();

}

QWMainWind::~QWMainWind()
{
    delete ui;
}

void QWMainWind::iniUI()
{
    //状态栏上添加组件
    fLabCUrFile = new QLabel;
    fLabCUrFile->setMinimumWidth(150);
    fLabCUrFile->setText("当前文件");
    this->ui->statusBar->addWidget(fLabCUrFile);//添加到状态栏

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(this->ui->txtEdit->font().pointSize());
    this->ui->statusBar->addWidget(progressBar1);//添加到状态栏

    //工具栏上添加组件
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(this->ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    this->ui->toolBar->addWidget(new QLabel("字体大小"));
    this->ui->toolBar->addWidget(spinFontSize);//SpinBox添加到工具栏

    this->ui->toolBar->addSeparator();//添加分割条
    this->ui->toolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    this->ui->toolBar->addWidget(comboFont);//添加到工具栏

    this->setCentralWidget(this->ui->txtEdit);

}

void QWMainWind::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = this->ui->txtEdit->currentCharFormat();
    if(checked){
        fmt.setFontWeight(QFont::Bold);
    }else{
        fmt.setFontWeight(QFont::Normal);
    }
    this->ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_txtEdit_copyAvailable(bool b)
{
    //更新cut, copy, paste的enbale属性
    this->ui->actCut->setEnabled(b);
    this->ui->actCopy->setEnabled(b);
    this->ui->actPaste->setEnabled(this->ui->txtEdit->canPaste());
}

void QWMainWind::on_txtEdit_selectionChanged()
{
    //更新粗体，斜体和下划线3种action的checked属性
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    this->ui->actFontItalic->setChecked(fmt.fontItalic());//是否斜体
    this->ui->actFontBold->setChecked(fmt.font().bold());//是否粗体
    this->ui->actFontUnder->setChecked(fmt.fontUnderline());//是否有下划线
}

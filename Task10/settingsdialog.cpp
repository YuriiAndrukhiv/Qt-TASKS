#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

bool SettingsDialog::isShowToolBar() const
{
    return ui->showToolbarCheckBox->isChecked();
}

void SettingsDialog::setShowToolBar(bool pShow)
{
    ui->showToolbarCheckBox->setChecked(pShow);
}

bool SettingsDialog::isShowStatusBar() const
{
    return ui->showStatusBarCheckBox->isChecked();
}

void SettingsDialog::setShowStatusBar(bool pShow)
{
    ui->showStatusBarCheckBox->setChecked(pShow);
}

#ifndef SIMPLETEXTEDITOR_H
#define SIMPLETEXTEDITOR_H

#include <QMainWindow>
#include <QFile>

class SettingsDialog;

// Попреднє оголошення класу форми
// створеної з .ui-файлу
namespace Ui {
class SimpleTextEditor;
}

class SimpleTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleTextEditor(QWidget *parent = nullptr);
    ~SimpleTextEditor();

private:
    // Вказівник на об'єкт форми
    // створеної з .ui-файлу
    Ui::SimpleTextEditor *ui;

    QString mFileName;

    QFile mFile;

    void updateTitle();

    bool askForFileSaveAndClose();

    SettingsDialog *mSettingsDialog;

    void readSettings();
    void writeSettings();
    void applySettings();

private slots:
    void slotNew();

    void slotOpen();

    void slotSave();

    void slotAboutProgram();

    void showPreferencesDialog();

    void slotPreferencesAccepted();

};

#endif // SIMPLETEXTEDITOR_H

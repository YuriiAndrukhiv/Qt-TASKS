#include "simpletexteditor.h"
#include "settingsdialog.h"
// Файл згенерований uic
// під час обробки файлу форми
#include "ui_simpletexteditor.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QVariant>
SimpleTextEditor::SimpleTextEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleTextEditor), // Створюємо об'єкт форми
    // створеної у QtDesigner
    mSettingsDialog(new SettingsDialog(this)) // Створюємо діалог налаштувань
{
    ui->setupUi(this); // Застосовуємо дизайн, який ми створили у QtDesigner
    // до поточного вікна

    // Задаємо комбінації клавіш для дій
    ui->action_Undo->setShortcut(QKeySequence::Undo);
    ui->action_Redo->setShortcut(QKeySequence::Redo);
    ui->action_Cut->setShortcut(QKeySequence::Cut);
    ui->action_Copy->setShortcut(QKeySequence::Copy);
    ui->action_Paste->setShortcut(QKeySequence::Paste);
    ui->action_Select_All->setShortcut(QKeySequence::SelectAll);
    ui->action_New->setShortcut(QKeySequence::New);
    ui->action_Open->setShortcut(QKeySequence::Open);
    ui->action_Save->setShortcut(QKeySequence::Save);
    ui->action_Exit->setShortcut(QKeySequence::Quit);

    ui->action_New->setIcon(QIcon(":/actions/new"));
    ui->action_Open->setIcon(QIcon(":/actions/open"));
    ui->action_Save->setIcon(QIcon(":/actions/save"));
    ui->action_Copy->setIcon(QIcon(":/actions/copy"));
    ui->action_Cut->setIcon(QIcon(":/actions/cut"));
    ui->action_Paste->setIcon(QIcon(":/actions/paste"));
    ui->action_Redo->setIcon(QIcon(":/actions/redo"));
    ui->action_Select_All->setIcon(QIcon(":/actions/select_all"));
    ui->action_Undo->setIcon(QIcon(":/actions/undo"));
    ui->action_About_Program->setIcon(QIcon(":/actions/about"));
    ui->action_Exit->setIcon(QIcon(":/actions/exit"));
    ui->action_About_Qt->setIcon(QIcon(":/actions/about_qt"));

    ui->action_Preferences->setIcon(QIcon(":/actions/preferences"));

    connect(ui->action_New, SIGNAL(triggered()), this, SLOT(slotNew()), Qt::UniqueConnection);

    // Приєднуємо дії до створених слотів
    connect(ui->action_New, SIGNAL(triggered()),
            this, SLOT(slotNew()), Qt::UniqueConnection);
    connect(ui->action_Open, SIGNAL(triggered()),
            this, SLOT(slotOpen()), Qt::UniqueConnection);
    connect(ui->action_Save, SIGNAL(triggered()),
            this, SLOT(slotSave()), Qt::UniqueConnection);
    connect(ui->action_About_Qt, SIGNAL(triggered()),
            qApp, SLOT(aboutQt()), Qt::UniqueConnection);
    connect(ui->action_About_Program, SIGNAL(triggered()),
            this, SLOT(slotAboutProgram()), Qt::UniqueConnection);

    connect(ui->action_Preferences, SIGNAL(triggered()),
            this, SLOT(showPreferencesDialog()), Qt::UniqueConnection);

    connect(mSettingsDialog, SIGNAL(accepted()),
            this, SLOT(slotPreferencesAccepted()), Qt::UniqueConnection);

    // Наприкінці, викликаємо слот для створення нового документу
    // Таким чином, користувач зможе одразу ж розпочати роботу
    slotNew();
    readSettings();
}

SimpleTextEditor::~SimpleTextEditor()
{
    // Видалити форму з пам'яті
    delete ui;
}

// Метод для перевірки поточного файла на зміни
// та виведення діалогу для користувача, з пропозицією
// зберегти зміни. Метод повертає логічне значення,
// яке містить false у випадку, коли коритувач натиснув
// у діалогу кнопку "Cancel"
bool SimpleTextEditor::askForFileSaveAndClose()
{
    // Якщо вміст вікна модифіковано...
    if (isWindowModified())
    {
        // викликаємо діалог з запитанням чи зберігати зміни:
        // підставляємо у текст діалогу назву поточного відкритого файлу,
        // задаємо кнопки: "Так", "Ні" та "Відмінити".
        // Результат роботи діалогу (натиснену кнопку) записуємо у змінну
        int lResult = QMessageBox::question(this, tr("Save changes"),
                                            QString(tr("File %1 is modified. Do you want to save your changes?")).arg(mFile.fileName()),
                                            QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);

        // Якщо натиснено кнопку "Так"...
        if (QMessageBox::Yes == lResult)
        {
            slotSave(); // зберегти зміни
        }
        else
        {
            // Якщо натиснено кнопку "Відмінити"...
            if (QMessageBox::Cancel == lResult)
            {
                return false;
            }
        }
    }
    return true;
}

void SimpleTextEditor::readSettings()
{
    // Вказуємо де зберігалися налаштування
    // QSettings::NativeFormat - у форматі визначеному системою
    // QSettings::UserScope - налаштування для кожного користувача окремо
    // Також задаємо ім’я орагінзації та назву програми
    QSettings lSettings(QSettings::NativeFormat, QSettings::UserScope,
                        "", qApp->applicationName());
    // Читаємо налаштування
    bool lShowToolBar = lSettings.value("SETTINGS_TOOLBAR", true).toBool();
    bool lShowStatusBar = lSettings.value("SETTINGS_STATUS_BAR", true).toBool();

    mSettingsDialog->setShowToolBar(lShowToolBar);
    mSettingsDialog->setShowStatusBar(lShowStatusBar);
    ui->mainToolBar->setVisible(lShowToolBar);
    ui->statusBar->setVisible(lShowStatusBar);
}

void SimpleTextEditor::writeSettings()
{
    // Вказуємо як зберігати налаштування
    // QSettings::NativeFormat - у форматі визначеному системою
    // QSettings::UserScope - берігати налаштування для кожного користувача окремо
    // Також задаємо ім’я орагінзації та назву програми
    QSettings lSettings (QSettings::NativeFormat, QSettings::UserScope,
                         "", qApp->applicationName());

    // Записуємо налаштування
    lSettings.setValue("SETTINGS_TOOLBAR", mSettingsDialog->isShowToolBar());
    lSettings.setValue("SETTINGS_STATUS_BAR", mSettingsDialog->isShowStatusBar());

}

void SimpleTextEditor::applySettings()
{
    // Читаємо налаштування встановлені
    // у діалозі та застосовуємо їх
    ui->mainToolBar->setVisible(mSettingsDialog->isShowToolBar());
    ui->statusBar->setVisible(mSettingsDialog->isShowStatusBar());
}

// Метод оновлення заголовку вікна
void SimpleTextEditor::updateTitle()
{
    // Підставляємо у назву заголовку ім'я поточного відкритого файлу
    // комбінацією символів "[*]" позначаємо місце, де буде виводитись
    // знак "*" у випадку, коли вміст вікна модифіковано
    QString lTitle = QString("TextEditor - %1[*]").arg(mFile.fileName());

    // Встановлюємо заголовок вікна
    setWindowTitle(lTitle);
}

// Слот для створення нового документу
void SimpleTextEditor::slotNew()
{
    // Задати ім'я для нового файлу за замовчуванням
    mFileName = "UntiteledFile";
    // Очистити текстове поле
    ui->plainTextEdit->clear();
    // Встановити - вміст не модифіковано
    setWindowModified(false);
    // Оновити заголовок вікна;
    updateTitle();

    // Запитати користувача про збереження документу
    if (!askForFileSaveAndClose())
    {
        // Якщо користувач натиснув "Відмінити"...
        // ... ігнорувати виклик- продовжувати роботу
        return;
    }
}

// Слот для відкриття файлу у редакторі
void SimpleTextEditor::slotOpen()
{
    // Викликати системний діалог відкриття файлу
    // у домашній теці користувача
    QString lFileName = QFileDialog::getOpenFileName(this, tr("Open file..."),
                                                     QDir::homePath(),
                                                     tr("Text files (*.txt);; All files (*.*)")); // вказуємо фільтри для перегляду файлів

    // Якщо користувач не вибрав жодного файлу...
    if (lFileName.isEmpty())
    {
        // ... вийти з методу
        return;
    }

    // Запитати користувача про збереження документу
    if (!askForFileSaveAndClose())
    {
        // Якщо користувач натиснув "Відмінити"...
        // ... ігнорувати виклик- продовжувати роботу
        return;
    }

    // Встановлюємо ім'я відкритого файлу
    QFile lFile(lFileName);

    // Якщо текстовий файл відкрито для читання...
    if (lFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // задати ім'я для файлу
        mFileName = lFileName;
        // ... читаємо весь вміст та втановлюємо текст для редактора...
        ui->plainTextEdit->setPlainText(lFile.readAll());
        // ..закриваємо відкритий файл...
        lFile.close();
        // ...встановлюємо стан вікна - вміст не модифіковано...
        setWindowModified(false);
        // ... та оновлюємо заголовок вікна для зображення
        // назви поточного відкритого файлу
        updateTitle();
    }
    else
    {
        // Якщо під час відкриття файлу виникла помилка...
        // виводимо діалогове вікно з повідомленням, куди підставляємо ім'я файлу,

        // вказуємо - вікно містить одну кнопку "Ок" та заголовок "Error"
        QMessageBox::warning(this, tr("Error"),
                             QString(tr("Could not open file %1 for reading")).arg(lFile.fileName()), QMessageBox::Ok);
    }

}

// Слот для збереження змін у поточному файлі
void SimpleTextEditor::slotSave()
{
    // Якщо вміст не модифіковано...
    if (!isWindowModified())
    {
        // Вийти з методу - продовжити роботу
        return;
    }

    // Викликати системний діалог збереження файлу
    // у домашній теці користувача
    QString lFileName = QFileDialog::getSaveFileName(this, tr("Save file..."),
                                                     QDir::homePath(),
                                                     tr("Text files(*.txt);; All files (*.*)"));

    // Якщо користувач не вибрав
    // ім'я файлу для збереження...
    if (lFileName.isEmpty())
    {
        // ... вийти з методу
        return;
    }

    // Встановлюємо ім'я відкритого файлу
    QFile lFile(lFileName);

    // Якщо текстовий файл відкрито для запису...
    if (lFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Задати ім'я для файлу
        mFileName = lFileName;

        // Створюємо тимчасовий QByteArray для запису даних
        QByteArray lData;
        // Читаємо текст з редактора та додаємо QByteArray,
        // записуємо у файл та закриваємо файл після запису
        lData.append(ui->plainTextEdit->toPlainText());
        lFile.write(lData);
        lFile.close();

        // Встановлюємо стан вікна - вміст не модифікован
        setWindowModified(false);
    }
    else
    {
        // Якщо під час відкриття файлу виникла помилка...
        // виводимо діалогове вікно з повідомленням, куди підставляємо ім'я файлу,
        // вказуємо - вікно містить одну кнопку "Ок" та заголовок "Error"
        QMessageBox::warning(this, tr("Error"),
                             QString(tr("Could not open file %1 for writing")).arg(lFile.fileName()), QMessageBox::Ok);
    }
}

// Слот для відображення інформації про програму
void SimpleTextEditor::slotAboutProgram()
{
    // Виводимо діалогове інформаційне вікно з повідомленням, куди підставляємо
    // версію програми та назву програми які повертає QApplication.
    // Вказуємо - вікно містить заголовок "About"
    QMessageBox::about(this, tr("About"), QString("%1 v. %2")
                       .arg(qApp->applicationName())
                       .arg(qApp->applicationVersion()));
}

void SimpleTextEditor::showPreferencesDialog()
{
    // Читаємо налаштування та встановлюємо
    // їх для діалога


    // Показуємо діалог налаштувань
    mSettingsDialog->show();
}

void SimpleTextEditor::slotPreferencesAccepted()
{
    // Записати нові налаштування
    writeSettings();
    // Застосувати налаштування
    applySettings();
}

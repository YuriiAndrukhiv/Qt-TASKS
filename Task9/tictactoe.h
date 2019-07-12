#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QWidget>
#include <QSignalMapper>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <vector>
#include <QString>
#include <QMenu>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void newGame();
    void pressed(const int id);

private:
    void init();
    void setSignalMapper();
    void endGame();
    bool winnerFound();

private:
    Ui::TicTacToe *ui;
    QSignalMapper *mSignalMapper;


    std::vector <QString> mBoard;

    bool isPlayer1 = true;
    bool isPlayer1Beginner = true;
};

#endif // TICTACTOE_H

#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <iostream>
#include <QMessageBox>

const int BUTTONS_COUNT = 9;

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    init();
    setSignalMapper();
    connect(mSignalMapper, SIGNAL(mapped(int)), this, SLOT(pressed(int)));
    connect(ui->newGameButton , SIGNAL(aboutToShow()) , this , SLOT(newGame()));
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::newGame()
{
    isPlayer1Beginner = !isPlayer1Beginner;

    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        mBoard[i] = "";
    }

    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        auto tempBtn = (QPushButton*)mSignalMapper->mapping(i);
        tempBtn->setText(QString());
        tempBtn->setEnabled(true);
    }

    if(isPlayer1Beginner)
    {
        isPlayer1 = true;
        ui->label->setText(QString("NEXT: PLAYER 1"));
    }
    else {
        isPlayer1 = false;
        ui->label->setText(QString("NEXT: PLAYER 2"));
    }
}

void TicTacToe::pressed(const int id)
{
    auto pressedButton = (QPushButton*)mSignalMapper->mapping(id);
    if(isPlayer1)
    {
        pressedButton->setText("X");
        mBoard.at(id) = QString("X");
        ui->label->setText("NEXT: Player 2");
    }
    else
    {
        pressedButton->setText("O");
        mBoard.at(id) = QString("O");
        ui->label->setText("NEXT: Player 1");
    }
    if(!winnerFound())
    {
        isPlayer1 = !isPlayer1;
        pressedButton->setEnabled(false);
    }
    else
    {
        if(isPlayer1)
        {
            QMessageBox::information(this, QString("Congratulations") , "Winner: Player 1"  , QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, QString("Congratulations") , "Winner: Player 2"  , QMessageBox::Ok);
        }
        endGame();
    }
}

void TicTacToe::init()
{
    setWindowTitle("Crosses 'N Zeros");

    for(int i = 0; i < BUTTONS_COUNT; i++)
    {
        mBoard.push_back(QString());
    }
}

void TicTacToe::setSignalMapper()
{
    mSignalMapper = new QSignalMapper(this);
    mSignalMapper->setMapping(ui->pushButton, 0);
    mSignalMapper->setMapping(ui->pushButton_2, 1);
    mSignalMapper->setMapping(ui->pushButton_3, 2);
    mSignalMapper->setMapping(ui->pushButton_4, 3);
    mSignalMapper->setMapping(ui->pushButton_5, 4);
    mSignalMapper->setMapping(ui->pushButton_6, 5);
    mSignalMapper->setMapping(ui->pushButton_7, 6);
    mSignalMapper->setMapping(ui->pushButton_8, 7);
    mSignalMapper->setMapping(ui->pushButton_9, 8);

    connect(ui->pushButton, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_2, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_3, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_4, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_5, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_6, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_7, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_8, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
    connect(ui->pushButton_9, &QPushButton::clicked, mSignalMapper, QOverload<>::of(&QSignalMapper::map));
}

void TicTacToe::endGame()
{
    for(int i = 0 ; i < BUTTONS_COUNT ; i++)
    {
        auto button = (QPushButton*)mSignalMapper->mapping(i);
        button->setEnabled(false);
    }
}

bool TicTacToe::winnerFound()
{
    for(int i = 0, j = 0; i < BUTTONS_COUNT; i+=3, j++)
    {
        if (mBoard[i] == mBoard[i+1] && mBoard[i+1] == mBoard[i+2] && !mBoard[i].isEmpty())
        {
            return true;
        }
        if (mBoard[j] == mBoard[j+3] && mBoard[j+3] == mBoard[j+6] && !mBoard[j].isEmpty())
        {
            return true;
        }
    }

    if(mBoard[0] == mBoard[4] && mBoard[4] == mBoard[8] && !mBoard[0].isEmpty())
    {
        return true;
    }

    if(mBoard[2] == mBoard[4] && mBoard[4] == mBoard[6] && !mBoard[2].isEmpty())
    {
        return true;
    }

    return false;
}

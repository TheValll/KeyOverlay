// This program creates a graphical user interface (GUI) using Qt framework for monitoring the status of various keys and buttons on a Windows system.
// Depending on whether the key is pressed or released, the function updates the style of the corresponding QPushButton to visually indicate its status.
// Users can modify the keys/buttons to monitor by editing the QPushButton objects in the UI file and updating the key codes accordingly.
// Virtual-Key Codes provided by Microsoft's documentation are used to represent key codes. Overall, this program provides a visual representation of key/button status in real-time.


// Include necessary library

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Windows.h>
#include <QTimer>
#include <QObject>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Initialize MainWindow and set up the UI
    ui->setupUi(this);

    // Create a QTimer object to trigger periodic events
    QTimer *timer = new QTimer(this);

    // Connect the timeout signal of the timer to a lambda function
    connect(timer, &QTimer::timeout, this, [this]() {

        // Call the function to check the status of each UI element (key/button)
        // If you want change a key :
        // 1. Go to the mainwindow.ui and edit the right QPushButton and rename it
        // Exemple : Change R by G -> rename R QPushButton by G
        // 2. Change the call function for the QPushButton
        // Exemple : Change R by G -> checkStatus(ui->R, 0x52); -> checkStatus(ui->G, 0x47);
        // For the list of Virtual-Key Codes, refer to:
        // https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

        checkStatus(ui->ESCAPE, VK_ESCAPE);
        checkStatus(ui->ONE, 0x31);
        checkStatus(ui->TWO, 0x32);
        checkStatus(ui->THREE, 0x33);
        checkStatus(ui->FOUR, 0x34);
        checkStatus(ui->Z, 0x5A);
        checkStatus(ui->G, 0x47);
        checkStatus(ui->UP, VK_UP);
        checkStatus(ui->RSHIFT, VK_RSHIFT);
        checkStatus(ui->RCTRL, VK_RCONTROL);
        checkStatus(ui->SHIFT, VK_LSHIFT);
        checkStatus(ui->Q, 0x51);
        checkStatus(ui->W, 0x57);
        checkStatus(ui->E, 0x45);
        checkStatus(ui->R, 0x52);
        checkStatus(ui->X, 0x58);
        checkStatus(ui->LEFT, VK_LEFT);
        checkStatus(ui->DOWN, VK_DOWN);
        checkStatus(ui->RIGHT, VK_RIGHT);
        checkStatus(ui->MOUSE3, VK_XBUTTON1);
        checkStatus(ui->CTRL, VK_LCONTROL);
        checkStatus(ui->A, 0x41);
        checkStatus(ui->S, 0x53);
        checkStatus(ui->D, 0x44);
        checkStatus(ui->F, 0x46);
        checkStatus(ui->SPACE, VK_SPACE);
        checkStatus(ui->MOUSE1, VK_LBUTTON);
        checkStatus(ui->MOUSE2, VK_RBUTTON);
        checkStatus(ui->MOUSE4, VK_XBUTTON2);
    });

    // Start the timer with a timeout interval of 10 milliseconds
    timer->start(10);
}

MainWindow::~MainWindow()
{
    // Destructor to clean up memory allocated for UI
    delete ui;
}

void MainWindow::checkStatus(QPushButton *name, int keycode){
    // Get the state of the key associated with the keycode
    SHORT KeyState = GetKeyState(keycode);
    if(KeyState & 0x8000){
        // If the key is pressed, update the button style to reflect the pressed state
        // You can change the color and background-color here :
        name->setStyleSheet("color: rgb(0, 0, 0); background-color: rgb(85, 170, 255); border-color: rgb(85, 170, 255); border-style: solid; border-width: 2px; margin: 4px 6px;");
    }else{
        // If the key is not pressed, update the button style to reflect the released state
        // You can change the default color and background-color here :
        name->setStyleSheet("color: rgb(85, 170, 255); background-color: rgb(0, 0, 0); border-color: rgb(85, 170, 255); border-style: solid; border-width: 2px; margin: 4px 6px;");
    }
}

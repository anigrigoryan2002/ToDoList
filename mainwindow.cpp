#include "mainwindow.h"
#include <QMainWindow>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <string>
#include "core/TaskManager.h"
#include "core/CommandParser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , parser(taskManager)
{
    setWindowTitle("ToDoList");
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    setStyleSheet("background-color:#F0F0F0");

    titleLabel = new QLabel("ToDoList");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "QLabel {"
        "background-color: #E0E0E0;"
        "color: #333333;"
        "border-bottom: 2px solid #B0B0B0;"
        "padding: 10px;"
        "font-size: 20px;"
        "font-weight: bold;"
        "}"
        );

    mainLayout->addWidget(titleLabel);
    QLabel* tasksLabel = new QLabel("Tasks:");
    tasksLabel->setStyleSheet("QLabel { color: black; font-weight: bold; }");
    mainLayout->addWidget(tasksLabel);

    taskList = new QListWidget;
    taskList->setStyleSheet(
        "QListWidget { "
        "background: white; "
        "color: black;"
        "border: 1px solid #A9A9A9; "
        "}"
        );
    mainLayout->addWidget(taskList);

    connect(taskList, &QListWidget::itemChanged,
            this, &MainWindow::handleTaskChecked);
    QLabel* logLabel = new QLabel("Log:");
    logLabel->setStyleSheet("QLabel { color: black; font-weight: bold; }");
    mainLayout->addWidget(logLabel);

    logOutput = new QTextEdit;
    logOutput->setReadOnly(true);
    logOutput->setStyleSheet(
        "QTextEdit { "
        "background: white; "
        "color: black;"
        "border: 1px solid #A9A9A9; "
        "}"
        );
    mainLayout->addWidget(logOutput);

    // ===== Command input + button =====
    QHBoxLayout* commandLayout = new QHBoxLayout;

    commandInput = new QLineEdit;
    commandInput->setPlaceholderText("Enter command here...");
    commandInput->setStyleSheet(
        "QLineEdit { "
        "background-color: white;"
        "color: black; "
        "border: 1px solid #A9A9A9; "
        "padding: 6px 12px; "
        "}"
        );
    commandLayout->addWidget(commandInput);

    executeButton = new QPushButton("Execute");
    executeButton->setStyleSheet(

        "QPushButton { "
        "background-color: white;"
        "color: black; "
        "padding: 6px 12px; "
        "border: 1px solid #A9A9A9; "
        "} "
        "QPushButton:hover { background-color: #C8C8C8; } "
        "QPushButton:pressed { background-color: #BDBDBD; }"
        );
    commandLayout->addWidget(executeButton);

    connect(executeButton, &QPushButton::clicked,
            this, &MainWindow::handleCommand);
    connect(commandInput, &QLineEdit::returnPressed,
            this, &MainWindow::handleCommand);

    mainLayout->addLayout(commandLayout);

}


MainWindow::~MainWindow()
{
}

void MainWindow::handleTaskChecked(QListWidgetItem* item)
{
    std::string taskName = item->text().toStdString();
    bool checked = (item->checkState() == Qt::Checked);

    taskManager.setCompleted(taskName, checked);

    updateLog(
        QString("Task %1 %2").arg(QString::fromStdString(taskName))
            .arg(checked ? "completed" : "added")
        );

    refreshTaskList();
}


void MainWindow::handleCommand()
{
    std::string result = parser.execute(
        commandInput->text().toStdString()
        );

    bool isError = result.rfind("Error", 0) == 0;

    updateLog(
        QString::fromStdString(result),
        isError
        );

    refreshTaskList();
    commandInput->clear();

}

// void MainWindow::handleCommand()
// {
//     QString input = commandInput->text().trimmed();
//     if(input.isEmpty()) return;

//     std::string result = parser.execute(input.toStdString());

//     bool isError =
//         result.find("Invalid") != std::string::npos ||
//         result.find("Unknown") != std::string::npos ||
//         result.find("already") != std::string::npos ||
//         result.find("not found") != std::string::npos;

//     showStatus(QString::fromStdString(result), isError);

//     commandInput->clear();
//     refreshTaskList();
// }


void MainWindow::refreshTaskList()
{
    taskList->blockSignals(true);
    taskList->clear();

    for(const Task& task : taskManager.listTasks()) {
        QListWidgetItem* item =
            new QListWidgetItem(QString::fromStdString(task.getName()));

        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(
            task.isCompleted() ? Qt::Checked : Qt::Unchecked
            );

        taskList->addItem(item);
    }
    taskList->blockSignals(false);
}

void MainWindow::updateLog(const QString& message, bool isError)
{
    QString color = isError ? "red" : "green";

    QString html = QString(
                       "<div style='font-weight:bold; color:%1;'>%2</div>"
                       "<div> %3 tasks list. </div>"
                       )
                       .arg(color)
                       .arg(message)
                       .arg(QString::number(taskManager.pendingTasksCount()));

    logOutput->setHtml(html);


}

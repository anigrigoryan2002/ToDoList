#include <QMainWindow>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "core/TaskManager.h"
#include "core/CommandParser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
private slots:
    void handleCommand();
    void handleTaskChecked(QListWidgetItem* item);
    void refreshTaskList();

private:
    QLabel* titleLabel;
    QListWidget* taskList;
    QTextEdit* logOutput;
    QLineEdit* commandInput;
    QPushButton* executeButton;
    TaskManager taskManager;
    CommandParser parser{taskManager};
    void updateLog(const QString& message, bool isError = false);
};

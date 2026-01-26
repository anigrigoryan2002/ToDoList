#include <QMainWindow>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "core/TaskManager.h"
#include "core/CommandParser.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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
    void showStatus(const QString& message, bool isError);
    void updateLog(const QString& message, bool isError = false);

};

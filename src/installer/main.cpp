#include "main.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    Ui::MainWindow ui;
    ui.setupUi(this);
    show();

#ifdef WIN32
    const std::string defaultfolder = std::string(std::getenv("APPDATA")) + "\\local\\Citra";
    ui.InstallPath->setText(QString::fromStdString(defaultfolder));
#endif
    connect(ui.PathButton, &QPushButton::clicked, this, [this] {
        auto filedialog = new QFileDialog(this);
        filedialog->setFileMode(QFileDialog::Directory);
        filedialog->exec();
    });
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    new MainWindow();

    return app.exec();
}

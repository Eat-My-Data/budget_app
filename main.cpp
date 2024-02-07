#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QTabWidget>

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(const QString &fileName, QWidget *parent = nullptr);

private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

TabDialog::TabDialog(const QString &fileName, QWidget *parent)
    	: QDialog(parent)
{
    	QFileInfo fileInfo(fileName);

    	tabWidget = new QTabWidget;
    	tabWidget->addTab(new GeneralTab(fileInfo), tr("General"));
    	tabWidget->addTab(new PermissionsTab(fileInfo), tr("Permissions"));
    	tabWidget->addTab(new ApplicationsTab(fileInfo), tr("Applications"));

	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    	connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

 	QVBoxLayout *mainLayout = new QVBoxLayout;
    	mainLayout->addWidget(tabWidget);
    	mainLayout->addWidget(buttonBox);
    	setLayout(mainLayout);
	setWindowTitle(tr("Tab Dialog"));
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QLabel label("Budget App");
	QTabWidget tabWidget;
 	label.show();
 	return app.exec();
}

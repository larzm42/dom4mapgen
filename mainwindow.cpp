/* This file is part of dom4mapgen.
 *
 * dom4mapgen is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dom4mapgen is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dom4mapgen.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_riverPartSlider_valueChanged(int value)
{
    ui->riverPartText->setText(QString::number(value));
}

void MainWindow::on_riverPartText_textChanged(const QString &arg1)
{
    ui->riverPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_seaPartSlider_valueChanged(int value)
{
    ui->seaPartText->setText(QString::number(value));
}

void MainWindow::on_seaPartText_textChanged(const QString &arg1)
{
    ui->seaPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_mountainPartSlider_valueChanged(int value)
{
    ui->mountainPartText->setText(QString::number(value));
}

void MainWindow::on_mountainPartText_textChanged(const QString &arg1)
{
    ui->mountainPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_forestPartSlider_valueChanged(int value)
{
    ui->forestPartText->setText(QString::number(value));
}

void MainWindow::on_forestPartText_textChanged(const QString &arg1)
{
    ui->forestPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_farmPartSlider_valueChanged(int value)
{
    ui->farmPartText->setText(QString::number(value));
}

void MainWindow::on_farmPartText_textChanged(const QString &arg1)
{
    ui->farmPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_wastePartSlider_valueChanged(int value)
{
    ui->wastePartText->setText(QString::number(value));
}

void MainWindow::on_wastePartText_textChanged(const QString &arg1)
{
    ui->wastePartSlider->setValue(arg1.toInt());
}

void MainWindow::on_swampPartSlider_valueChanged(int value)
{
    ui->swampPartText->setText(QString::number(value));
}

void MainWindow::on_swampPartText_textChanged(const QString &arg1)
{
    ui->swampPartSlider->setValue(arg1.toInt());
}

void MainWindow::on_cavePartSlider_valueChanged(int value)
{
    ui->cavePartText->setText(QString::number(value));
}

void MainWindow::on_cavePartText_textChanged(const QString &arg1)
{
    ui->cavePartSlider->setValue(arg1.toInt());
}

void MainWindow::on_groundColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->groundColorR->text().toInt(),ui->groundColorG->text().toInt(),ui->groundColorB->text().toInt(),ui->groundColorA->text().toInt()), this, "Select Ground Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->groundColorLabel->setPalette(QPalette(color));
        ui->groundColorLabel->setAutoFillBackground(true);
        ui->groundColorR->setText(QString::number(color.red()));
        ui->groundColorG->setText(QString::number(color.green()));
        ui->groundColorB->setText(QString::number(color.blue()));
        ui->groundColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_seaColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->seaColorR->text().toInt(),ui->seaColorG->text().toInt(),ui->seaColorB->text().toInt(),ui->seaColorA->text().toInt()), this, "Select Sea Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->seaColorLabel->setPalette(QPalette(color));
        ui->seaColorLabel->setAutoFillBackground(true);
        ui->seaColorR->setText(QString::number(color.red()));
        ui->seaColorG->setText(QString::number(color.green()));
        ui->seaColorB->setText(QString::number(color.blue()));
        ui->seaColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_groundBorderColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->groundBorderColorR->text().toInt(),ui->groundBorderColorG->text().toInt(),ui->groundBorderColorB->text().toInt(),ui->groundBorderColorA->text().toInt()), this, "Select Ground Border Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->groundBorderColorLabel->setPalette(QPalette(color));
        ui->groundBorderColorLabel->setAutoFillBackground(true);
        ui->groundBorderColorR->setText(QString::number(color.red()));
        ui->groundBorderColorG->setText(QString::number(color.green()));
        ui->groundBorderColorB->setText(QString::number(color.blue()));
        ui->groundBorderColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_seaBorderColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->seaBorderColorR->text().toInt(),ui->seaBorderColorG->text().toInt(),ui->seaBorderColorB->text().toInt(),ui->seaBorderColorA->text().toInt()), this, "Select Sea Border Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->seaBorderColorLabel->setPalette(QPalette(color));
        ui->seaBorderColorLabel->setAutoFillBackground(true);
        ui->seaBorderColorR->setText(QString::number(color.red()));
        ui->seaBorderColorG->setText(QString::number(color.green()));
        ui->seaBorderColorB->setText(QString::number(color.blue()));
        ui->seaBorderColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_deepSeaColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->deepSeaColorR->text().toInt(),ui->deepSeaColorG->text().toInt(),ui->deepSeaColorB->text().toInt(),ui->deepSeaColorA->text().toInt()), this, "Select Deep Sea Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->deepSeaColorLabel->setPalette(QPalette(color));
        ui->deepSeaColorLabel->setAutoFillBackground(true);
        ui->deepSeaColorR->setText(QString::number(color.red()));
        ui->deepSeaColorG->setText(QString::number(color.green()));
        ui->deepSeaColorB->setText(QString::number(color.blue()));
        ui->deepSeaColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_coastColorButton_clicked()
{
    const QColor color = QColorDialog::getColor(QColor(ui->coastColorR->text().toInt(),ui->coastColorG->text().toInt(),ui->coastColorB->text().toInt(),ui->coastColorA->text().toInt()), this, "Select Coast Color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        ui->coastColorLabel->setPalette(QPalette(color));
        ui->coastColorLabel->setAutoFillBackground(true);
        ui->coastColorR->setText(QString::number(color.red()));
        ui->coastColorG->setText(QString::number(color.green()));
        ui->coastColorB->setText(QString::number(color.blue()));
        ui->coastColorA->setText(QString::number(color.alpha()));
    }
}

void MainWindow::on_mapNoiseText_textChanged(const QString &arg1)
{
    ui->mapNoiseSlider->setValue(arg1.toInt());
}

void MainWindow::on_mapNoiseSlider_valueChanged(int value)
{
    ui->mapNoiseText->setText(QString::number(value));
}

void MainWindow::on_borderWidthText_textChanged(const QString &arg1)
{
    ui->borderWidthSlider->setValue(arg1.toInt());
}

void MainWindow::on_borderWidthSlider_valueChanged(int value)
{
    ui->borderWidthText->setText(QString::number(value));
}

void MainWindow::on_ruggednessText_textChanged(const QString &arg1)
{
    ui->ruggednessSlider->setValue(arg1.toInt());
}

void MainWindow::on_ruggednessSlider_valueChanged(int value)
{
    ui->ruggednessText->setText(QString::number(value));
}

void MainWindow::on_groundColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->groundColorR->text().toInt(),ui->groundColorG->text().toInt(),ui->groundColorB->text().toInt(),ui->groundColorA->text().toInt());
    if (color.isValid()) {
        ui->groundColorLabel->setPalette(QPalette(color));
        ui->groundColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_groundColorG_textEdited(const QString &arg1)
{
    on_groundColorR_textEdited(arg1);
}

void MainWindow::on_groundColorB_textEdited(const QString &arg1)
{
    on_groundColorR_textEdited(arg1);
}

void MainWindow::on_groundColorA_textEdited(const QString &arg1)
{
    on_groundColorR_textEdited(arg1);
}

void MainWindow::on_seaColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->seaColorR->text().toInt(),ui->seaColorG->text().toInt(),ui->seaColorB->text().toInt(),ui->seaColorA->text().toInt());
    if (color.isValid()) {
        ui->seaColorLabel->setPalette(QPalette(color));
        ui->seaColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_seaColorG_textEdited(const QString &arg1)
{
    on_seaColorR_textEdited(arg1);
}

void MainWindow::on_seaColorB_textEdited(const QString &arg1)
{
    on_seaColorR_textEdited(arg1);
}

void MainWindow::on_seaColorA_textEdited(const QString &arg1)
{
    on_seaColorR_textEdited(arg1);
}

void MainWindow::on_groundBorderColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->groundBorderColorR->text().toInt(),ui->groundBorderColorG->text().toInt(),ui->groundBorderColorB->text().toInt(),ui->groundBorderColorA->text().toInt());
    if (color.isValid()) {
        ui->groundBorderColorLabel->setPalette(QPalette(color));
        ui->groundBorderColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_groundBorderColorG_textEdited(const QString &arg1)
{
    on_groundBorderColorR_textEdited(arg1);
}

void MainWindow::on_groundBorderColorB_textEdited(const QString &arg1)
{
    on_groundBorderColorR_textEdited(arg1);
}

void MainWindow::on_groundBorderColorA_textEdited(const QString &arg1)
{
    on_groundBorderColorR_textEdited(arg1);
}

void MainWindow::on_seaBorderColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->seaBorderColorR->text().toInt(),ui->seaBorderColorG->text().toInt(),ui->seaBorderColorB->text().toInt(),ui->seaBorderColorA->text().toInt());
    if (color.isValid()) {
        ui->seaBorderColorLabel->setPalette(QPalette(color));
        ui->seaBorderColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_seaBorderColorG_textEdited(const QString &arg1)
{
    on_seaBorderColorR_textEdited(arg1);
}

void MainWindow::on_seaBorderColorB_textEdited(const QString &arg1)
{
    on_seaBorderColorR_textEdited(arg1);
}

void MainWindow::on_seaBorderColorA_textEdited(const QString &arg1)
{
    on_seaBorderColorR_textEdited(arg1);
}

void MainWindow::on_deepSeaColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->deepSeaColorR->text().toInt(),ui->deepSeaColorG->text().toInt(),ui->deepSeaColorB->text().toInt(),ui->deepSeaColorA->text().toInt());
    if (color.isValid()) {
        ui->deepSeaColorLabel->setPalette(QPalette(color));
        ui->deepSeaColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_deepSeaColorG_textEdited(const QString &arg1)
{
    on_deepSeaColorR_textEdited(arg1);
}

void MainWindow::on_deepSeaColorB_textEdited(const QString &arg1)
{
    on_deepSeaColorR_textEdited(arg1);
}

void MainWindow::on_deepSeaColorA_textEdited(const QString &arg1)
{
    on_deepSeaColorR_textEdited(arg1);
}

void MainWindow::on_coastColorR_textEdited(const QString &arg1)
{
    QColor color = QColor(ui->coastColorR->text().toInt(),ui->coastColorG->text().toInt(),ui->coastColorB->text().toInt(),ui->coastColorA->text().toInt());
    if (color.isValid()) {
        ui->coastColorLabel->setPalette(QPalette(color));
        ui->coastColorLabel->setAutoFillBackground(true);
    }
}

void MainWindow::on_coastColorG_textEdited(const QString &arg1)
{
    on_coastColorR_textEdited(arg1);
}

void MainWindow::on_coastColorB_textEdited(const QString &arg1)
{
    on_coastColorR_textEdited(arg1);
}

void MainWindow::on_coastColorA_textEdited(const QString &arg1)
{
    on_coastColorR_textEdited(arg1);
}

void MainWindow::on_dom4BrowseButton_1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Dominions 4 Exectuable"), "", tr("Dominions 4 Exectuable (*)"));
    ui->dom4Text->setText(fileName);
}

void MainWindow::on_generateButton_clicked()
{
    if (ui->mapName->text().size() == 0) {
        QMessageBox msgBox(QMessageBox::Warning, tr("Error"),
                           "You must choose a name for the map.", 0, this);
        msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
        msgBox.exec();
        return;
    }

    QStringList args;
    args << "--makemap" << ui->mapName->text()
         << "--riverpart" << ui->riverPartText->text()
         << "--seapart" << ui->seaPartText->text()
         << "--mountpart" << ui->mountainPartText->text()
         << "--forestpart" << ui->forestPartText->text()
         << "--farmpart" << ui->farmPartText->text()
         << "--wastepart" << ui->wastePartText->text()
         << "--swamppart" << ui->swampPartText->text()
         << "--cavepart" << ui->cavePartText->text()
         << "--mapsize" << ui->mapSizeWidth->text() << ui->mapSizeHeight->text()
         << "--mapprov" << ui->numProvincesText->text()
         << "--mapgcol" << ui->groundColorR->text() << ui->groundColorG->text() << ui->groundColorB->text() << ui->groundColorA->text()
         << "--mapscol" << ui->seaColorR->text() << ui->seaColorG->text() << ui->seaColorB->text() << ui->seaColorA->text()
         << "--mapdscol" << ui->deepSeaColorR->text() << ui->deepSeaColorG->text() << ui->deepSeaColorB->text() << ui->deepSeaColorA->text()
         << "--mapbcol" << ui->groundBorderColorR->text() << ui->groundBorderColorG->text() << ui->groundBorderColorB->text() << ui->groundBorderColorA->text()
         << "--mapsbcol" << ui->seaBorderColorR->text() << ui->seaBorderColorG->text() << ui->seaBorderColorB->text() << ui->seaBorderColorA->text()
         << "--mapccol" << ui->coastColorR->text() << ui->coastColorG->text() << ui->coastColorB->text() << ui->coastColorA->text()
         << "--mapnoise" << ui->mapNoiseText->text()
         << "--borderwidth" << ui->borderWidthText->text()
         << "--hills" << ui->hillsText->text()
         << "--rugedness" << ui->ruggednessText->text()
         << "--seasize" << ui->seaSizeText->text()
         << "--textonly";
    if (ui->antiAliasBox->isChecked()) {
        args << "--mapaa";
    }
    if (!(ui->spritesBox->isChecked())) {
        args << "--mapnospr";
    }
    if (ui->northSouthWrapBox->isChecked()) {
        args << "--vwrap";
    }
    if (!(ui->eastWestWrapBox->isChecked())) {
        args << "--nohwrap";
    }
    if (!(ui->impassableBox->isChecked())) {
        args << "--passmount";
    }

    QString program = ui->dom4Text->text();

    QProcess *myProcess = new QProcess();
    QFileInfo exe = QFileInfo(program);
    if (exe.exists() && exe.isExecutable()) {
        myProcess->setWorkingDirectory(exe.absolutePath());
        myProcess->start(program, args);
#ifdef Q_OS_WIN32
        QStringList env = myProcess->systemEnvironment();
        QStringListIterator iter(env);
        while (iter.hasNext()) {
            QString line = iter.next();
            if (line.startsWith("APPDATA")) {
                appdata = line.remove(0, 8);
            }
        }
#endif
#ifdef Q_OS_LINUX
        appdata = QDir::homePath();
#endif

        dialog.reset();
        Qt::WindowFlags flags = dialog.windowFlags();
        Qt::WindowFlags helpFlag = Qt::WindowContextHelpButtonHint;
        flags = flags & (~helpFlag);
        dialog.setWindowFlags(flags);
        dialog.setModal(true);
        dialog.setWindowTitle("Generating Map");
        dialog.setWindowIcon(QIcon(":/ophan.png"));
        dialog.show();

        counter = 0;
        QTimer::singleShot(1000, this, SLOT(poll_map_file()));
    } else {
        QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),
                           "Dominions 4 executable can't be run.", 0, this);
        msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
        msgBox.exec();
    }

}

void MainWindow::poll_map_file()
{
    QFileInfo mapFile = QFileInfo(appdata + "/dominions4/maps/" + ui->mapName->text() + ".rgb");
    if (mapFile.exists() && mapFile.size() > 0 /*&& isMapValid(mapFile.absoluteFilePath())*/) {
        dialog.close();
#ifdef Q_OS_WIN32
        QString program = "OpenSeeIt.exe";

        QProcess *myProcess = new QProcess();
        QFileInfo viewer = QFileInfo(program);
        if (viewer.exists() && viewer.isExecutable()) {
            QStringList args;
            args << QDir::toNativeSeparators(mapFile.absoluteFilePath());

            myProcess->start(program, args);
        }
#endif
#ifdef Q_OS_LINUX
        QString program = "display";
        QDesktopServices::openUrl(QUrl("file://"+mapFile.absoluteFilePath()));
#endif


    } else {
        if (!dialog.wasCanceled()) {
            counter += 2;
            if (counter > 99) {
                counter = 0;
            }
            dialog.setValue(counter);
            QTimer::singleShot(1000, this, SLOT(poll_map_file()));
        }
    }
}

void MainWindow::on_loadSettingsButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Dominions 4 Map Settings"), "", tr("Settings (*.json)"));
    QFile loadFile(fileName);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    read(loadDoc.object());

}

void MainWindow::read(const QJsonObject &json)
{
    ui->dom4Text->setText(json["dom4Text"].toString());
    ui->mapName->setText(json["mapName"].toString());
    ui->riverPartText->setText(json["riverPartText"].toString());
    ui->numProvincesText->setText(json["numProvincesText"].toString());
    ui->mapName->setText(json["mapName"].toString());
    ui->riverPartText->setText(json["riverPartText"].toString());
    ui->numProvincesText->setText(json["numProvincesText"].toString());
    ui->seaPartText->setText(json["seaPartText"].toString());
    ui->mountainPartText->setText(json["mountainPartText"].toString());
    ui->forestPartText->setText(json["forestPartText"].toString());
    ui->farmPartText->setText(json["farmPartText"].toString());
    ui->wastePartText->setText(json["wastePartText"].toString());
    ui->swampPartText->setText(json["swampPartText"].toString());
    ui->cavePartText->setText(json["cavePartText"].toString());
    ui->mapSizeWidth->setText(json["mapSizeWidth"].toString());
    ui->mapSizeHeight->setText(json["mapSizeHeight"].toString());
    ui->groundColorR->setText(json["groundColorR"].toString());
    ui->groundColorG->setText(json["groundColorG"].toString());
    ui->groundColorB->setText(json["groundColorB"].toString());
    ui->groundColorA->setText(json["groundColorA"].toString());
    on_groundColorR_textEdited(json["groundColorR"].toString());
    ui->seaColorR->setText(json["seaColorR"].toString());
    ui->seaColorG->setText(json["seaColorG"].toString());
    ui->seaColorB->setText(json["seaColorB"].toString());
    ui->seaColorA->setText(json["seaColorA"].toString());
    on_seaColorR_textEdited(json["seaColorR"].toString());
    ui->deepSeaColorR->setText(json["deepSeaColorR"].toString());
    ui->deepSeaColorG->setText(json["deepSeaColorG"].toString());
    ui->deepSeaColorB->setText(json["deepSeaColorB"].toString());
    ui->deepSeaColorA->setText(json["deepSeaColorA"].toString());
    on_deepSeaColorR_textEdited(json["deepSeaColorR"].toString());
    ui->groundBorderColorR->setText(json["groundBorderColorR"].toString());
    ui->groundBorderColorG->setText(json["groundBorderColorG"].toString());
    ui->groundBorderColorB->setText(json["groundBorderColorB"].toString());
    ui->groundBorderColorA->setText(json["groundBorderColorA"].toString());
    on_groundBorderColorR_textEdited(json["groundBorderColorR"].toString());
    ui->seaBorderColorR->setText(json["seaBorderColorR"].toString());
    ui->seaBorderColorG->setText(json["seaBorderColorG"].toString());
    ui->seaBorderColorB->setText(json["seaBorderColorB"].toString());
    ui->seaBorderColorA->setText(json["seaBorderColorA"].toString());
    on_seaBorderColorR_textEdited(json["seaBorderColorR"].toString());
    ui->coastColorR->setText(json["coastColorR"].toString());
    ui->coastColorG->setText(json["coastColorG"].toString());
    ui->coastColorB->setText(json["coastColorB"].toString());
    ui->coastColorA->setText(json["coastColorA"].toString());
    on_coastColorR_textEdited(json["coastColorR"].toString());
    ui->mapNoiseText->setText(json["mapNoiseText"].toString());
    ui->borderWidthText->setText(json["borderWidthText"].toString());
    ui->hillsText->setText(json["hillsText"].toString());
    ui->ruggednessText->setText(json["ruggednessText"].toString());
    ui->seaSizeText->setText(json["seaSizeText"].toString());
    ui->antiAliasBox->setChecked(json["antiAliasBox"].toBool());
    ui->spritesBox->setChecked(json["spritesBox"].toBool());
    ui->northSouthWrapBox->setChecked(json["northSouthWrapBox"].toBool());
    ui->eastWestWrapBox->setChecked(json["eastWestWrapBox"].toBool());
    ui->impassableBox->setChecked(json["impassableBox"].toBool());
}

void MainWindow::on_saveSettingsButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Dominions 4 Map Settings"), "save.json", tr("Settings (*.json)"));

    QFile saveFile(fileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonObject gameObject;
    write(gameObject);
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());
}

void MainWindow::write(QJsonObject &json) const
{
    json["dom4Text"] =  ui->dom4Text->text();
    json["mapName"] = ui->mapName->text();
    json["riverPartText"] = ui->riverPartText->text();
    json["numProvincesText"] = ui->numProvincesText->text();
    json["seaPartText"] = ui->seaPartText->text();
    json["mountainPartText"] = ui->mountainPartText->text();
    json["forestPartText"] = ui->forestPartText->text();
    json["farmPartText"] = ui->farmPartText->text();
    json["wastePartText"] = ui->wastePartText->text();
    json["swampPartText"] = ui->swampPartText->text();
    json["cavePartText"] = ui->cavePartText->text();
    json["mapSizeWidth"] = ui->mapSizeWidth->text();
    json["mapSizeHeight"] = ui->mapSizeHeight->text();
    json["groundColorR"] = ui->groundColorR->text();
    json["groundColorG"] = ui->groundColorG->text();
    json["groundColorB"] = ui->groundColorB->text();
    json["groundColorA"] = ui->groundColorA->text();
    json["seaColorR"] = ui->seaColorR->text();
    json["seaColorG"] = ui->seaColorG->text();
    json["seaColorB"] = ui->seaColorB->text();
    json["seaColorA"] = ui->seaColorA->text();
    json["deepSeaColorR"] = ui->deepSeaColorR->text();
    json["deepSeaColorG"] = ui->deepSeaColorG->text();
    json["deepSeaColorB"] = ui->deepSeaColorB->text();
    json["deepSeaColorA"] = ui->deepSeaColorA->text();
    json["groundBorderColorR"] = ui->groundBorderColorR->text();
    json["groundBorderColorG"] = ui->groundBorderColorG->text();
    json["groundBorderColorB"] = ui->groundBorderColorB->text();
    json["groundBorderColorA"] = ui->groundBorderColorA->text();
    json["seaBorderColorR"] = ui->seaBorderColorR->text();
    json["seaBorderColorG"] = ui->seaBorderColorG->text();
    json["seaBorderColorB"] = ui->seaBorderColorB->text();
    json["seaBorderColorA"] = ui->seaBorderColorA->text();
    json["coastColorR"] = ui->coastColorR->text();
    json["coastColorG"] = ui->coastColorG->text();
    json["coastColorB"] = ui->coastColorB->text();
    json["coastColorA"] = ui->coastColorA->text();
    json["mapNoiseText"] = ui->mapNoiseText->text();
    json["borderWidthText"] = ui->borderWidthText->text();
    json["hillsText"] = ui->hillsText->text();
    json["ruggednessText"] = ui->ruggednessText->text();
    json["seaSizeText"] = ui->seaSizeText->text();
    json["antiAliasBox"] = ui->antiAliasBox->isChecked();
    json["spritesBox"] = ui->spritesBox->isChecked();
    json["northSouthWrapBox"] = ui->northSouthWrapBox->isChecked();
    json["eastWestWrapBox"] = ui->eastWestWrapBox->isChecked();
    json["impassableBox"] = ui->impassableBox->isChecked();
}


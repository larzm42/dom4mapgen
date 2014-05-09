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
         << "--mapbcol" << ui->groundBorderColorR->text() << ui->groundBorderColorG->text() << ui->groundBorderColorB->text() << ui->groundBorderColorA->text()
         << "--mapsbcol" << ui->seaBorderColorR->text() << ui->seaBorderColorG->text() << ui->seaBorderColorB->text() << ui->seaBorderColorA->text()
         << "--mapnoise" << ui->mapNoiseText->text()
         << "--borderwidth" << ui->borderWidthText->text()
         << "--hills" << ui->hillsText->text()
         << "--rugedness" << ui->ruggednessText->text()
         << "--seasize" << ui->seaSizeText->text();
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

    QString program = ui->dom4Text->text();

    QProcess *myProcess = new QProcess();
    QFileInfo exe = QFileInfo(program);
    if (exe.exists() && exe.isExecutable()) {
        myProcess->setWorkingDirectory(exe.absolutePath());
        myProcess->start(program, args);

    } else {
        QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),
                           "Dominions 4 executable can't be run.", 0, this);
        msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
        msgBox.exec();
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
    ui->mapNoiseText->setText(json["mapNoiseText"].toString());
    ui->borderWidthText->setText(json["borderWidthText"].toString());
    ui->hillsText->setText(json["hillsText"].toString());
    ui->ruggednessText->setText(json["ruggednessText"].toString());
    ui->seaSizeText->setText(json["seaSizeText"].toString());
    ui->antiAliasBox->setChecked(json["antiAliasBox"].toBool());
    ui->spritesBox->setChecked(json["spritesBox"].toBool());
    ui->northSouthWrapBox->setChecked(json["northSouthWrapBox"].toBool());
    ui->eastWestWrapBox->setChecked(json["eastWestWrapBox"].toBool());
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
    json["groundBorderColorR"] = ui->groundBorderColorR->text();
    json["groundBorderColorG"] = ui->groundBorderColorG->text();
    json["groundBorderColorB"] = ui->groundBorderColorB->text();
    json["groundBorderColorA"] = ui->groundBorderColorA->text();
    json["seaBorderColorR"] = ui->seaBorderColorR->text();
    json["seaBorderColorG"] = ui->seaBorderColorG->text();
    json["seaBorderColorB"] = ui->seaBorderColorB->text();
    json["seaBorderColorA"] = ui->seaBorderColorA->text();
    json["mapNoiseText"] = ui->mapNoiseText->text();
    json["borderWidthText"] = ui->borderWidthText->text();
    json["hillsText"] = ui->hillsText->text();
    json["ruggednessText"] = ui->ruggednessText->text();
    json["seaSizeText"] = ui->seaSizeText->text();
    json["antiAliasBox"] = ui->antiAliasBox->isChecked();
    json["spritesBox"] = ui->spritesBox->isChecked();
    json["northSouthWrapBox"] = ui->northSouthWrapBox->isChecked();
    json["eastWestWrapBox"] = ui->eastWestWrapBox->isChecked();
}


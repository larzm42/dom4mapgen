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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_riverPartSlider_valueChanged(int value);

    void on_riverPartText_textChanged(const QString &arg1);

    void on_seaPartSlider_valueChanged(int value);

    void on_seaPartText_textChanged(const QString &arg1);

    void on_mountainPartSlider_valueChanged(int value);

    void on_mountainPartText_textChanged(const QString &arg1);

    void on_forestPartSlider_valueChanged(int value);

    void on_forestPartText_textChanged(const QString &arg1);

    void on_farmPartSlider_valueChanged(int value);

    void on_farmPartText_textChanged(const QString &arg1);

    void on_wastePartSlider_valueChanged(int value);

    void on_wastePartText_textChanged(const QString &arg1);

    void on_swampPartSlider_valueChanged(int value);

    void on_swampPartText_textChanged(const QString &arg1);

    void on_cavePartSlider_valueChanged(int value);

    void on_cavePartText_textChanged(const QString &arg1);

    void on_groundColorButton_clicked();

    void on_seaColorButton_clicked();

    void on_groundBorderColorButton_clicked();

    void on_seaBorderColorButton_clicked();

    void on_mapNoiseText_textChanged(const QString &arg1);

    void on_mapNoiseSlider_valueChanged(int value);

    void on_borderWidthText_textChanged(const QString &arg1);

    void on_borderWidthSlider_valueChanged(int value);

    void on_ruggednessText_textChanged(const QString &arg1);

    void on_ruggednessSlider_valueChanged(int value);

    void on_groundColorR_textEdited(const QString &arg1);

    void on_groundColorG_textEdited(const QString &arg1);

    void on_groundColorA_textEdited(const QString &arg1);

    void on_groundColorB_textEdited(const QString &arg1);

    void on_dom4BrowseButton_1_clicked();

    void on_generateButton_clicked();

    void on_loadSettingsButton_clicked();

    void on_saveSettingsButton_clicked();
    void on_seaColorR_textEdited(const QString &arg1);

    void on_seaColorG_textEdited(const QString &arg1);

    void on_seaColorB_textEdited(const QString &arg1);

    void on_seaColorA_textEdited(const QString &arg1);

    void on_groundBorderColorR_textEdited(const QString &arg1);

    void on_groundBorderColorG_textEdited(const QString &arg1);

    void on_groundBorderColorB_textEdited(const QString &arg1);

    void on_groundBorderColorA_textEdited(const QString &arg1);

    void on_seaBorderColorR_textEdited(const QString &arg1);

    void on_seaBorderColorG_textEdited(const QString &arg1);

    void on_seaBorderColorB_textEdited(const QString &arg1);

    void on_seaBorderColorA_textEdited(const QString &arg1);

    void on_deepSeaColorButton_clicked();

    void on_coastColorButton_clicked();

    void on_deepSeaColorR_textEdited(const QString &arg1);

    void on_deepSeaColorG_textEdited(const QString &arg1);

    void on_deepSeaColorB_textEdited(const QString &arg1);

    void on_deepSeaColorA_textEdited(const QString &arg1);

    void on_coastColorR_textEdited(const QString &arg1);

    void on_coastColorG_textEdited(const QString &arg1);

    void on_coastColorB_textEdited(const QString &arg1);

    void on_coastColorA_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void write(QJsonObject &json) const;
    void read(const QJsonObject &json);
};

#endif // MAINWINDOW_H

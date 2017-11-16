/********************************************************************************
** Form generated from reading UI file 'firstprogram.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTPROGRAM_H
#define UI_FIRSTPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstprogram
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *playback_tab;
    QPushButton *load_button;
    QLabel *display_image;
    QPushButton *play_pause_button;
    QPushButton *stop_button;
    QSlider *playbackslider;
    QLabel *time_start_label;
    QLabel *time_end_label;
    QWidget *tab_2;
    QLabel *display_record;
    QPushButton *stop_record_button;
    QGroupBox *groupBox;
    QCheckBox *human_checkbox;
    QCheckBox *movement_checkbox;
    QCheckBox *everything_checkbox;
    QGroupBox *groupBox_2;
    QLabel *camstatus_label;
    QPushButton *loadcam_button;
    QLabel *record_label;
    QMenuBar *menuBar;
    QMenu *menuMain_Window;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *firstprogram)
    {
        if (firstprogram->objectName().isEmpty())
            firstprogram->setObjectName(QStringLiteral("firstprogram"));
        firstprogram->resize(865, 679);
        centralWidget = new QWidget(firstprogram);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 841, 611));
        playback_tab = new QWidget();
        playback_tab->setObjectName(QStringLiteral("playback_tab"));
        playback_tab->setInputMethodHints(Qt::ImhNone);
        load_button = new QPushButton(playback_tab);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(710, 60, 81, 31));
        display_image = new QLabel(playback_tab);
        display_image->setObjectName(QStringLiteral("display_image"));
        display_image->setGeometry(QRect(30, 20, 640, 480));
        display_image->setMaximumSize(QSize(640, 480));
        display_image->setAutoFillBackground(false);
        display_image->setStyleSheet(QStringLiteral("Background-color: #000;"));
        play_pause_button = new QPushButton(playback_tab);
        play_pause_button->setObjectName(QStringLiteral("play_pause_button"));
        play_pause_button->setEnabled(false);
        play_pause_button->setGeometry(QRect(710, 110, 81, 31));
        stop_button = new QPushButton(playback_tab);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setEnabled(false);
        stop_button->setGeometry(QRect(710, 160, 81, 31));
        playbackslider = new QSlider(playback_tab);
        playbackslider->setObjectName(QStringLiteral("playbackslider"));
        playbackslider->setEnabled(false);
        playbackslider->setGeometry(QRect(30, 510, 641, 22));
        playbackslider->setOrientation(Qt::Horizontal);
        time_start_label = new QLabel(playback_tab);
        time_start_label->setObjectName(QStringLiteral("time_start_label"));
        time_start_label->setGeometry(QRect(30, 530, 46, 13));
        time_end_label = new QLabel(playback_tab);
        time_end_label->setObjectName(QStringLiteral("time_end_label"));
        time_end_label->setGeometry(QRect(630, 530, 46, 13));
        tabWidget->addTab(playback_tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        display_record = new QLabel(tab_2);
        display_record->setObjectName(QStringLiteral("display_record"));
        display_record->setGeometry(QRect(20, 20, 640, 480));
        display_record->setMaximumSize(QSize(640, 480));
        display_record->setAutoFillBackground(false);
        display_record->setStyleSheet(QStringLiteral("Background-color: #000;"));
        stop_record_button = new QPushButton(tab_2);
        stop_record_button->setObjectName(QStringLiteral("stop_record_button"));
        stop_record_button->setEnabled(false);
        stop_record_button->setGeometry(QRect(280, 520, 111, 41));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(680, 260, 131, 91));
        human_checkbox = new QCheckBox(groupBox);
        human_checkbox->setObjectName(QStringLiteral("human_checkbox"));
        human_checkbox->setGeometry(QRect(10, 40, 111, 17));
        movement_checkbox = new QCheckBox(groupBox);
        movement_checkbox->setObjectName(QStringLiteral("movement_checkbox"));
        movement_checkbox->setGeometry(QRect(10, 60, 121, 17));
        everything_checkbox = new QCheckBox(groupBox);
        everything_checkbox->setObjectName(QStringLiteral("everything_checkbox"));
        everything_checkbox->setGeometry(QRect(10, 20, 111, 17));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(680, 40, 120, 51));
        camstatus_label = new QLabel(groupBox_2);
        camstatus_label->setObjectName(QStringLiteral("camstatus_label"));
        camstatus_label->setGeometry(QRect(10, 20, 101, 16));
        loadcam_button = new QPushButton(tab_2);
        loadcam_button->setObjectName(QStringLiteral("loadcam_button"));
        loadcam_button->setGeometry(QRect(700, 100, 81, 31));
        record_label = new QLabel(tab_2);
        record_label->setObjectName(QStringLiteral("record_label"));
        record_label->setGeometry(QRect(20, 560, 201, 16));
        tabWidget->addTab(tab_2, QString());
        firstprogram->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(firstprogram);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 865, 21));
        menuMain_Window = new QMenu(menuBar);
        menuMain_Window->setObjectName(QStringLiteral("menuMain_Window"));
        firstprogram->setMenuBar(menuBar);
        mainToolBar = new QToolBar(firstprogram);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        firstprogram->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(firstprogram);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        firstprogram->setStatusBar(statusBar);

        menuBar->addAction(menuMain_Window->menuAction());

        retranslateUi(firstprogram);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(firstprogram);
    } // setupUi

    void retranslateUi(QMainWindow *firstprogram)
    {
        firstprogram->setWindowTitle(QApplication::translate("firstprogram", "firstprogram", 0));
        load_button->setText(QApplication::translate("firstprogram", "Load Video", 0));
        display_image->setText(QApplication::translate("firstprogram", "Image", 0));
        play_pause_button->setText(QApplication::translate("firstprogram", "Play", 0));
        stop_button->setText(QApplication::translate("firstprogram", "Stop", 0));
        time_start_label->setText(QApplication::translate("firstprogram", "00:00:00", 0));
        time_end_label->setText(QApplication::translate("firstprogram", "00:00:00", 0));
        tabWidget->setTabText(tabWidget->indexOf(playback_tab), QApplication::translate("firstprogram", "Playback", 0));
        display_record->setText(QApplication::translate("firstprogram", "Image", 0));
        stop_record_button->setText(QApplication::translate("firstprogram", "Record", 0));
        groupBox->setTitle(QApplication::translate("firstprogram", "Record On:", 0));
        human_checkbox->setText(QApplication::translate("firstprogram", "Detected Human", 0));
        movement_checkbox->setText(QApplication::translate("firstprogram", "Detected Movement", 0));
        everything_checkbox->setText(QApplication::translate("firstprogram", "Everything", 0));
        groupBox_2->setTitle(QApplication::translate("firstprogram", "Status:", 0));
        camstatus_label->setText(QApplication::translate("firstprogram", "no camera detected", 0));
        loadcam_button->setText(QApplication::translate("firstprogram", "Load Camera", 0));
        record_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("firstprogram", "Monitor", 0));
        menuMain_Window->setTitle(QApplication::translate("firstprogram", "Main Window", 0));
    } // retranslateUi

};

namespace Ui {
    class firstprogram: public Ui_firstprogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTPROGRAM_H

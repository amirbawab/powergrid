#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "Player.h"
#include <memory>
#include "DataStore.h"
#include <QPainter>
#include <QStyleOption>

class BoardProfileWidget : public QWidget {
public:
	BoardProfileWidget();
	~BoardProfileWidget();
	void Refresh();
private:
	QLabel *playerNameLabel;
	QLabel *playerPictureLabel;
	QLabel *playerElektroLabel;
	QGridLayout *gridLayout;
};

class BoardResourcePowerPlantWiget : public QWidget {
public:
	BoardResourcePowerPlantWiget();
	~BoardResourcePowerPlantWiget();
	void SetPowerPlantCard(std::shared_ptr<PowerPlantCard> powerPlantCard) { this->powerPlantCard = powerPlantCard; }
	void Refresh();
private:
	std::shared_ptr<PowerPlantCard> powerPlantCard;
	QGridLayout *gridLayout;
	std::vector<QLabel*> resourceLables;
	void paintEvent(QPaintEvent *e);
};

class BoardPlayerPowerPlantsWidget : public QWidget {
public:
	BoardPlayerPowerPlantsWidget();
	~BoardPlayerPowerPlantsWidget();
	void Refresh();
private:
	std::vector<BoardResourcePowerPlantWiget*> playerPowerPlantsWidgets;
	QGridLayout *gridLayout;
};

class CounterWidget : public QWidget {
	Q_OBJECT
public:
	CounterWidget();
	~CounterWidget();
private:
	QGridLayout *gridLayout;
	QPushButton *plusBtn, *minusBtn;
	QLabel *numberLabel;
	void paintEvent(QPaintEvent *pe);
private slots:
	void increment();
	void decrement();
};

class StepOnePanel : public QWidget {
public:
	StepOnePanel();
	~StepOnePanel();
private:
	QGridLayout *gridLayout;
	QPushButton *okButton;
	QPushButton *skipButton;
	CounterWidget *counterWidget;
};

class BoardMessageWidget : public QWidget {
public:
	BoardMessageWidget();
	~BoardMessageWidget();
	void Refresh();
private:
	QGridLayout *gridLayout;
	QLabel *questionLabel;
	StepOnePanel *stepOnePanel;
};

class BoardBottomWidget : public QWidget {
public:
	BoardBottomWidget();
	~BoardBottomWidget();
	void Refresh();
private:
	QGridLayout *gridLayout;
	BoardProfileWidget *boardProfileWidget;
	BoardPlayerPowerPlantsWidget *boardPlayerPowerPlantsWidget;
	BoardMessageWidget *boardMessageWidget;
};

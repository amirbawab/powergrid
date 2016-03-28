#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>

class OverviewModeWidget : public QWidget {
public:
	OverviewModeWidget();
	~OverviewModeWidget();
private:
	QScrollArea *scrollArea;
	QGridLayout *gridLayout;
};


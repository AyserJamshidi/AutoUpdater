#pragma once

#include <QtWidgets/QMainWindow>
#include <Windows.h>
#include <string>

#include "ui_AutoUpdater.h"

class AutoUpdater : public QMainWindow {
	Q_OBJECT

public:
	AutoUpdater(QWidget* parent = Q_NULLPTR);
	~AutoUpdater();

private:
	Ui::AutoUpdaterClass* ui;
	bool IsErrorMessage(std::string reply);
	void AnnounceText(QString message);
	void LoadingPage(bool turnOn);
	void LimitQLineEditLength(int maxLength);
	void StartProgram(LPCTSTR lpApplicationName, LPWSTR argv);

	private slots:
	bool AttemptLogin();
};

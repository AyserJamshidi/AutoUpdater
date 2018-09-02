#include "AutoUpdater.h"
#include <qmovie.h>
#include <qbitmap.h>
#include <qsignalmapper.h>
#include <qmessagebox.h>
#include <LoginRequests.h>
#include <qdebug.h>
#include <ctime>
#include <array>
#include <locale>
#include <codecvt>

#include <Windows.h>
#include <WinHttp.h>

#pragma comment(lib, "urlmon.lib")

/* QT Variables */
QMovie* movie;
LoginRequests* loginReq;

/* Path Variables */
std::wstring urlDirectory = L"https://www.lmfaoown.com/aion_hack/";
std::wstring fileName = L"KR.Text.Font.zip";
std::wstring urlPath = urlDirectory + fileName;



AutoUpdater::AutoUpdater(QWidget *parent) : QMainWindow(parent), ui(new Ui::AutoUpdaterClass) {
	ui->setupUi(this);
	//setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	movie = new QMovie(":/AutoUpdater/Resources/loading.gif");

	LimitQLineEditLength(10);

	// Button and trigger connections
	connect(ui->login_Button, SIGNAL(clicked()), this, SLOT(AttemptLogin()));


	//QSignalMapper* signalMapper = new QSignalMapper(this);

	//connect(ui.login_Button, SIGNAL(clicked()), this, SLOT());
}

AutoUpdater::~AutoUpdater() {
	delete ui;
}

bool AutoUpdater::AttemptLogin() {
	//LoadingPage(true);
	//AnnounceText("Attempting Login");
	std::string givenUsername = ui->username_Field->text().toUtf8();
	std::string givenPassword = ui->password_Field->text().toUtf8();
	std::string reply;
	//if (givenUsername.length() > 0 && givenPassword.length() > 0) {
	std::string postData;

	if (givenUsername.length() > 0) {
		if (givenPassword.length() > 0) {
			std::string guid = QString::fromStdWString(loginReq->GetMachineGuid()).toStdString();
			std::string serials = std::to_string(loginReq->GetHddSerialsTotal());
			if (guid.length() > 0 && serials.length() > 0) {
				postData
					.append("usr=" + givenUsername)
					.append("&pwd=" + givenPassword)
					.append("&guid=" + guid); // Can not convert wstring to string easily without QStr
					//.append("&serials=" + serials);

				reply = loginReq->HttpsWebRequestPost("www.Lmfaoown.com",
					"/aion_hack/index.php",
					postData).c_str();
				qDebug() << QString::fromStdString(reply);
				//qDebug() << loginReq->GetHddSerialsTotal();

				if (!IsErrorMessage(reply)) {
					std::wstring TempPath;
					wchar_t wcharPath[MAX_PATH];

					if (GetTempPathW(MAX_PATH, wcharPath))
						TempPath = wcharPath;

					if (TempPath.length() > 0) {
						HRESULT downloadResult = URLDownloadToFile(NULL, urlPath.c_str(), (TempPath + fileName).c_str(), NULL, NULL);

						qDebug() << "Checking...";
						if (downloadResult == S_OK) {
							//StartProgram((TempPath + fileName).c_str(), L"-ip:123.123.123 -port:2106");
							// TODO Make this download hack.
							qDebug() << "Successful download!!";
							QCoreApplication::quit();
							return true;
						} else if (downloadResult == E_OUTOFMEMORY) {
							AnnounceText("Out of memory");
						} else {
							AnnounceText("Could not contact the server.");
						}
						return false;
					}
					AnnounceText("Error retrieving save location");
					return false;
				}
				return false; // Error message applied via IsErrorMessage()
			}
			AnnounceText("Error retrieving hardware information");
			return false;
		}
		AnnounceText("Please enter a password");
		return false;
	}

	AnnounceText("Please enter a username");
	return false;
	//QMessageBox::information(this, "Login Error", QString::fromStdString(loginReq->HttpsWebRequestPost("google.com", "/api.php?action=UserLogin", "loginUsername=" + givenUsername + "&loginPassword=" + givenPassword + "&url=/index.php?page=Portal")));
}

bool AutoUpdater::IsErrorMessage(std::string reply) {
	try {
		switch (std::stoi(reply)) { // String to Integer
		case 1001: // "Empty username and/or password"
			AnnounceText("Empty username and/or password");
			return true;
		case 1002: // "An error occured while attempting to search through the database"
			AnnounceText("Database error, please try again");
			return true;
		case 1003: // "Username or password is incorrect"
			AnnounceText("Username or password is incorrect");
			return true;
		case 1004: // "The IP set with this account doesn't match your current IP"
			AnnounceText("IP mismatch");
			return true;
		case 1005: // "Could not create HWID"
			AnnounceText("Could not create HWID");
			return true;
		case 1006: // "The HWID set with this account doesn't match your current HWID"
			AnnounceText("HWID mismatch");
			return true;
		}
	} catch (std::invalid_argument& e) {

	} catch (...) {

	}
	return false;
}

void AutoUpdater::AnnounceText(QString message) {
	LoadingPage(false);
	QMessageBox::information(this, "Oops!", "<html><head/><body><p><span style = \"font-size:10pt; color:#b01e3a;\">" + message + "</span></p></body></html>");
	//ui->status_Label->setText("<html><head/><body><p><span style=\"font-size:12pt; color:#b01e3a;\">" + message + "</span></p></body></html>");
}

void AutoUpdater::LoadingPage(bool turnOn) {
	if (turnOn) {
		ui->stackedWidget->setCurrentIndex(1);
		if (!movie->isValid())
			QCoreApplication::quit();

		ui->loadingGif_Label->setMovie(movie);
		ui->loadingGif_Label->setGeometry(QRect(-150, 0, 0, 0));
		ui->loadingGif_Label->setFixedHeight(300);
		ui->loadingGif_Label->setFixedWidth(500);
		movie->start();
	} else {
		ui->stackedWidget->setCurrentIndex(0);
		if (movie->isValid()) {
			movie->stop();
		}
	}
}

void AutoUpdater::LimitQLineEditLength(int maxLength) {
	ui->username_Field->setMaxLength(maxLength);
	ui->password_Field->setMaxLength(maxLength);
}

void AutoUpdater::StartProgram(LPCTSTR lpApplicationName, LPWSTR argv) {
	// additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcess(lpApplicationName,   // the path
		argv,			  // Command line
		FALSE,           // Process handle not inheritable
		FALSE,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		FALSE,           // No creation flags
		FALSE,           // Use parent's environment block
		FALSE,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
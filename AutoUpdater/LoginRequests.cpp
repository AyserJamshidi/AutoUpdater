#include <Windows.h>
#include <WinHttp.h>
#include <stdio.h>

#include "LoginRequests.h"

#pragma comment(lib, "winhttp.lib")

std::string LoginRequests::HttpsWebRequestPost(std::string domain, std::string url, std::string dat) {
	//Extra
	LPSTR  data = const_cast<char *>(dat.c_str());;
	DWORD data_len = strlen(data);


	std::wstring sdomain = get_utf16(domain, CP_UTF8);
	std::wstring surl = get_utf16(url, CP_UTF8);
	std::string response;

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer;
	BOOL  bResults = FALSE;
	HINTERNET  hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;
	LPCWSTR additionalHeaders = L"Content-Type: application/x-www-form-urlencoded\r\n";
	DWORD headersLength = -1;

	// Use WinHttpOpen to obtain a session handle.
	hSession = WinHttpOpen(L"Lmfaoown\'s Hack",
						   WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
						   WINHTTP_NO_PROXY_NAME,
						   WINHTTP_NO_PROXY_BYPASS, 0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect(hSession, sdomain.c_str(),
								  INTERNET_DEFAULT_HTTP_PORT, 0);

	// Create an HTTP request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest(hConnect, L"POST", surl.c_str(),
									  NULL, WINHTTP_NO_REFERER,
									  WINHTTP_DEFAULT_ACCEPT_TYPES,
									  0);

	// Send a request.
	if (hRequest)
		bResults = WinHttpSendRequest(hRequest,
									  additionalHeaders,
									  headersLength,
									  (LPVOID)data,
									  data_len,
									  data_len,
									  0);


	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, NULL);

	// Keep checking for data until there is nothing left.
	if (bResults) {
		do {
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
				printf("Error %u in WinHttpQueryDataAvailable.\n",
					   GetLastError());

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize + 1];
			if (!pszOutBuffer) {
				printf("Out of memory\n");
				dwSize = 0;
			} else {
				// Read the data.
				ZeroMemory(pszOutBuffer, dwSize + 1);

				if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer,
					dwSize, &dwDownloaded))
					printf("Error %u in WinHttpReadData.\n", GetLastError());
				else
					//printf("%s", pszOutBuffer);
					response = response + std::string(pszOutBuffer);
				// Free the memory allocated to the buffer.
				delete[] pszOutBuffer;
			}
		} while (dwSize > 0);
	}

	// Report any errors.
	if (!bResults)
		printf("Error %d has occurred.\n", GetLastError());

	// Close any open handles.
	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);

	return response;

}

std::wstring LoginRequests::get_utf16(const std::string &str, int codepage) {
	if (str.empty()) return std::wstring();
	int sz = MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), 0, 0);
	std::wstring res(sz, 0);
	MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), &res[0], sz);
	return res;
}

std::wstring LoginRequests::GetMachineGuid() {
	WCHAR vcVER[256];
	DWORD dwSize = _countof(vcVER);
	RegGetValueW(HKEY_LOCAL_MACHINE,
				 L"SOFTWARE\\Microsoft\\Cryptography",
				 L"MachineGuid", RRF_RT_REG_SZ, NULL, &vcVER, &dwSize);

	return vcVER;
}

DWORD LoginRequests::GetHddSerialsTotal() {
	DWORD TotalVolumeSerialNumbers = 0;
	LPCWSTR curLetter[] = { L"A:\\", L"B:\\", L"C:\\", L"D:\\", L"E:\\", L"F:\\", L"G:\\", L"H:\\", L"I:\\", L"J:\\", L"K:\\", L"L:\\",
		L"M:\\", L"N:\\", L"O:\\", L"P:\\", L"Q:\\", L"R:\\", L"S:\\", L"T:\\", L"U:\\", L"V:\\", L"W:\\", L"X:\\", L"Y:\\", L"Z:\\", };

	for (LPCWSTR curDriveLetter : curLetter) {
		DWORD CurrentVolumeSerialNumber = 0;

		GetVolumeInformation(curDriveLetter, NULL, NULL, &CurrentVolumeSerialNumber, NULL, NULL, NULL, NULL);
		TotalVolumeSerialNumbers += CurrentVolumeSerialNumber;
	}

	return TotalVolumeSerialNumbers;
}
#pragma once

#include <Windows.h>
#include <fstream>

class LoginRequests {
	public:
	std::string HttpsWebRequestPost(std::string domain, std::string url, std::string dat);
	std::wstring GetMachineGuid();
	DWORD GetHddSerialsTotal();

	private:
	std::wstring get_utf16(const std::string & str, int codepage);
};
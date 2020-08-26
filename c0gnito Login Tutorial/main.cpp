#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <Windows.h>
#include "include/c0gnito.h"
#include <string>
#pragma comment(lib, "urlmon.lib")
#include <stdio.h>
#include <sstream>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")

using namespace std;

std::string license;
int main(int argc, char* argv[]) {

	bool Connected = InternetCheckConnection(L"https://google.com", FLAG_ICC_FORCE_CONNECTION, 0);//Checks for internet connection
	if (!Connected)
	{

		cout << "Error: You are not connected to the Internet" << endl;
		Sleep(2500);
		exit(1);
	}
	if (Initialize("123456789qwertyuiopasdfghjklzxcvbnm"))//replace this with your public Key
	{
		std::cout << "Initialized\n";
	}
	else
	{
		std::cout << "Failed to initialize\n";
	}

	cout << "Running Security Checks...\n";
	Sleep(2500);
	std::string cur_dir(argv[0]);
	int pos = cur_dir.find_last_of("/\\");


	std::ifstream file(cur_dir.substr(0, pos) + "\\c0gnito.dll", std::ios::binary);

	if (file.is_open())
	{
		std::ostringstream contents;
		contents << file.rdbuf();

		std::hash<std::string> hash;

		cout << hash(contents.str()) << endl;//This will output your dll hash

		if (hash(contents.str()) != 15267821076292829319)//CHANGE THIS TO YOUR DLL HASH
		{
			Sleep(2500);
			std::cout << "Error: Failed to verify the integrity\n";
			exit(1);
		}

	}
	else
	{
		std::cout << "Error: Failed to find c0gnito.dll\n";
		exit(1);
	}

	std::cout << "Passed Security Validation\n";
	Sleep(2500);
	system("cls");

	cout << "Please enter your license:\n";

	std::cin >> license;
	std::string hwid = GetHardwareID();
	if (Authenticate(license.c_str(), hwid.c_str()))
	{

		std::cout << "Authenticated\n";
		std::cout << "Logged in as " + license << endl;
		Sleep(2500);
		//Run the rest of your code
	}
	else
	{
		std::cout << "Failed to Authenticate\n";
		Sleep(4000);
		exit(1);
	}

}
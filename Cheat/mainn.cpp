#pragma warning(disable : 4530)
#define WIN32_LEAN_AND_MEAN

#define safe_read(Addr, Type) driver::read<Type>(g_Sock, g_PID, Addr)
#define safe_write(Addr, Data, Type) driver::write<Type>(g_Sock, g_PID, Addr, Data)
#define safe_memcpy(Dst, Src, Size) driver::write_memory(g_Sock, g_PID, Dst, driver::read_memory(g_Sock, g_PID, Src, 0, Size), Size)

#include <Windows.h>
#include <psapi.h>
#include <d3d11.h>
#include <iostream>
#include <string>
#include <cassert>
#include <emmintrin.h>
#include <tlhelp32.h>
#include <winternl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <windows.h>

#include "driver.h"
#include "Offsets.h"

#include "sdk_new/math.h"
#include "vars/vars.h"

SOCKET g_Sock;
DWORD g_PID;
uint64_t u_Base;
uint64_t g_Base;
bool g_Locked;

#include "sdk/game_sdk.h"

#include "cheat_funcs/AimFuncs.h"
#include "cheat_funcs/MiscFuncs.h"
#include <thread>
#include <vector>
#include <chrono>

#include <random>



DWORD GetPID(const std::wstring& procname);
DWORD RPid();

UINT vps = 1;
D3D11_VIEWPORT viewport;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* RenderTargetView = NULL;
#define AllocCons 0
using namespace std;

void EntityZaLoop();
void MainLoop();
BasePlayer* Fetch();

BasePlayer* AimEntity = nullptr;
long long firstentry = 0;

UINT64 TodCycle = 0;

bool panic = false;

//FACE AddUtils














class Color
{
public:
	Color(int desiredColor) {
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		color = desiredColor;
	}

	friend ostream& operator<<(ostream& ss, Color obj) {
		SetConsoleTextAttribute(obj.consoleHandle, obj.color);
		return ss;
	}
private:
	int color;
	HANDLE consoleHandle;
	/*
	0 = black
	1 = blue
	2 = green
	3 = light blue
	4 = red
	5 = purple
	6 = gold
	7 = white
	*/
};


void randomizetitle()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> distr(0, 51);
	std::string name = "";
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < 15; ++i)
	{
		name = name + alphabet[distr(mt)];
		SetConsoleTitleA(name.c_str());
	}

}
void printlogo()
{

	system("cls");
	std::cout << Color(6) << R"(
\______ \_______|__|__  __ ___________  |    |    _________     __| _/___________  /_   |   \   _  \  
 |    |  \_  __ \  \  \/ // __ \_  __ \ |    |   /  _ \__  \   / __ |/ __ \_  __ \  |   |   /  /_\  \ 
 |    `   \  | \/  |\   /\  ___/|  | \/ |    |__(  <_> ) __ \_/ /_/ \  ___/|  | \/  |   |   \  \_/   \
/_______  /__|  |__| \_/  \___  >__|    |_______ \____(____  /\____ |\___  >__|     |___| /\ \_____  /
        \/                    \/                \/         \/      \/    \/               \/       \/                                                                             																			                                                                                   
        )";
	cout << "\n";
}


#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <string>
#include <iostream>

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <vector>




using namespace std;

string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}
#include <Wininet.h>
#include "junk.h"



#pragma comment(lib, "wininet.lib")

string DownloadString(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}


void main()
{
	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Overlay::Init, NULL, NULL, NULL);
	//Overlay::Init();
	printlogo();
	//////std::thread tgui(rungui);
	randomizetitle();
	J();
	try {
	/*	setlocale(0, "RU");
		bool valid = false;
		DWORD VSnumber;
		GetVolumeInformationA("C:\\", 0, 0, &VSnumber, 0, 0, 0, 0);
		stringstream sosi;
		sosi << VSnumber;
		string str = sosi.str();
		string lol = DownloadString("https://pastebin.com/raw/j8dmEN1L  ");
		string s;
		stringstream ss(lol);
		while (ss >> s) {
			if (s == str) {
				valid = true;
				break;
			}
		}
		if (valid == true) {
			cout << "OK" << endl;
		}
		else {
			cout << "ПАШЕЛ НАХУЙ" << endl;
			return;
		}*/
		std::cout << Color(4) << "Welcome " << Color(4) << getenv("USERNAME") << endl;;
		J();
		cout << "Init...";
		driver::initialize();
		cout << "OK" << endl;
		g_Locked = false;
		cout << "Connecting...";
		g_Sock = driver::connect();
		if (g_Sock == INVALID_SOCKET)
		{
			cout << "Connection fail!\n";
			cin.get();
			return;
		}
		cout << "OK" << endl;
	}
	catch (...){
		cout << "Driver ERROR!" << endl;
		cin.get();
		return;
	}
	g_PID = RPid();
	cout << "pid: " << g_PID << endl;
	cout << "Getting base address...";
	u_Base = driver::get_process_base_address(g_Sock, g_PID, 0); //0 - UnityPlayer.dll, 
	g_Base = driver::get_process_base_address(g_Sock, g_PID, 1); //1 - GameAssembly.dll
	if (u_Base == 0 || g_Base == 0)
	{
		cout << "Failed to get base addr...\n";
		cin.get();
		return;
	}
	
	J();
	
	
	EntityZaLoop();
	
	
	
	MainLoop();


	
	
	
	
	
		
	
}

void EntityZaLoop()
{

	long long i = 0;
	UINT64  ObjMgr = safe_read(u_Base + 0x17A6AD8, UINT64);
	UINT64  Obj = safe_read(ObjMgr + 0x8, UINT64);
	//std::cout << "ObjMgr " << ObjMgr << std::endl;

	bool LP_isValid = false;
	std::cout << "Loading..." << std::endl;

	for (UINT64 Obj = safe_read(ObjMgr + 0x8, UINT64); (Obj && (Obj != safe_read(ObjMgr, UINT64))); Obj = safe_read(Obj + 0x8, UINT64))
	{
		//std::cout << "Ent" << endl;
		UINT64 GameObject = safe_read(Obj + 0x10, UINT64);
		WORD Tag = safe_read(GameObject + 0x54, WORD);

		if (Tag == 6)
		{
			UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
			UINT64 Entity = safe_read(ObjClass + 0x18, UINT64);

			BasePlayer* Player = (BasePlayer*)safe_read(Entity + 0x28, UINT64);
			if (!Player->IsValid())continue;





			std::cout << "BASEPLAYER FOUND" << endl;
			std::cout << "ID: " << Player->GetSteamID() << endl;



			if (safe_read(safe_read(GameObject + 0x60, UINT64), UINT64) == 0x616C506C61636F4C)
			{


				LP_isValid = true;
				LocalPlayer.BasePlayer = Player;
				firstentry = Obj;
				if (TodCycle && LocalPlayer.pViewMatrix)
					return;

			}
		}

		else if (Tag == 5) {
			UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
			UINT64	Entity = safe_read(ObjClass + 0x18, UINT64);
			LocalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0x2E4);
		}

		else if (Tag == 20011) {
			UINT64 ObjClass = safe_read(GameObject + 0x30, UINT64);
			UINT64	Entity = safe_read(ObjClass + 0x18, UINT64);
			UINT64 Dome = safe_read(Entity + 0x28, UINT64);
			TodCycle = safe_read(Dome + 0x38, UINT64);
		}



	NextEnt:
		continue;
	}
	if (!TodCycle || !LP_isValid || LocalPlayer.BasePlayer->IsMenu()) {

		std::cout << "Cant find player/sky/youre in menu..." << TodCycle << " " << LP_isValid << " " << LocalPlayer.BasePlayer->IsMenu() << endl;
		std::cin.get();
		exit(1);
	}
}


void MainLoop() {

	std::cout << "Loaded!\n";
	int last = -1;
	while (true) {
		RPid();
		Misc(TodCycle);










		if (LocalPlayer.BasePlayer->IsDead()) {
			last = 0;
			continue;
		}
		auto begin = std::chrono::steady_clock::now();
		//if (Activate && (GetAsyncKeyState(VK_RBUTTON) || GetAsyncKeyState(VK_LBUTTON))) Aim(Fetch());
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		//if(elapsed_ms.count()) cout << "Fetch OK in " << elapsed_ms.count() << " ms\n";
		WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
		if (last && last != active->GetUID()) {
			std::cout << "Weapon patching ";
		std:cout << "id " << active->GetID() << std::endl;
			last = active->GetUID();
			if (last) {
				WeaponPatch(active);
			}
		}
		else if (!last)
			last = active->GetUID();


	}
}

BasePlayer* Fetch() {

	DWORD64 Id = LocalPlayer.BasePlayer->GetActiveWeapon()->GetID();
	if (!Id || Id == 1525520776 || Id == 200773292)
		return nullptr; //building plan, hammer(киянка)
	UINT64 BaseNetworkable = safe_read(g_Base + 0x2815dd8, UINT64);
	UINT64 EntityRealm = safe_read(BaseNetworkable + 0xB8, UINT64);
	UINT64 ClientEntities = safe_read(EntityRealm, UINT64);
	UINT64 ClientEntities_list = safe_read(ClientEntities + 0x10, UINT64);
	UINT64 ClientEntities_values = safe_read(ClientEntities_list + 0x28, UINT64);
	int EntityCount = safe_read(ClientEntities_values + 0x10, int);
	//cout << "Entites " << EntityCount << endl;
	if (!EntityCount)
		return nullptr;
	UINT64 EntityBuffer = safe_read(ClientEntities_values + 0x18, UINT64);

	for (int i = EntityCount - 1; i >= EntityCount / 4; i--)
	{
		UINT64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64);
		UINT64 Object = safe_read(Entity + 0x10, UINT64);

		BasePlayer* Player = (BasePlayer*)safe_read(Object + 0x28, UINT64);
		if (!Player->IsValid())
			continue; //4 чтения

		if (VisibleCheck) {
			if (!Player->IsVisible())
				continue;
		} //2 чтения

		if (IgnoreTeam) {
			UINT64 EntitySID = Player->GetSteamID();
			int size = LocalPlayer.BasePlayer->GetTeamSize(); //3
			for (int j = 0; j < size; j++) {
				UINT64 SlotSID = LocalPlayer.BasePlayer->IsTeamMate(j);       //5
				if (SlotSID == EntitySID)
					continue;
			}
		}


	}
	return nullptr;
}

DWORD RPid() {
	if (g_PID) {
		if (!safe_read(g_Base, int)) {
			std::cout << "Rust closed...(or driver fail)" << std::endl;
			std::cin.get();
			exit(1);
		}
		return g_PID;
	}
	else {
		DWORD pid = GetPID(L"RustClient.exe");
		
		if (!pid) {
			std::cout << "Rust closed..." << std::endl;
			std::cin.get();
			exit(1);
		}
		return pid;
	}
}
DWORD GetPID(const std::wstring& procname)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32First(processesSnapshot, &processInfo);
	if (!procname.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!procname.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}





#pragma once
#include <conio.h>
#include "Utils.h"

using namespace std;

enum class KeyState
{
	Idle,
	Pressed,
	Stay,
	Released
};


class InputSystem
{
	int Key;
	int Minor;
	KeyState keys[256];
	HANDLE hStdin;
	DWORD fdwSaveOlMode;
	INPUT_RECORD ininbuf[128];

	VOID ErrorExit(LPSTR lpszMessage)
	{
		fprintf(stderr, "%s\n", lpszMessage);

		// Restore input mode on exit.

		SetConsoleMode(hStdin, fdwSaveOldMode);

		ExitProcess(0);
	}

	VOID KeyEventProc(KEY_EVENT_RECORD ker)
	{
		switch (keys[ker.wVirtualKeyCode & 0xff])
		{
		case KeyState::Idle:
			if(ker.bKeyDown == TRUE)
			{
				kers[key.virtualKeyCode] = KeyState::Pressed;
				break;
		case KeyState::Pressed:
			if (key.bKeyDown == TRUE)
				keys[ker.wVirtualKeyCode] = KeyState::Stay;
			else
				keys[ker.wVirtualKeyCode] = KeyState::Released;
			break;
		case KeyState::Stay:
			if (ker.bKeyDown == FALSE)
				keys[ker.wVirtualKeyCode] = KeyState::Released;
			break;
		case KeyState::Released:
			keys[ker.wRepeatCode] = KeyState::Idle;
				break;

		}
	}

	VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
	{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
		printf("Mouse event: ");

		switch (mer.dwEventFlags)
		{
		case 0:

			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				printf("left button press \n");
			}
			else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				printf("right button press \n");
			}
			else
			{
				printf("button press\n");
			}
			break;
		case DOUBLE_CLICK:
			printf("double click\n");
			break;
		case MOUSE_HWHEELED:
			printf("horizontal mouse wheel\n");
			break;
		case MOUSE_MOVED:
			printf("mouse moved\n");
			break;
		case MOUSE_WHEELED:
			printf("vertical mouse wheel\n");
			break;
		default:
			printf("unknown\n");
			break;
		}
	}

public:
	InpuSysem()
	{
		DWORD fdwMode;
		
		for(int i =0;i<256;i++)
			key[256]

	if(!setConsoleMode(hStdin,))

	}
	virtual ~InputSystem()
	{
		SeConsoleMode(hStdin, fdsavOldMode);
	}

	
	void readEveryFrame() 
	{
		DWORD cNumRead = -;

		Borland::GotoXY(0, 25);
		if (GetNumberOfConsoleInputEvents(hStdin, &cNumRead) == 0)
		{
			printf("Iput Reading failur%d \n", GetLastError());
			retrun;
		}

		for (int i = 0 i < 256; i++)
		{
			switch (keys[i])
			{
			case KeyState::Released:
				keys[i] = KeyState::Idle;
				break;
			case KeyState::Pressed:
				keys[i] = KeyState::Stay;
				break;
			}
		}



		if(cNumRead == 0)
		{
			for(int i = 0 i<int )


		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			128,         // size of read buffer
			&cNumRead)) // number of records read
			ErrorExit("ReadConsoleInput");


		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events

			case MENU_EVENT:   // disregard menu events
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	auto getKeyDown(WORD keyCode)
	{
		Borland::GotoXY(0, 26);
		printf("key sate ")
		return keys[keyCode & 0xff] == KeysState::pressed;
	}

	auto getKey(WORD keyCode)
	{
		printf("key state stay [%x] ", keys[keyCode ])
		return keys[keyCode & 0xff] == KeyState::Pressed ||
			keys[keyCode & 0xff] == KeyStae::Stay ||
			keys[KeyCode & 0xff] == KeySae::Released;

	auto getKeyUP(WORD keyCode)
	{
		return kys[keyCode & 0xff] == KeySatee::Released;
	}
};


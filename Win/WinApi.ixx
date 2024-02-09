module;

#include <Windows.h>

export module com.ntmonkeys.win.winapi;
export using ::HANDLE;
export using ::HWND;
export using ::CONSOLE_SCREEN_BUFFER_INFO;

import <stdexcept>;

namespace NT::Win
{
	export enum class StdDeviceType : DWORD
	{
		INPUT	= STD_INPUT_HANDLE,
		OUPUT	= STD_OUTPUT_HANDLE,
		ERR		= STD_ERROR_HANDLE
	};

	export class WinApi
	{
	public:
		[[nodiscard]]
		static HANDLE GetStdHandle(const StdDeviceType deviceType);

		[[nodiscard]]
		static HWND GetConsoleWindow();

		[[nodiscard]]
		static CONSOLE_SCREEN_BUFFER_INFO GetConsoleScreenBufferInfo(const HANDLE hConsole);
	};

	HANDLE WinApi::GetStdHandle(const StdDeviceType deviceType)
	{
		const HANDLE retVal{ ::GetStdHandle(static_cast<DWORD>(deviceType)) };
		if (!retVal || (retVal == INVALID_HANDLE_VALUE))
			throw std::runtime_error{ "Cannot retrieve the handle." };

		return retVal;
	}

	HWND WinApi::GetConsoleWindow()
	{
		const HWND retVal{ ::GetConsoleWindow() };
		if (!retVal)
			throw std::runtime_error{ "Cannot retrieve the handle." };

		return retVal;
	}

	CONSOLE_SCREEN_BUFFER_INFO WinApi::GetConsoleScreenBufferInfo(const HANDLE hConsole)
	{
		CONSOLE_SCREEN_BUFFER_INFO retVal{ };
		if (!(::GetConsoleScreenBufferInfo(hConsole, &retVal)))
			throw std::runtime_error{ "Cannot retrieve the info." };

		return retVal;
	}
}
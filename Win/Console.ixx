export module com.ntmonkeys.win.console;

import com.ntmonkeys.library.unique;
import com.ntmonkeys.library.glm;
import com.ntmonkeys.win.winapi;
import <cstdint>;

namespace NT::Win
{
	export class Console : public Lib::Unique
	{
	public:
		virtual ~Console() noexcept = default;

		[[nodiscard]]
		constexpr uint32_t getWidth() const noexcept;

		[[nodiscard]]
		constexpr uint32_t getHeight() const noexcept;

		[[nodiscard]]
		static Console &getInstance();

	private:
		HWND __windowHandle{ };
		HANDLE __consoleHandle{ };

		CONSOLE_SCREEN_BUFFER_INFO __screenBufferInfo{ };

		Console();

		void __retrieveWindowHandle();
		void __retrieveConsoleHandle();
		void __validateScreenBufferInfo();
	};

	Console::Console()
	{
		__retrieveWindowHandle();
		__retrieveConsoleHandle();
		__validateScreenBufferInfo();
	}

	constexpr uint32_t Console::getWidth() const noexcept
	{
		const auto &[left, top, right, bottom] {__screenBufferInfo.srWindow };
		return static_cast<uint32_t>(right - left);
	}

	constexpr uint32_t Console::getHeight() const noexcept
	{
		const auto &[left, top, right, bottom] {__screenBufferInfo.srWindow };
		return static_cast<uint32_t>(bottom - top);
	}

	Console &Console::getInstance()
	{
		static Console instance;
		return instance;
	}

	void Console::__retrieveWindowHandle()
	{
		__windowHandle = WinApi::GetConsoleWindow();
	}

	void Console::__retrieveConsoleHandle()
	{
		__consoleHandle = WinApi::GetStdHandle(StdDeviceType::OUPUT);
	}

	void Console::__validateScreenBufferInfo()
	{
		__screenBufferInfo = WinApi::GetConsoleScreenBufferInfo(__consoleHandle);
	}
}
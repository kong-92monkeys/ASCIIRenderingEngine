export module com.ntmonkeys.win.console;

import com.ntmonkeys.library.unique;
import com.ntmonkeys.library.glm;
import <cstdint>;

namespace NT::Win
{
	export class Console : public Lib::Unique
	{
	public:
		[[nodiscard]]
		constexpr uint32_t getWidth() const noexcept;

		[[nodiscard]]
		constexpr uint32_t getHeight() const noexcept;

	private:
		uint32_t __width{ };
		uint32_t __height{ };
	};

	constexpr uint32_t Console::getWidth() const noexcept
	{
		return __width;
	}

	constexpr uint32_t Console::getHeight() const noexcept
	{
		return __height;
	}
}
export module com.ntmonkeys.graphics.image;

import com.ntmonkeys.library.unique;
import com.ntmonkeys.library.glm;

namespace NT::Graphics
{
	export class Image : public Lib::Unique
	{
	public:
		explicit Image(const uint32_t width, const uint32_t height);

		[[nodiscard]]
		constexpr uint32_t getWidth() const noexcept;

		[[nodiscard]]
		constexpr uint32_t getHeight() const noexcept;

		virtual void setPixels(const glm::vec3 *const pixels) = 0;

	private:
		const uint32_t __width;
		const uint32_t __height;
	};

	Image::Image(const uint32_t width, const uint32_t height) :
		__width{ width }, __height{ height }
	{}

	constexpr uint32_t Image::getWidth() const noexcept
	{
		return __width;
	}

	constexpr uint32_t Image::getHeight() const noexcept
	{
		return __height;
	}
}
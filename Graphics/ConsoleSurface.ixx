export module com.ntmonkeys.graphics.consolesurface;

export import com.ntmonkeys.win.console;
export import com.ntmonkeys.graphics.surface;
import <memory>;

namespace NT::Graphics
{
	export class ConsoleImage : public Image
	{
	public:
		ConsoleImage(Win::Console &console) noexcept;

		virtual void setPixels(const glm::vec3 *const pixels) override;

	private:
		Win::Console &__console;
	};

	export class ConsoleSurface : public Surface
	{
	public:
		struct CreateInfo
		{
		public:
			Win::Console *pConsole{ };
		};

		ConsoleSurface(const CreateInfo &createInfo);

		[[nodiscard]]
		virtual Image &getImage() noexcept override;

		virtual void sync() override;

	private:
		std::unique_ptr<ConsoleImage> __image;

		void __createImage(Win::Console &console);
	};

	ConsoleImage::ConsoleImage(Win::Console &console) noexcept :
		Image{ console.getWidth(), console.getHeight() },
		__console{ console }
	{}

	void ConsoleImage::setPixels(const glm::vec3 *const pixels)
	{
		// TODO
	}

	ConsoleSurface::ConsoleSurface(const CreateInfo &createInfo)
	{
		__createImage(*(createInfo.pConsole));
	}

	Image &ConsoleSurface::getImage() noexcept
	{
		return *__image;
	}

	void ConsoleSurface::sync()
	{
		// TODO
	}

	void ConsoleSurface::__createImage(Win::Console &console)
	{
		__image = std::make_unique<ConsoleImage>(console);
	}
}
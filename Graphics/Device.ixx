export module com.ntmonkeys.graphics.device;

import com.ntmonkeys.library.unique;
import com.ntmonkeys.graphics.consolesurface;
import <memory>;

namespace NT::Graphics
{
	export class Device : public Lib::Unique
	{
	public:
		struct CreateInfo
		{
		public:

		};

		Device(const CreateInfo &createInfo);

		[[nodiscard]]
		std::unique_ptr<Surface> createSurface(const ConsoleSurface::CreateInfo &createInfo);

		void waitIdle() noexcept;

	private:
	};

	Device::Device(const CreateInfo &createInfo)
	{}

	std::unique_ptr<Surface> Device::createSurface(const ConsoleSurface::CreateInfo &createInfo)
	{
		return std::make_unique<ConsoleSurface>(createInfo);
	}

	void Device::waitIdle() noexcept
	{

	}
}
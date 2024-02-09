import com.ntmonkeys.graphics.device;
import com.ntmonkeys.graphics.consolesurface;

int main()
{
	NT::Win::Console &console{ NT::Win::Console::getInstance() };

	/*

	NT::Graphics::Device::CreateInfo deviceCreateInfo;
	NT::Win::Console &console{ NT::Win::Console::getInstance() };

	NT::Graphics::Device device{ deviceCreateInfo };

	NT::Graphics::ConsoleSurface::CreateInfo createInfo
	{
		.pConsole{ &console }
	};

	auto surface = device.createSurface(createInfo);
	device.waitIdle();*/

	return 0;
}
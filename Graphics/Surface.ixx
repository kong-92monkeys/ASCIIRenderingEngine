export module com.ntmonkeys.graphics.surface;

import com.ntmonkeys.library.unique;
export import com.ntmonkeys.graphics.image;

namespace NT::Graphics
{
	export class Surface : public Lib::Unique
	{
	public:
		[[nodiscard]]
		virtual Image &getImage() noexcept = 0;
		virtual void sync() = 0;

		[[nodiscard]]
		const Image &getImage() const noexcept;
	};

	const Image &Surface::getImage() const noexcept
	{
		return const_cast<Surface *>(this)->getImage();
	}
}
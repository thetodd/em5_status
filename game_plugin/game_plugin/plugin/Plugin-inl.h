namespace flo11
{

	inline Plugin::~Plugin()
	{
		// Nothing to do in here
	}

	inline const char* Plugin::getName() const
	{
		return "Status component plugin";
	}

	inline const char* Plugin::getVendor() const
	{
		return "Florian 11-47-1";
	}

	inline const char* Plugin::getDescription() const
	{
		return "Adds status components to vehicles.";
	}

}

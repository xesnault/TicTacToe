#include <string>
#include <cstring>

class Args
{
	public:

	Args(int argc, char** argv) : argCount(argc), args(argv)
	{
		
	}

	bool Has(std::string key) const
	{
		for (int i = 0; i < argCount; ++i)
		{
			if (std::strcmp(args[i], key.c_str()) == 0)
				return true;
		}
		return false;
	}

	std::string ValueOf(std::string key) const
	{
		for (int i = 0; i < argCount; ++i)
		{
			if (std::strcmp(args[i], key.c_str()) == 0 && i < argCount + 1 && args[i + 1][0] != '-')
				return args[i + 1];
		}
		return "";
	}

	private:

	int argCount;
	char** args;
};
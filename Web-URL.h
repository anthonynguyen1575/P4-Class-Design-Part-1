#include <string>

class URL {
public:
	URL(std::string url);

	std::string myURL;
	std::string myScheme;
	std::string myAuthority;
	std::string myPath;
	
};

std::string getURL(URL url);
std::string getScheme(URL url);
std::string getAuthority(URL url);
std::string getPath(URL url);
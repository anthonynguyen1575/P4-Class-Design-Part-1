#include "Web-URL.h"

URL::URL(std::string url)
	: myURL{ url } {

    int colonPlacement = myURL.find(":");

    myScheme = myURL.substr(0, colonPlacement + 1);

    int forwardSlashPlacement = myURL.find_first_of("/", colonPlacement + 3);

    myAuthority = myURL.substr(colonPlacement + 1, forwardSlashPlacement - colonPlacement - 1);
    myPath = myURL.substr(forwardSlashPlacement);
}

std::string getURL(URL url) {
    return url.myURL;
}

std::string getScheme(URL url) {
    return url.myScheme;
}

std::string getAuthority(URL url) {
    return url.myAuthority;
}

std::string getPath(URL url) {
    return url.myPath;
}

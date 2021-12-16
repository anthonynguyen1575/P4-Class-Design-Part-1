#include <string>

class Metadata {
public:
	Metadata(std::string fileName, std::string imageType, std::string date, 
		double size, std::string author, int width, int height, std::string apertureSize,
		std::string exposureTime, int iso, bool flash);

	std::string myFileName;
	std::string myImageType;
	std::string myDate;
	double mySize;
	std::string myAuthor;
	int myWidth;
	int myHeight;
	std::string myApertureSize;
	std::string myExposureTime;
	int myISO;
	bool myFlash;

};

std::string getFileName(Metadata metadata);
std::string getImageType(Metadata metadata);
std::string getDate(Metadata metadata);
double getSize(Metadata metadata);
std::string getAuthor(Metadata metadata);
int getWidth(Metadata metadata);
int getHeight(Metadata metadata);
std::string getApertureSize(Metadata metadata);
std::string getExposureTime(Metadata metadata);
int getISO(Metadata metadata);
bool getFlash(Metadata metadata);

void setFileName(Metadata& metadata, std::string fileName);
void setImageType(Metadata& metadata, std::string imageType);
void setDate(Metadata& metadata, std::string date);
void setSize(Metadata& metadata, double size);
void setAuthor(Metadata& metadata, std::string author);
void setWidth(Metadata& metadata, int width);
void setHeight(Metadata& metadata, int height);
void setApertureSize(Metadata& metadata, std::string apertureSize);
void setExposureTime(Metadata& metadata, std::string exposureTime);
void setISO(Metadata& metadata, int iso);
void setFlash(Metadata& metadata, bool flash);

void printMetadata(Metadata metadata);

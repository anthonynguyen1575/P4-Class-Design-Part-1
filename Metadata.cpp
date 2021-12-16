#include <iostream>
#include "Metadata.h"

Metadata::Metadata(std::string fileName, std::string imageType, std::string date,
	double size, std::string author, int width, int height, std::string apertureSize,
	std::string exposureTime, int iso, bool flash)
	: myFileName { fileName }, myImageType { imageType }, myDate { date }, mySize { size },
	myAuthor { author }, myWidth { width }, myHeight { height }, myApertureSize { apertureSize },
	myExposureTime{ exposureTime }, myISO{ iso }, myFlash{ flash } { }

std::string getFileName(Metadata metadata) {
	return metadata.myFileName;
}

std::string getImageType(Metadata metadata) {
	return metadata.myImageType;
}

std::string getDate(Metadata metadata) {
	return metadata.myDate;
}

double getSize(Metadata metadata) {
	return metadata.mySize;
}

std::string getAuthor(Metadata metadata) {
	return metadata.myAuthor;
}

int getWidth(Metadata metadata) {
	return metadata.myWidth;
}

int getHeight(Metadata metadata) {
	return metadata.myHeight;
}

std::string getApertureSize(Metadata metadata) {
	return metadata.myApertureSize;
}

std::string getExposureTime(Metadata metadata) {
	return metadata.myExposureTime;
}

int getISO(Metadata metadata) {
	return metadata.myISO;
}

bool getFlash(Metadata metadata) {
	return metadata.myFlash;
}

void setFileName(Metadata& metadata, std::string fileName) {
	metadata.myFileName = fileName;
}

void setImageType(Metadata& metadata, std::string imageType) {
	if(imageType == "PNG" || imageType == "GIF" || imageType == "JPEG") {
		metadata.myImageType = imageType;
	}
	else {
		while (imageType != "PNG" || imageType != "GIF" || imageType != "JPEG") {
			std::cout << "Please enter an accepted image type (PNG, GIF, JPEG)\n";
			std::cin >> imageType;

			if (imageType == "PNG" || imageType == "GIF" || imageType == "JPEG") {
				break;
			}
		}
		metadata.myImageType = imageType;
	}
}
// dates have to be in the form of MM/DD/YYYY
void setDate(Metadata& metadata, std::string date) {
	int firstForwardSlash = date.find_first_of("/");
	int month = std::stoi(date.substr(0, firstForwardSlash));
	std::string dayAndYear = date.substr(firstForwardSlash + 1);
	int secondForwardSlash = dayAndYear.find_first_of("/");
	int day = std::stoi(dayAndYear.substr(0, secondForwardSlash));

	if(month <= 12 and month > 0 and day <= 31 and day > 0) {
		metadata.myDate = date;
	}
	else {
		while (month > 12 || month < 0 || day > 31 || day < 0) {
			std::cout << "Please enter the date in the proper format with proper values. (MM/DD/YYYY)\n";
			std::cin >> date;
			int firstForwardSlash = date.find_first_of("/");
			int month = std::stoi(date.substr(0, firstForwardSlash));
			std::string dayAndYear = date.substr(firstForwardSlash + 1);
			int secondForwardSlash = dayAndYear.find_first_of("/");
			int day = std::stoi(dayAndYear.substr(0, secondForwardSlash));

			if (month <= 12 and month > 0 and day <= 31 and day > 0) {
				break;
			}
		}
		metadata.myDate = date;
	}
}

void setSize(Metadata& metadata, double size) {
	metadata.mySize = size;
}

void setAuthor(Metadata& metadata, std::string author) {
	metadata.myAuthor = author;
}

void setWidth(Metadata& metadata, int width) {
	metadata.myWidth = width;
}

void setHeight(Metadata& metadata, int height) {
	metadata.myHeight = height;
}

void setApertureSize(Metadata& metadata, std::string apertureSize) {
	std::string firstHalf = apertureSize.substr(0, 2);
	int secondHalf = std::stoi(apertureSize.substr(2));

	if(firstHalf == "f/" and secondHalf > 0) {
		metadata.myApertureSize = apertureSize;
	}
	else {
		while (firstHalf != "f/" || secondHalf <= 0) {
			std::cout << "Please enter a valid aperture size in the form 'f/#', where '#' is some positive integer.\n";
			std::cin >> apertureSize;
			std::string firstHalf = apertureSize.substr(0, 2);
			int secondHalf = std::stoi(apertureSize.substr(2));

			if (firstHalf == "f/" and secondHalf > 0) {
				break;
			}
		}
		metadata.myApertureSize = apertureSize;
	}
}

void setExposureTime(Metadata& metadata, std::string exposureTime) {
	int forwardSlashPlacement = exposureTime.find_first_of("/");
	int denominator = std::stoi(exposureTime.substr(forwardSlashPlacement + 1));

	if (denominator > 0) {
		metadata.myExposureTime = exposureTime;
	}
	else {
		while (denominator <= 0) {
			std::cout << "You can not have a zero in the denominator for a shutter speed. Please enter a correct value!\n";
			std::cin >> exposureTime;
			int forwardSlashPlacement = exposureTime.find_first_of("/");
			int denominator = std::stoi(exposureTime.substr(forwardSlashPlacement + 1));

			if (denominator > 0) {
				break;
			}
		}
		metadata.myExposureTime = exposureTime;
	}
}

void setISO(Metadata& metadata, int iso) {
	metadata.myISO = iso;
}

void setFlash(Metadata& metadata, bool flash) {
	metadata.myFlash = flash;
}

void printMetadata(Metadata metadata) {
	std::cout << "File name: " << getFileName(metadata) << "\n";
	std::cout << "Image type: " << getImageType(metadata) << "\n";
	std::cout << "Date: " << getDate(metadata) << "\n";
	std::cout << "Image File Size (MB): " << std::to_string(getSize(metadata)) << "\n";
	std::cout << "Author: " << getAuthor(metadata) << "\n";
	std::cout << "Image dimensions (px): " << std::to_string(getWidth(metadata)) << "x" << std::to_string(getHeight(metadata)) << "\n";
	std::cout << "Aperture size: " << getApertureSize(metadata) << "\n";
	std::cout << "Exposure time: " << getExposureTime(metadata) << "\n";
	std::cout << "ISO: " << std::to_string(getISO(metadata)) << "\n";
	if (getFlash(metadata) == 0) {
		std::cout << "Flash: Off" << "\n";
	}
	else {
		std::cout << "Flash: On" << "\n";
	}
}
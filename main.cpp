#include "ImageUpscaler.h"
#include <iostream>

int main(const int argc, const char* const* const argv)
{
	ImageUpscaler app;
	app.init(argc, argv);

	try
	{
		app.run();
	}
	catch (cv::Exception e)
	{
		std::cerr << "OpenCV exception occured!\nWhat: " << e.what() << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cerr << "Invalid argument exception occured!\nWhat: " << e.what() << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cerr << "Runtime error occured!\nWhat: " << e.what() << std::endl;
	}
	return 0;
}
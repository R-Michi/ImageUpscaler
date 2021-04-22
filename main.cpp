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

#if 0
	constexpr char IMAGE_PATH[] = "../../../images/minecraft_bricks.png";
	constexpr char MODEL_PATH[] = "../../../models/LapSRN_x8.pb";

	cv::dnn_superres::DnnSuperResImpl sr;

	// image to upscale
	cv::Mat image = cv::imread(IMAGE_PATH);
	if (image.empty())
	{
		std::cout << "Could not open file \"" << IMAGE_PATH << "\"!" << std::endl;
		return -1;
	}
	
	// read model for AI upscaler
	sr.readModel(MODEL_PATH);

	// set correct model and upscaling factor
	sr.setModel("lapsrn", 8);

	// upscale and write image
	cv::Mat upscaled_image;
	try
	{
		sr.upsample(image, upscaled_image);
	}
	catch (cv::Exception e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	cv::Mat filtered_image;
	cv::bilateralFilter(upscaled_image, filtered_image, 3, 75, 75);

	if (!cv::imwrite("../../../images/upscaled.png", upscaled_image))
	{
		std::cerr << "Write image failed!" << std::endl;
		return -1;
	}

	if (!cv::imwrite("../../../images/filtered.png", filtered_image))
	{
		std::cerr << "Write image failed!" << std::endl;
		return -1;
	}


	cv::imshow("upscaled image", upscaled_image);
	cv::imshow("filtered image", filtered_image);
	cv::waitKey(0);
#endif

	return 0;
}
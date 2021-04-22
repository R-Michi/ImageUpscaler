#pragma once

#include <opencv2/dnn_superres.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>

class ImageUpscaler
{
private:
	enum Model : int
	{
		EDSR_x2 = 0,
		EDSR_x3 = 1,
		EDSR_x4 = 2,
		ESPCN_x2 = 3,
		ESPCN_x3 = 4,
		ESPCN_x4 = 5,
		FSRCNN_x2 = 6,
		FSRCNN_x3 = 7,
		FSRCNN_x4 = 8,
		FSRCNN_small_x2 = 9,
		FSRCNN_small_x3 = 10,
		FSRCNN_small_x4 = 11,
		LapSRN_x2 = 12, 
		LapSRN_x4 = 13,
		LapSRN_x8 = 14,
		MODEL_MAX_ENUM = 15
	};

	int argc;
	const char* const* argv;

	static const char* strmodel(Model model);
	static const char* get_file_name(Model model);
	static int get_upscale(Model model);

	constexpr static char MODEL_PATH[] = "./models/";

public:
	ImageUpscaler(void) = default;
	virtual ~ImageUpscaler(void) = default;

	void init(int argc, const char* const* const argv);
	void run(void);
};
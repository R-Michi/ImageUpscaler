#include "ImageUpscaler.h"
#include <string>
#include <string.h>
#include <iostream>

void ImageUpscaler::init(int argc, const char* const* const argv)
{
	this->argc = argc;
	this->argv = argv;
}

void ImageUpscaler::run(void)
{
	// command: image_upscaler <src_image> <dst_image> <model>
	if (argc != 4)
		throw std::invalid_argument("Syntax: image_upscaler.exe <src_image> <dst_image> <model>");

	std::string src_image = this->argv[1];
	std::string dst_image = this->argv[2];
	std::string inp_model_name = this->argv[3];

	// find model
	Model model = Model::MODEL_MAX_ENUM;
	for (int i = 0; i < Model::MODEL_MAX_ENUM; i++)
	{
		if (get_file_name(static_cast<Model>(i)) == inp_model_name)
			model = static_cast<Model>(i);
	}
	if (model == Model::MODEL_MAX_ENUM)
		throw std::runtime_error("Could not find model \"" + inp_model_name + "\"");

	// get file-name, string-name and upsample from model
	std::string model_file_path = MODEL_PATH + std::string(get_file_name(model)) + ".pb";
	std::string model_name		= strmodel(model);
	int upsample				= get_upscale(model);

	cv::dnn_superres::DnnSuperResImpl sr;
	sr.readModel(model_file_path);
	sr.setModel(model_name, upsample);

	// read surce image
	cv::Mat src = cv::imread(src_image);
	if (src.empty())
		throw std::runtime_error("Failed to open source image file \"" + src_image + "\"");

	// upsample image
	cv::Mat dst;
	sr.upsample(src, dst);

	// write destination image
	if (!cv::imwrite(dst_image, dst))
		throw std::runtime_error("Failed to write image file \"" + dst_image + "\"");
}

const char* ImageUpscaler::strmodel(Model model)
{
	switch (model)
	{
	case EDSR_x2:
		return "edsr";
	case EDSR_x3:
		return "edsr";
	case EDSR_x4:
		return "edsr";
	case ESPCN_x2:
		return "espcn";
	case ESPCN_x3:
		return "espcn";
	case ESPCN_x4:
		return "espcn";
	case FSRCNN_x2:
		return "fsrcnn";
	case FSRCNN_x3:
		return "fsrcnn";
	case FSRCNN_x4:
		return "fsrcnn";
	case FSRCNN_small_x2:
		return "fsrcnnsmall";
	case FSRCNN_small_x3:
		return "fsrcnnsmall";
	case FSRCNN_small_x4:
		return "fsrcnnsmall";
	case LapSRN_x2:
		return "lapsrn";
	case LapSRN_x4:
		return "lapsrn";
	case LapSRN_x8:
		return "lapsrn";
	default:
		return "Unkndown model";
	}
}

const char* ImageUpscaler::get_file_name(Model model)
{
	switch(model)
	{
	case EDSR_x2:
		return "EDSR_x2";
	case EDSR_x3:
		return "EDSR_x3";
	case EDSR_x4:
		return "EDSR_x4";
	case ESPCN_x2:
		return "ESPCN_x2";
	case ESPCN_x3:
		return "ESPCN_x3";
	case ESPCN_x4:
		return "ESPCN_x4";
	case FSRCNN_x2:
		return "FSRCNN_x2";
	case FSRCNN_x3:
		return "FSRCNN_x3";
	case FSRCNN_x4:
		return "FSRCNN_x4";
	case FSRCNN_small_x2:
		return "FSRCNN--small_x2";
	case FSRCNN_small_x3:
		return "FSRCNN-small_x3";
	case FSRCNN_small_x4:
		return "FSRCNN-small_x4";
	case LapSRN_x2:
		return "LapSRN_x2";
	case LapSRN_x4:
		return "LapSRN_x4";
	case LapSRN_x8:
		return "LapSRN_x8";
	default:
		return "Unkndown model";
	}
}

int ImageUpscaler::get_upscale(Model model)
{
	switch (model)
	{
	case EDSR_x2:
		return 2;
	case EDSR_x3:
		return 3;
	case EDSR_x4:
		return 4;
	case ESPCN_x2:
		return 2;
	case ESPCN_x3:
		return 3;
	case ESPCN_x4:
		return 4;
	case FSRCNN_x2:
		return 2;
	case FSRCNN_x3:
		return 3;
	case FSRCNN_x4:
		return 4;
	case FSRCNN_small_x2:
		return 2;
	case FSRCNN_small_x3:
		return 3;
	case FSRCNN_small_x4:
		return 4;
	case LapSRN_x2:
		return 2;
	case LapSRN_x4:
		return 4;
	case LapSRN_x8:
		return 8;
	default:
		return -1;
	}
}
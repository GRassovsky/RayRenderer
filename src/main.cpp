// System includes
#include <iostream>
#include <fstream>

// Project includes
#include "vec3.h"
#include "color.h"



// Debug macro
#define DEBUG 0




int main()
{
	const int image_width = 256;
	const int image_height = 256;


	std::ofstream outfile( "render.ppm", std::ios_base::out);

	outfile << "P3\n" << image_width << " " << image_height << "\n255\n";
#if DEBUG
	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
#endif


	for( int j = image_height-1; j >= 0; --j )
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

		for( int i = 0; i < image_width; ++i )
		{
			color pixel_color{	static_cast<float>(i) / static_cast<float>(image_width-1), 
								static_cast<float>(j) / static_cast<float>(image_height-1),
								0.25f };

			write_color(outfile, pixel_color);
#if DEBUG
			write_color(std::cout, pixel_color);
#endif
		}
	}

	std::cerr << "\nDone.\n";
}

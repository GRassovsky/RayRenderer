#include <iostream>
#include <fstream>

#define DEBUG 0

int main()
{
	int nx = 200;
	int ny = 100;

	std::ofstream outfile( "render.ppm", std::ios_base::out);
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

#if DEBUG
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
#endif

	for( int j = ny-1; j >= 0; --j )
	{
		for( int i = 0; i < nx; ++i )
		{
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2f;

			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);

			outfile << ir << " " << ig << " " << ib << std::endl;
#if DEBUG
			std::cout << ir << " " << ig << " " << ib << std::endl;
#endif
		}
	}
}
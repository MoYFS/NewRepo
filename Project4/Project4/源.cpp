//#include "pch.h"
#include <iostream>
#include <ctime>
#include<fstream>
using namespace std;
struct vec3
{
	double x;
	double y;
	double z;
	vec3() {};
	vec3(double x, double y, double z) :x(x), y(y), z(z) {}
	double operator*(vec3 t)
	{
		return x * t.x + y * t.y + z * t.z;
	}
	vec3 operator+(vec3 t)
	{
		return vec3(x + t.x, y + t.y, z + t.z);
	}
};
class perlinNoise {
public:
	vec3 g[12] = { vec3(1,1,0),vec3(-1,1,0),vec3(1,-1,0),vec3(-1,-1,0),
		vec3(1,0,1),vec3(-1,0,1),vec3(1,0,-1),vec3(-1,0,-1), vec3(0,1,1),
		vec3(0,-1,1),vec3(0,1,-1),vec3(0,-1,-1) };
	vec3 vertex[25][25][25];
	perlinNoise()
	{
		srand((int)time(0));
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				for (int k = 0; k < 25; k++)
				{
					int mrand = rand() % 12;
					vertex[i][j][k] = g[mrand];
				}
			}
		}
	}
	double generateNoise(double x, double y, double z)
	{
		int X = (int)floor(x);
		int Y = (int)floor(y);
		int Z = (int)floor(z);

		double u = x - X;
		double v = y - Y;
		double w = z - Z;

		vec3 vec000 = vec3(u, v, w);
		vec3 vec010 = vec3(u, v, w) + vec3(0, -1, 0);
		vec3 vec100 = vec3(u, v, w) + vec3(-1, 0, 0);
		vec3 vec110 = vec3(u, v, w) + vec3(-1, -1, 0);
		vec3 vec001 = vec3(u, v, w) + vec3(0, 0, -1);
		vec3 vec011 = vec3(u, v, w) + vec3(0, -1, -1);
		vec3 vec101 = vec3(u, v, w) + vec3(-1, 0, -1);
		vec3 vec111 = vec3(u, v, w) + vec3(-1, -1, -1);

		double g000 = vec000 * vertex[X][Y][Z];
		double g010 = vec010 * vertex[X][Y + 1][Z];
		double g100 = vec100 * vertex[X + 1][Y][Z];
		double g110 = vec110 * vertex[X + 1][Y + 1][Z];
		double g001 = vec001 * vertex[X][Y][Z + 1];
		double g011 = vec011 * vertex[X][Y + 1][Z + 1];
		double g101 = vec101 * vertex[X + 1][Y][Z + 1];
		double g111 = vec111 * vertex[X + 1][Y + 1][Z + 1];

		u = fade(u);
		v = fade(v);
		w = fade(w);

		double lerpx1 = lerp(g000, g100, u);
		double lerpx2 = lerp(g010, g110, u);
		double lerpy1 = lerp(lerpx1, lerpx2, v);

		double lerpx3 = lerp(g001, g101, u);
		double lerpx4 = lerp(g011, g111, u);
		double lerpy2 = lerp(lerpx3, lerpx4, v);

		double lerpz = lerp(lerpy1, lerpy2, w);

		return lerpz;
	}
	double lerp(double a, double b, double t)
	{
		return a + t * (b - a);
	}
	double fade(double t)
	{
		return t * t * t * (t * (t * 6 - 15) + 10);
	}
};
int main()
{
	perlinNoise a;
	ofstream outfile("perlinNoise.ppm");
	int X = 400, Y = 400;
	outfile << "P3" << endl << X << " " << Y << endl << "255" << endl;
	for (double i = 0; i < 20; i += 0.05)
	{
		for (double j = 0; j < 20; j += 0.05)
		{
			int temp = (a.generateNoise(i, j, 7.856413) + 1.0) / 2.0 * 255.0;
			outfile << temp << " " << temp << " " << temp << " ";
		}
	}
}

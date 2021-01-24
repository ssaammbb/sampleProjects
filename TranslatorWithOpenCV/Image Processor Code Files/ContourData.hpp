
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
using namespace ml;

class ContourData
{
private:
	int minCountourSize = 100;
public:
	std::vector<Point> pointContour;
	Rect boundingRect;
	int centerX = (boundingRect.x + boundingRect.x + boundingRect.width) / 2;
	int centerY = (boundingRect.y + boundingRect.y + boundingRect.height) / 2;

	float area;

	bool validContour()
	{
		if (area < minCountourSize) return false;
		return true;
	}
	static bool sortBoundingRectx(const ContourData& left, const ContourData& right)
	{
		return(left.boundingRect.x < right.boundingRect.x);
	}
};
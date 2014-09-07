#include "Utilities.h"


Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

void Utilities::StartClock()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}


double Utilities::GetClock()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void Utilities::PrintToOutput(std::string output)
{
	std::wstring stemp = std::wstring(output.begin(), output.end());
	LPCWSTR sw = stemp.c_str();
	OutputDebugString(sw);
}


void Utilities::PrintFrameAvg(double milliseconds)
{
	static int i = 0;
	
	results.push_back(milliseconds);

	if (++i >= 500)
	{
		double sum = 0;
		for (int j = 0; j < results.size(); j++)
		{
			sum += results[j];
		}

		double avg = sum / (double)results.size();
		i = 0;
		results.clear();

		std::string str = "Avg last 500 frames: ";
		str += std::to_string(avg);
		str += "\n";
		PrintToOutput(str);
	}
}

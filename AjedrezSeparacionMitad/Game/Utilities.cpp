#include "Utilities.h"

int PromptInput(int min, int max)
{
	int response;
	do
	{
		cin >> response;
	} while (response < min || response > max);

	return response;
}
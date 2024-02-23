#include "Harl.hpp"

int main(void)
{
	Harl *harlone = new Harl;

	harlone->complain("debug");
	harlone->complain("info");
	harlone->complain("warning");
	harlone->complain("error");

	delete harlone;

	return 0;
}

#include "grcImage.h"
#include "XMem.h"
using namespace XMem;

grcImageFactory* grcImageFactory::GetGrcImageFactory()
{
	return *(grcImageFactory**)GetAddressFromRva(0x2ac0a28);
}

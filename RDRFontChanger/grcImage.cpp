#include "grcImage.h"
#include "XMem.h"
using namespace XMem;

grcTextureFactory* grcTextureFactory::GetInstance()
{
	return *(grcTextureFactory**)GetAddressFromRva(0x2ac0a28);
}

#include "Resource.h"


Resource::Resource()
	:initialized(false)
{

}

void Resource::swap(Resource& r1, Resource& r2)
{
	std::swap(r1.initialized, r2.initialized);
	std::swap(r2.directory, r1.directory);
}

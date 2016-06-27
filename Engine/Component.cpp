#include "Component.h"


namespace Tetra
{
	Component::Component(Object *object)
	{
		this->object = object;
	}


	Component::~Component()
	{
	}
}
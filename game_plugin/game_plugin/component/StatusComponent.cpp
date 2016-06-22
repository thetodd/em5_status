#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/component/StatusComponent.h"

#include <em5/command/component/CommandableComponent.h>

namespace flo11
{
	const uint32 StatusComponent::COMPONENT_ID = qsf::StringHash("flo11::StatusComponent");

	StatusComponent::StatusComponent(qsf::Prototype* prototype) :
		qsf::Component(prototype),
		mStatusId(2),
		mOldStatusId(2)
	{
		// Nothing to do in here
	}

	StatusComponent::~StatusComponent()
	{
		// Nothing to do in here
	}

	int StatusComponent::getStatus()
	{
		return mStatusId;
	}

	void StatusComponent::setStatus(int status)
	{
		if (status >= 1 && status <= 6) {
			mOldStatusId = this->getStatus();
			mStatusId = status;
		}
	}

	int StatusComponent::getOldStatus()
	{
		return this->mOldStatusId;
	}

}

// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/component/StatusComponent.h"

#include <qsf/map/Entity.h>
#include <qsf/component/base/TransformComponent.h>
#include <qsf/plugin/QsfJobs.h>
#include <qsf/job/JobArguments.h>
#include <qsf/debug/request/PolygonDebugDrawRequest.h>
#include <qsf/QsfHelper.h>
#include <qsf/log/LogSystem.h>

#include <em5/gui/EmergencyGui.h>
#include <em5/EM5Helper.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{


	//[-------------------------------------------------------]
	//[ Public definitions                                    ]
	//[-------------------------------------------------------]
	const uint32 StatusComponent::COMPONENT_ID = qsf::StringHash("flo11::StatusComponent");


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
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
			QSF_LOG_PRINTF(INFO, "Neuer Status %d", this->getStatus())
		}
	}


	//[-------------------------------------------------------]
	//[ Namespace                                             ]
	//[-------------------------------------------------------]
} // user

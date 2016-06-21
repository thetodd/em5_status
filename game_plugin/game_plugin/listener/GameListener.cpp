// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/listener/GameListener.h"
#include "game_plugin/component/StatusComponent.h"
#include "game_plugin/gui/FMSGui.h"

#include <em5/plugin/Messages.h>
#include <em5/EM5Helper.h>
#include <em5/game/Game.h>
#include <em5/game/selection/SelectionManager.h>

#include <qsf/job/JobArguments.h>
#include <qsf/message/MessageConfiguration.h>
#include <qsf/QsfHelper.h>
#include <qsf/map/Map.h>
#include <qsf/map/Entity.h>

#include <boost/bind.hpp>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	GameListener::GameListener()
	{
		// Nothing here
	}

	GameListener::~GameListener()
	{
		// Unregister the lifetime messages
		mChangeSelectionMessageProxy.unregister();
	}

	void GameListener::init()
	{
		// Register the message proxy to the life cycle messages. It is important to have the right time. Otherwise we would start our gamelogic in the main menu
		mChangeSelectionMessageProxy.registerAt(qsf::MessageConfiguration(em5::Messages::EM5_CHANGE_SELECTION), boost::bind(&GameListener::selectionChanged, this, _1));
	}


	//[-------------------------------------------------------]
	//[ Lifecycle                                             ]
	//[-------------------------------------------------------]
	void GameListener::selectionChanged(const qsf::MessageParameters& parameters)
	{
		QSF_LOG_PRINTS(INFO, "Selection changed...")
		//get selected Entity
		uint64 selectedEntityId = EM5_APPLICATION.getGame().getSelectionManager().getCurrentId();
		qsf::Entity* qsfEntity = QSF_MAINMAP.getEntityById(selectedEntityId);
		if (qsfEntity == nullptr) {
			FMSGui::instance->hide();
		}
		else {
			QSF_LOG_PRINTF(INFO, "Aktuelle Selection %s", qsfEntity->campClassName())
				flo11::StatusComponent* statusComponent = qsfEntity->getComponent<flo11::StatusComponent>();
			if (statusComponent != nullptr) {
				QSF_LOG_PRINTF(INFO, "Aktueller Status %d", statusComponent->getStatus())
				FMSGui::instance->show();
			}
			else {
				FMSGui::instance->hide();
			}
		}
	}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // user

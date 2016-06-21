// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/commands/ShowStatusCommand.h"
#include "game_plugin/component/StatusComponent.h"
#include "game_plugin/gui/FMSGui.h"

#include <em5/action/ActionPriority.h>
#include <em5/map/EntityHelper.h>
#include <em5/gui/EmergencyGui.h>
#include <em5/EM5Helper.h>

#include <qsf_game/command/CommandContext.h>
#include <qsf/localization/LocalizationSystem.h>
#include <qsf/QsfHelper.h>
#include <qsf/map/Map.h>
#include <qsf/log/LogSystem.h>

#include <string>
//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{


	//[-------------------------------------------------------]
	//[ Public definitions                                    ]
	//[-------------------------------------------------------]
	const uint32 ShowStatusCommand::PLUGINABLE_ID = qsf::StringHash("flo11::ShowStatusCommand");


	//[-------------------------------------------------------]
	//[ Private definitions                                   ]
	//[-------------------------------------------------------]
	const uint32 ShowStatusCommand::ACTION_PRIORITY = em5::action::COMMAND_STD;


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	ShowStatusCommand::ShowStatusCommand(qsf::game::CommandManager* commandManager) :
		em5::Command(commandManager, PLUGINABLE_ID)
	{
		mIconSettings.mTooltip = QT_TR_NOOP("ID_RedirectTraffic");
		mIconSettings.mShowAsGuiButton = true;
		mIconSettings.mButtonIconPath = "send_dog";
		mPriority=2;
	}


	//[-------------------------------------------------------]
	//[ Public virtual em5::Command methods                   ]
	//[-------------------------------------------------------]
	bool ShowStatusCommand::checkAvailable()
	{
		// Command is always available
		return true;
	}

	bool ShowStatusCommand::checkCaller(qsf::Entity& caller)
	{
		return true;
	}

	bool ShowStatusCommand::checkContext(const qsf::game::CommandContext& context)
	{
		return context.mCaller->getComponent<flo11::StatusComponent>() != nullptr;
	}

	void ShowStatusCommand::execute(const qsf::game::CommandContext& context)
	{
		//For easy debugging: execute action directly
		flo11::StatusComponent *status = context.mCaller->getComponent<flo11::StatusComponent>();

		if (status != nullptr) {
			FMSGui::instance->toggleVisibility();
		}
	}



//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // user

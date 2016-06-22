/// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/commands/MoveWithStatusCommand.h"
#include "game_plugin/component/StatusComponent.h"

#include <em5/gui/EmergencyGui.h>
#include <em5/application/Application.h>
#include <em5/game/Game.h>
#include <em5/game/selection/SelectionManager.h>
#include <em5/action/ActionPriority.h>
#include <em5/ai/MovementModes.h>
#include <em5/game/groundmap/GroundMaps.h>
#include <em5/EM5Helper.h>

#include <qsf/input/device/MouseDevice.h>
#include <qsf/input/device/KeyboardDevice.h>
#include <qsf/input/InputSystem.h>
#include <qsf/map/Map.h>
#include <qsf/QsfHelper.h>
#include <qsf/map/Map.h>
#include <qsf/map/query/RayMapQuery.h>
#include <qsf/map/query/GroundMapQuery.h>
#include <qsf/time/Time.h>

#include <qsf_ai/navigation/goal/ReachSinglePointGoal.h>
#include <qsf_game/command/CommandContext.h>
#include <qsf/logic/action/ActionComponent.h>

//test
#include <fstream>
//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{

	glm::vec3 OldMousePos2 = glm::vec3(0, 0, 0);

	//[-------------------------------------------------------]
	//[ Public definitions                                    ]
	//[-------------------------------------------------------]
	const uint32 MoveWithStatusCommand::PLUGINABLE_ID = qsf::StringHash("flo11::MoveWithStatusCommand");

	//[-------------------------------------------------------]
	//[ Private definitions                                   ]
	//[-------------------------------------------------------]
	const uint32 MoveWithStatusCommand::ACTION_PRIORITY = 200;

	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	MoveWithStatusCommand::MoveWithStatusCommand(qsf::game::CommandManager* commandManager) :
		em5::Command(commandManager, PLUGINABLE_ID)
	{
		origCommand = commandManager->getById<em5::Command>("em5::MoveCommand");
		mIconSettings = origCommand->getIconSettings();
		mPriority = origCommand->getPriority();
	}

	bool MoveWithStatusCommand::checkCallerWithoutPriority(qsf::Entity& caller)
	{
		// Check if unit state is valid
		return true;
	}


	//[-------------------------------------------------------]
	//[ Public virtual em5::Command methods                   ]
	//[-------------------------------------------------------]
	bool MoveWithStatusCommand::checkAvailable()
	{
		return origCommand->checkAvailable();
		// Command is always available

	}

	bool MoveWithStatusCommand::checkCaller(qsf::Entity& caller)
	{
		flo11::StatusComponent *statusComponent = caller.getComponent<flo11::StatusComponent>();

		if (statusComponent == nullptr) {
			return false;
		}
		else {
			if (statusComponent->getStatus() == 4 || statusComponent->getStatus() == 6) {
				return false;
			}
			if (statusComponent->getStatus() == 5) {
				if (statusComponent->getOldStatus() == 4 || statusComponent->getOldStatus() == 6) {
					return false;
				}
			}
		}

		return origCommand->checkCaller(caller);
	}

	bool MoveWithStatusCommand::checkContext(const qsf::game::CommandContext& context)
	{
		return origCommand->checkContext(context);
	}

	void MoveWithStatusCommand::execute(const qsf::game::CommandContext& context)
	{
		origCommand->execute(context);
	}

	glm::vec3 MoveWithStatusCommand::getPositionUnderMouse(qsf::Entity* caller)
	{
		glm::vec2 mousePosition = QSF_INPUT.getMouse().getPosition();

		// Check the first hit in the world...
		glm::vec3 worldPosition;
		qsf::RayMapQueryResponse response;
		qsf::RayMapQuery(caller->getMap()).getFirstHitByRenderWindow(*EM5_APPLICATION.getRenderWindow(), (int)mousePosition.x, (int)mousePosition.y, response);
		worldPosition = response.position;

		// and then take the ground position (to avoid jumping all the time)
		float groundHeight = 0.f;
		qsf::GroundMapQuery(QSF_MAINMAP, em5::GroundMaps::FILTER_DEFAULT).getHeightAt(worldPosition, groundHeight);

		worldPosition.y = groundHeight;
		return worldPosition;
	}

	/*void MoveWithStatusCommand::execute(const qsf::game::CommandContext& context)
	{
		qsf::ActionComponent& actionComponent = getActionComponent(*context.mCaller);
		actionComponent.clearPlan();

		actionComponent.pushAction<em5::MoveAction>(em5::action::COMMAND_STD, qsf::action::INSERT_AT_FRONT)
			.init(new qsf::ai::ReachSinglePointGoal(qsf::logic::TargetPoint(OldMousePos2, false, 0.0f, 1.0f)),
				em5::MovementModes::MOVEMENT_MODE_PLAYER_VEHICLE_ON_EMERGENCY_OPERATIONS);

	}*/


	//[-------------------------------------------------------]
	//[ Namespace                                             ]
	//[-------------------------------------------------------]
} // em5

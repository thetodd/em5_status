#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/commands/MoveWithStatusCommand.h"
#include "game_plugin/component/StatusComponent.h"

#include <qsf_game/command/CommandContext.h>
#include <qsf/logic/action/ActionComponent.h>

namespace flo11
{
	const uint32 MoveWithStatusCommand::PLUGINABLE_ID = qsf::StringHash("flo11::MoveWithStatusCommand");
	const uint32 MoveWithStatusCommand::ACTION_PRIORITY = 200;

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

}

#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/plugin/Plugin.h"
#include "game_plugin/component/StatusComponent.h"
#include "game_plugin/commands/MoveWithStatusCommand.h"

#include <em5/plugin/version/PluginVersion.h>
#include <em5/reflection/CampDefines.h>

#include <qsf_game/command/CommandManager.h>		// This is needed for commands; without this include, the build will work, but creation of commands fail
#include <qsf/map/Entity.h>							// Needed to avoid "error C2664: cannot convert argument 1 from 'qsf::Entity *' to 'qsf::Prototype *' (game_plugin\plugin\Plugin.cpp)"


namespace flo11
{

	Plugin::Plugin() :
		qsf::Plugin(new em5::PluginVersion())
	{
		QSF_LOG_PRINTS(INFO, "----Loading plugin status_component----");
		QSF_LOG_PRINTS(INFO, "    Built " __DATE__ ", " __TIME__);
	}

	bool Plugin::onInstall()
	{
		try
		{
			// Declare CAMP reflection system classes
			QSF_START_CAMP_CLASS_EXPORT(flo11::StatusComponent, "StatusComponent", "ID_USER_COMPONENT_INDICATOR_DESCRIPTION")
				QSF_CAMP_IS_COMPONENT
				QSF_ADD_CAMP_PROPERTY(Status, StatusComponent::getStatus, StatusComponent::setStatus, "The vehicles fms status", 2)
			QSF_END_CAMP_CLASS_EXPORT

			QSF_START_CAMP_CLASS_EXPORT(flo11::MoveWithStatusCommand, "MoveWithStatusCommand", "Moves a vehicle according to the vehicle status id.")
				QSF_GAME_CAMP_IS_COMMAND
			QSF_END_CAMP_CLASS_EXPORT

			// Done
			return true;
		}
		catch (const std::exception& e)
		{
			// Error!
			QSF_ERROR("Failed to install the plugin '" << getName() << "'. Exception caught: " << e.what(), QSF_REACT_NONE);
			return false;
		}
	}

	bool Plugin::onStartup()
	{
		mGuiManager = new GuiManager();
		mGuiManager->init();

		mGameListener = new GameListener();
		mGameListener->init();
		// Done
		return true;
	}

	void Plugin::onShutdown()
	{
		QSF_SAFE_DELETE(mGuiManager);
		QSF_SAFE_DELETE(mGameListener);
	}

	void Plugin::onUninstall()
	{
		// Removing classes is not possible within the CAMP reflection system

		// Nothing to do in here
	}
}

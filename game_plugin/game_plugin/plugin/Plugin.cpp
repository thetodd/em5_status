// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/plugin/Plugin.h"
#include "game_plugin/component/StatusComponent.h"

#include <qsf/log/LogSystem.h>
#include <em5/plugin/version/PluginVersion.h>
#include <em5/reflection/CampDefines.h>
#include <qsf/map/Entity.h>

//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	Plugin::Plugin() :
		qsf::Plugin(new em5::PluginVersion())
	{

		// Show version string
		//QSF_LOG_PRINT(INFO, "\n")
		QSF_LOG_PRINTS(INFO, "----Loading plugin status_component----")
		QSF_LOG_PRINTS(INFO, "    Built " __DATE__ ", " __TIME__)
	}


	//[-------------------------------------------------------]
	//[ Protected virtual qsf::Plugin methods                 ]
	//[-------------------------------------------------------]
	bool Plugin::onInstall()
	{
		try
		{
			// Declare CAMP reflection system classes

			QSF_START_CAMP_CLASS_EXPORT(flo11::StatusComponent, "StatusComponent", "ID_USER_COMPONENT_INDICATOR_DESCRIPTION")
				QSF_CAMP_IS_COMPONENT
				QSF_ADD_CAMP_PROPERTY(Status, StatusComponent::getStatus, StatusComponent::setStatus, "The vehicles fms status", 2)
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


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // user

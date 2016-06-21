#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/gui/GuiManager.h"
#include "game_plugin/gui/FMSGui.h"
#include <em5/gui/IngameHud.h>
#include <em5/gui/hud/BaseHudLayer.h>
#include <em5/gui/EmergencyGui.h>
#include <em5/EM5Helper.h>

//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{
    //[-------------------------------------------------------]
    //[ Public methods                                        ]
    //[-------------------------------------------------------]
    GuiManager::GuiManager():
        mContext(nullptr)
    {
    }

    GuiManager::~GuiManager()
    {
        mStartupMessageProxy.unregister();
        mShutdownMessageProxy.unregister();
    }

    void GuiManager::init()
    {
        mStartupMessageProxy.registerAt(qsf::MessageConfiguration(em5::Messages::GAME_STARTUP_FINISHED), boost::bind(&GuiManager::startup, this, _1));
        mShutdownMessageProxy.registerAt(qsf::MessageConfiguration(em5::Messages::GAME_SHUTDOWN_STARTING), boost::bind(&GuiManager::shutdown, this, _1));
    }

    void GuiManager::startup(const qsf::MessageParameters& parameters)
    {
        //actual guis
		mContext = &EM5_GUI.getIngameHud().getBaseHudLayer().getGuiContext();
		FMSGui::init(*mContext);
    }

    void GuiManager::shutdown(const qsf::MessageParameters& parameters)
    {
        //actual guis
		FMSGui::shutdown();
    }
}
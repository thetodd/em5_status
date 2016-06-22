#pragma once

#include <qsf/message/MessageProxy.h>
#include <qsf/gui/GuiContext.h>
#include <em5/plugin/Messages.h>
#include <em5/gui/EmergencyGui.h>

namespace flo11
{
    /**
    *   @brief
    *   This class starts up and shuts down all gui related things at game
    *   startup and shutdown.
	*
	*   @author Florian 11-47-1
    */
    class GuiManager
    {
    public:
        GuiManager();
        ~GuiManager();
        void init();

    private:
        void startup(const qsf::MessageParameters& parameters);
        void shutdown(const qsf::MessageParameters& parameters);

    private:
        qsf::MessageProxy		mStartupMessageProxy;
        qsf::MessageProxy		mShutdownMessageProxy;
        qsf::GuiContext*        mContext;
    };
}
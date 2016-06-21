#pragma once

#include <qsf/message/MessageProxy.h>
#include <qsf/gui/GuiContext.h>
#include <em5/plugin/Messages.h>
#include <em5/gui/EmergencyGui.h>

namespace flo11
{
    //[-------------------------------------------------------]
    //[ Classes                                               ]
    //[-------------------------------------------------------]
    /**
    *   @brief
    *   This class starts up and shuts down all gui related things at game
    *   startup and shutdown.
    */
    class GuiManager
    {


        //[-------------------------------------------------------]
        //[ Public definitions                                    ]
        //[-------------------------------------------------------]
    public:

        //[-------------------------------------------------------]
        //[ Public methods                                        ]
        //[-------------------------------------------------------]
    public:
        GuiManager();
        ~GuiManager();
        void init();
        //[-------------------------------------------------------]
        //[ Private methods                                       ]
        //[-------------------------------------------------------]
    private:

        void startup(const qsf::MessageParameters& parameters);
        void shutdown(const qsf::MessageParameters& parameters);
        //[-------------------------------------------------------]
        //[ Private data                                          ]
        //[-------------------------------------------------------]
    private:
        qsf::MessageProxy		mStartupMessageProxy;
        qsf::MessageProxy		mShutdownMessageProxy;
        qsf::GuiContext*        mContext;
    };
}
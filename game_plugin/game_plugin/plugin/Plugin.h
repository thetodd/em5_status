#pragma once

#include "game_plugin/gui/GuiManager.h"
#include "game_plugin/listener/GameListener.h"

#include <qsf/plugin/Plugin.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{
	/**
	*  @brief
	*    User-defined game plugin implementation
	*/
	class Plugin : public qsf::Plugin
	{

	#ifndef Q_OBJECT
		#define Q_OBJECT
		#define QSF_FAKE_Q_OBJECT
	#endif
	Q_OBJECT
	#ifdef QSF_FAKE_Q_OBJECT
		#undef Q_OBJECT
		#undef QSF_FAKE_Q_OBJECT
	#endif

	public:
		Plugin();
		inline virtual ~Plugin();

	public:
		inline virtual const char* getName() const override;
		inline virtual const char* getVendor() const override;
		inline virtual const char* getDescription() const override;

	protected:
		virtual bool onInstall() override;
		virtual bool onStartup() override;
		virtual void onShutdown() override;
		virtual void onUninstall() override;

	private:
		GuiManager* mGuiManager;
		GameListener* mGameListener;

	};

}

#include "game_plugin/plugin/Plugin-inl.h"

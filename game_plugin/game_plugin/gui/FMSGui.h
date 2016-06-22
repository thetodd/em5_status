#pragma once

#include <qsf/gui/GuiDocument.h>
#include <qsf/audio/AudioProxy.h>
#include <qsf/audio/AudioManager.h>

namespace flo11 {

	/**
	*  @brief
	*    The ingame hud GUI to set the status of a vehicle.
	*
	*  @remarks
	*    The RML source is in the folder "mod_files" and has to be copied to your mod.
	*
	*  @author Florian 11-47-1
	*/
	class FMSGui :
		public qsf::GuiDocument
	{
	public:
		static FMSGui* instance;

	public:
		FMSGui(qsf::GuiContext& guiContext);
		virtual ~FMSGui();
		static void init(qsf::GuiContext& guiContext);
		static void shutdown();
		virtual void processEvent(const std::string& eventKey, Rocket::Core::Event& event) override;

	private:
		char intToChar(int integer);
		void updateStatusId();

	};
	
}
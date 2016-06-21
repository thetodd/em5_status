#pragma once

#include <qsf/gui/GuiDocument.h>
#include <qsf/audio/AudioProxy.h>
#include <qsf/audio/AudioManager.h>

namespace flo11 {
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
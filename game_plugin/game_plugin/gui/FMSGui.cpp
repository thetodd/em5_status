#include "game_plugin/PrecompiledHeader.h"
#include "game_plugin/gui/FMSGui.h"
#include "game_plugin/component/StatusComponent.h"

#include <em5/gui/EmergencyGui.h>
#include <em5/EM5Helper.h>
#include <em5/application/Application.h>
#include <em5/game/Game.h>
#include <em5/logic/HintHelper.h>
#include <em5/game/selection/SelectionManager.h>

#include <qsf/log/LogSystem.h>
#include <qsf/QsfHelper.h>
#include <qsf/map/Map.h>
#include <qsf/map/Entity.h>

#include <Rocket/Core/Event.h>
#include <Rocket/Core/Element.h>
#include <Rocket/Core/Variant.h>
#include <Rocket/Core/ElementDocument.h>
#include <Rocket/Core/StringBase.h>

namespace flo11 {

	FMSGui* FMSGui::instance = nullptr;

	FMSGui::FMSGui(qsf::GuiContext& guiContext) :
		qsf::GuiDocument(guiContext)
	{
		loadByFilename("em5/gui/ingamehud/fms.rml");
	}


	FMSGui::~FMSGui()
	{
	}

	void FMSGui::init(qsf::GuiContext& guiContext)
	{
		QSF_ASSERT(instance == nullptr, "FmsGui: Instance already initialized", return);
		instance = new FMSGui(guiContext);
	}

	void FMSGui::shutdown()
	{
		QSF_SAFE_DELETE(instance);
	}

	void FMSGui::processEvent(const std::string& eventKey, Rocket::Core::Event& event)
	{
		if (eventKey == "changeStatus")
		{
			Rocket::Core::Element* btn = event.GetTargetElement();
			Rocket::Core::Variant* statusAttr = btn->GetAttribute("data-status");
			int status = 0;
			statusAttr->GetInto(status);

			uint64 selectedEntityId = EM5_APPLICATION.getGame().getSelectionManager().getCurrentId();
			qsf::Entity* qsfEntity = QSF_MAINMAP.getEntityById(selectedEntityId);

			flo11::StatusComponent *statusComponent = qsfEntity->getComponent<flo11::StatusComponent>();
			if (statusComponent != nullptr) {
				statusComponent->setStatus(status);

				qsf::AudioProxy().sourceFile("em5/audio/sfx_gui/fms_klack.ogg").absolute().channel(qsf::AudioManager::MIXERCHANNEL_GUI).play().detach();
				//Sleep(200);
				//qsf::AudioProxy().sourceFile("em5/audio/sfx_gui/fms_klack.ogg").absolute().channel(qsf::AudioManager::MIXERCHANNEL_GUI).play().detach();
				qsf::AudioProxy().sourceFile("em5/audio/sfx_gui/fms_quittung.ogg").absolute().channel(qsf::AudioManager::MIXERCHANNEL_GUI).volume(0.5f).play().detach();

				this->updateStatusId();
			}
		}
		else if (eventKey == "showfms") {
			this->updateStatusId();
		}
	}

	char FMSGui::intToChar(int integer)
	{
		return (char) integer + 48;
	}

	void FMSGui::updateStatusId()
	{
		uint64 selectedEntityId = EM5_APPLICATION.getGame().getSelectionManager().getCurrentId();
		qsf::Entity* qsfEntity = QSF_MAINMAP.getEntityById(selectedEntityId);
		flo11::StatusComponent *statusComponent = qsfEntity->getComponent<flo11::StatusComponent>();
		if (statusComponent != nullptr) {
			QSF_LOG_PRINTF(INFO, "Aktueller Status %d", statusComponent->getStatus())
				Rocket::Core::StringBase<char> statusText = "";
			statusText.Append(intToChar(statusComponent->getStatus()));
			this->getRocketCoreElementDocument()->GetElementById("statusId")->SetInnerRML(statusText);
		}
	}
}
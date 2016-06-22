#pragma once

#include "game_plugin/Export.h"

#include <qsf/component/Component.h>

namespace flo11
{
	/**
	*  @brief
	*    Status component
	*
	*  @remarks
	*    This component holds the vehicles status and is used in the new MoveCommand.
	*	 It can be used by other Plugins as well.
	*
	*  @author Florian 11-47-1
	*/
	class GAMEPLUGIN_API_EXPORT StatusComponent : public qsf::Component
	{

	public:
		static const uint32 COMPONENT_ID;

	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] prototype
		*    The prototype this component is in, no null pointer allowed
		*/
		StatusComponent(qsf::Prototype* prototype);
		~StatusComponent();

		int getStatus();
		void setStatus(int status);
		int getOldStatus();

	protected:

	private:
		int mStatusId;
		int mOldStatusId;

		QSF_CAMP_RTTI()	// Only adds the virtual method "campClassId()", nothing more


	};

}

QSF_CAMP_TYPE_NONCOPYABLE(flo11::StatusComponent)

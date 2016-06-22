#pragma once

#include <qsf/message/MessageProxy.h>

namespace flo11
{
	/**
	*  @remarks
	*    Listens to the em5 message "EM5_CHANGE_SELECTION" to display the FMSGui if needed.
	*/
	class GameListener
	{
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		GameListener();
		virtual ~GameListener();

		void init();

	private:
		void selectionChanged(const qsf::MessageParameters& parameters);
		
	private:
		qsf::MessageProxy mChangeSelectionMessageProxy;

	};

}

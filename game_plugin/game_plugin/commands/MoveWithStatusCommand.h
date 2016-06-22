#pragma once

#include "em5/command/Command.h"

namespace flo11
{
	/**
	*  @brief Let a vehicle move only on specific status ids.
	*  @author Florian 11-47-1
	*/
	class MoveWithStatusCommand : public em5::Command
	{

	public:
		static const uint32 PLUGINABLE_ID;

	public:
		/**
		*  @brief
		*    Constructor
		*/
		explicit MoveWithStatusCommand(qsf::game::CommandManager* commandManager);
		bool checkCallerWithoutPriority(qsf::Entity& caller);

	public:
		virtual bool checkAvailable() override;
		bool checkCaller(qsf::Entity& caller) override;
		virtual bool checkContext(const qsf::game::CommandContext& context) override;;
		virtual void execute(const qsf::game::CommandContext& context) override;

	protected:

	private:
		static const uint32 ACTION_PRIORITY;
		em5::Command* origCommand;

		QSF_CAMP_RTTI()


	};

}

QSF_CAMP_TYPE_NONCOPYABLE(flo11::MoveWithStatusCommand)

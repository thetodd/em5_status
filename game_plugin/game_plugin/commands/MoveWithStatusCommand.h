// Copyright (C) 2012-2015 Promotion Software GmbH


//[-------------------------------------------------------]
//[ Header guard                                          ]
//[-------------------------------------------------------]
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "em5/command/Command.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace flo11
{

	//[-------------------------------------------------------]
	//[ Classes                                               ]
	//[-------------------------------------------------------]
	/**
	*  @brief
	*    EMERGENCY 5 arrest gangster command
	*/
	class MoveWithStatusCommand : public em5::Command
	{


		//[-------------------------------------------------------]
		//[ Public definitions                                    ]
		//[-------------------------------------------------------]
	public:
		static const uint32 PLUGINABLE_ID;	///< "em5::ArrestGangsterCommand" unique command pluginable ID

											//[-------------------------------------------------------]
											//[ Public methods                                        ]
											//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*/
		explicit MoveWithStatusCommand(qsf::game::CommandManager* commandManager);

		bool checkCallerWithoutPriority(qsf::Entity& caller);


		//[-------------------------------------------------------]
		//[ Public virtual em5::Command methods                   ]
		//[-------------------------------------------------------]
	public:
		virtual bool checkAvailable() override;
		bool checkCaller(qsf::Entity& caller) override;
		virtual bool checkContext(const qsf::game::CommandContext& context) override;;
		virtual void execute(const qsf::game::CommandContext& context) override;
		glm::vec3 getPositionUnderMouse(qsf::Entity* caller);



	public:

	protected:
		//[-------------------------------------------------------]
		//[ Private definitions                                   ]
		//[-------------------------------------------------------]
	private:
		static const uint32 ACTION_PRIORITY;
	private:
		qsf::Map*	mMap;
		glm::vec3 OldMousePos;
		em5::Command* origCommand;

		//[-------------------------------------------------------]
		//[ CAMP reflection system                                ]
		//[-------------------------------------------------------]
		QSF_CAMP_RTTI()	// Only adds the virtual method "campClassId()", nothing more


	};


	//[-------------------------------------------------------]
	//[ Namespace                                             ]
	//[-------------------------------------------------------]
} // em5


  //[-------------------------------------------------------]
  //[ CAMP reflection system                                ]
  //[-------------------------------------------------------]
QSF_CAMP_TYPE_NONCOPYABLE(flo11::MoveWithStatusCommand)

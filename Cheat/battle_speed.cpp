#include "battle_speed.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"



namespace BattleSpeed
{
	int iCurrenTurnEntityTeam = 0;

	static void* GetCurrenTurnActionEntityHandler(void* _this)
	{
		PVOID lpResult = CALL_ORIGIN(GetCurrenTurnActionEntityHandler, _this);

		if (lpResult)
		{
			iCurrenTurnEntityTeam = RPG::GameCore::GameEntity::get_Team(lpResult);
		}

		return lpResult;
	}

	static void set_speedHandler(void* _this, float value)
	{
		FLOAT flValue = value;

		if (Options.bBattleSpeed)
		{
			__try
			{
				switch (Engine::GetPhaseType())
				{
				case RPG::Client::GamePhaseType_BattleLineup:
				case RPG::Client::GamePhaseType_QABattleLineup:
				case RPG::Client::GamePhaseType_Battle:
				case RPG::Client::GamePhaseType_BattleNew:
					if (iCurrenTurnEntityTeam == RPG::GameCore::TeamType_TeamDark)
						flValue = Options.flBattleSpeed;
					break;
				default:
					break;
				}
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("BattleSpeed::set_speedHandler(), exception 0x%X\n", GetExceptionCode());

				flValue = value;
			}
		}

		return CALL_ORIGIN(set_speedHandler, _this, flValue);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Battle Speed");

		ImGui::Checkbox("Enable", &Options.bBattleSpeed);

		if (Options.bBattleSpeed)
		{
			ImGui::Indent();

			ImGui::SliderFloat("Value", &Options.flBattleSpeed, 0.1f, 1000.f, "%.1f");

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(UnityEngine::Animator::set_speed, set_speedHandler);
		CreateHook(RPG::GameCore::TurnBasedGameMode::GetCurrenTurnActionEntity, GetCurrenTurnActionEntityHandler);
	}
}
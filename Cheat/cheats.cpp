#include "cheats.h"

#include "unload.h"
#include "config.h"
#include "fps.h"
#include "skip_cutscene.h"
#include "open_menu.h"
#include "chest_teleport.h"
#include "quest_teleport.h"
#include "auto_talk.h"
#include "battle_speed.h"
#include "force_autobattle.h"
#include "dump_enemies.h"
#include "esp.h"
#include "fov.h"
#include "noclip.h"
#include "peeking.h"

#include "engine.h"

namespace Cheats
{
	VOID RenderPlayerTab()
	{
		Noclip::Render();
	}

	VOID RenderBattleTab()
	{
		ForceAutoBattle::Render();
		BattleSpeed::Render();
	}

	VOID RenderWorldTab()
	{
		SkipCutscene::Render();
		ChestTeleport::Render();
		QuestTeleport::Render();
		AutoTalk::Render();
		DumpEnemies::Render();
	}

	VOID RenderVisualsTab()
	{
		Esp::Render();
		Fov::Render();
		Peeking::Render();
	}

	VOID RenderMiscTab()
	{
		Unload::Render();
		Config::Render();
		Fps::Render();
		OpenMenu::Render();
	}

	VOID Update()
	{
		Unload::Update();
		Config::Update();
		Fps::Update();
		SkipCutscene::Update();
		OpenMenu::Update();
		ChestTeleport::Update();
		QuestTeleport::Update();
		AutoTalk::Update();
		ForceAutoBattle::Update();
		BattleSpeed::Update();
		DumpEnemies::Update();
		Esp::Update();
		Fov::Update();
		Noclip::Update();
		Peeking::Update();
	}

	VOID Start()
	{
		Unload::Start();
		Config::Start();
		Fps::Start();
		SkipCutscene::Start();
		OpenMenu::Start();
		ChestTeleport::Start();
		QuestTeleport::Start();
		AutoTalk::Start();
		ForceAutoBattle::Start();
		BattleSpeed::Start();
		DumpEnemies::Start();
		Esp::Start();
		Fov::Start();
		Noclip::Start();
		Peeking::Start();
	}
}
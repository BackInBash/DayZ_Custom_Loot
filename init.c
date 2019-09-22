void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",100);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		TStringArray tops = {"M65Jacket_Black","M65Jacket_Khaki","M65Jacket_Tan","M65Jacket_Olive","TTsKOJacket_Camo","GorkaEJacket_Summer","GorkaEJacket_Flat","GorkaEJacket_Autumn","GorkaEJacket_PautRev"};
		TStringArray pants = {"BDUPants","TTSKOPants"};
        TStringArray shoes = {"MilitaryBoots_Redpunk","MilitaryBoots_Black"};
		TStringArray backpack = {"AliceBag_Camo"};
        TStringArray vest = {"HighCapacityVest_Olive","HighCapacityVest_Black"};
        TStringArray tool = {"OrienteeringCompass","Knife","PurificationTablets","Matchbox"};
        TStringArray medic = {"BandageDressing"};
        TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
        TStringArray food = {"Apple","PowderedMilk","PeachesCan","Pear"};

		player.RemoveAllItems(); 
		
		EntityAI itemEnt;
        EntityAI itemIn;
        ItemBase itemBs;
		
		//Hat
		ItemBase.Cast(player.GetInventory().CreateInInventory("BallisticHelmet_Green"));
		// Jacket
		ItemBase.Cast(player.GetInventory().CreateInInventory(tops.GetRandomElement()));
		// Pants
		ItemBase.Cast(player.GetInventory().CreateInInventory(pants.GetRandomElement()));
        // Shoes
        ItemBase.Cast(player.GetInventory().CreateInInventory(shoes.GetRandomElement()));
        // Backpack
        ItemBase.Cast(player.GetInventory().CreateInInventory(backpack.GetRandomElement()));
		// Vest
		ItemBase.Cast(player.GetInventory().CreateInInventory(vest.GetRandomElement()));
        // tool
        ItemBase.Cast(player.GetInventory().CreateInInventory(tool.GetRandomElement()));	
        ItemBase.Cast(player.GetInventory().CreateInInventory("CombatKnife"));
		ItemBase.Cast(player.GetInventory().CreateInInventory("Battery9V"));
		ItemBase.Cast(player.GetInventory().CreateInInventory("Battery9V"));
		ItemBase.Cast(player.GetInventory().CreateInInventory("Compass"));
		// Medical
        ItemBase.Cast(player.GetInventory().CreateInInventory(medic.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(medic.GetRandomElement()));
		// Drink
        ItemBase.Cast(player.GetInventory().CreateInInventory(drink.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(drink.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(drink.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(drink.GetRandomElement()));
		// Food
        ItemBase.Cast(player.GetInventory().CreateInInventory(food.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(food.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(food.GetRandomElement()));
		ItemBase.Cast(player.GetInventory().CreateInInventory(food.GetRandomElement()));
		
		//Random guns
		switch (Math.RandomInt(0, 3)) {
			
			case 0:
			// Sniper
				// Weapon + Scope
				EntityAI gun3 = player.GetHumanInventory().CreateInHands("SVD");
				gun3.GetInventory().CreateAttachment("PSO1Optic");
				gun3.GetInventory().CreateAttachment("AK_Suppressor");
				
				// Second Scope
				EntityAI at1 = player.GetInventory().CreateInInventory("KazuarOptic");
				at1.GetInventory().CreateAttachment("Battery9V");
				
				// Mags
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_SVD_10Rnd"));
				
				// Amo
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x54_20Rnd"));
			
				// Weapon + Scope
				EntityAI gun4 = player.GetInventory().CreateInInventory("AKM");
				gun4.GetInventory().CreateAttachment("AK_PlasticBttstck_Black");
				gun4.GetInventory().CreateAttachment("AK_RailHndgrd_Black");
				gun4.GetInventory().CreateAttachment("UniversalLight");
				gun4.GetInventory().CreateAttachment("AK_Suppressor");
				
				// Second Scope
				EntityAI at2 = player.GetInventory().CreateInInventory("KobraOptic");
				at2.GetInventory().CreateAttachment("Battery9V");
				
				// Mags
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AKM_30Rnd"));
				
				// Amo
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd"));
				
			
			break;
		
			case 1:
			// Rifle
				// Weapon + Attatchments
				EntityAI gun1 = player.GetHumanInventory().CreateInHands("M4A1_Black");
				gun1.GetInventory().CreateAttachment("M68Optic");
				gun1.GetInventory().CreateAttachment("M4_MPBttstck_Black");
				gun1.GetInventory().CreateAttachment("M4_PlasticHndgrd_Black");
				gun1.GetInventory().CreateAttachment("M4_Suppressor");
				gun1.GetInventory().CreateAttachment("UniversalLight");
				
				// Mags
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd"));
				
				// Amo
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd"));
				
				// Weapon
				EntityAI gun5 = player.GetInventory().CreateInInventory("AK101_Black");
				gun5.GetInventory().CreateAttachment("KobraOptic");
				gun5.GetInventory().CreateAttachment("AK_PlasticBttstck_Black");
				gun5.GetInventory().CreateAttachment("AK_RailHndgrd_Black");
				gun5.GetInventory().CreateAttachment("UniversalLight");
				gun5.GetInventory().CreateAttachment("AK_Suppressor");
				
				// Mags
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK101_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK101_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK101_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK101_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK101_30Rnd_Black"));
								
			break;
		
			case 3:
			// Rifle 1

				// Weapon + Attatchments
				EntityAI gun2 = player.GetHumanInventory().CreateInHands("AK74_Black");
				gun2.GetInventory().CreateAttachment("KobraOptic");
				gun2.GetInventory().CreateAttachment("AK_PlasticBttstck_Black");
				gun2.GetInventory().CreateAttachment("AK_RailHndgrd_Black");
				gun2.GetInventory().CreateAttachment("UniversalLight");
				gun2.GetInventory().CreateAttachment("AK_Suppressor");
				
				// Mags
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("Mag_AK74_30Rnd_Black"));
				
				// Amo
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				ItemBase.Cast(player.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd"));
				
				// Weapon
				EntityAI gun6 = player.GetInventory().CreateInInventory("AKS74U_Black");
				//gun6.GetInventory().CreateAttachment("AK_PlasticBttstck_Black");
				gun6.GetInventory().CreateAttachment("AK_Suppressor");
				
				
			break;
		}
		
		EntityAI strap = player.GetInventory().CreateInInventory("NVGHeadstrap");
		strap.GetInventory().CreateAttachment("NVGoggles");
		
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
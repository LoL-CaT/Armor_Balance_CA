{"generic"
	{on bullet_hit
		{if not under_water
			{if stuff "napalm"
				;do nothing
;flesh
			else material "flesh"
				{if stuff "zenite"
					{spawn "bloodsparks_big"}
				else stuff "mortar"
					{spawn "ex_air_big"}
				else stuff "shell fg"
					{spawn "bloodsparks_big"}
				else stuff "shell ap atgm"
					{spawn "bloodsparks_big"}
				else stuff "shell"
					{spawn "bloodsparks_big"}
				else stuff "rocketlauncher"
					{spawn "bloodsparks_big"}
				}
;steel
			else material "steel"
				{if stuff "bullet"
					{spawn "metal_hit_bul"}
				else stuff "mortar"
					{spawn "metal_hit_br"}
				else stuff "zenite"
					{spawn "metal_hit_bul"}
					{spawn "ex_bul_zenit"}
				else stuff "fg grenade"
					{spawn "metal_hit_br"}
				else stuff "shell fg small"
					{spawn "metal_hit_fg"}
				else stuff "shell small"
					{spawn "metal_hit_br_small"}
				else stuff "shell fg"
					{spawn "metal_hit_fg"}
				else stuff "shell ap atgm"
					{spawn "ex_fg_medium"}
				else stuff "shell"
					{spawn "metal_hit_br"}
				else
				 	{spawn "metal_hit_bul"}
				}
;wood
			else material "wood"
				{if stuff "bullet"
					{spawn "wood_hit_bul"}
				else stuff "mortar"
					{spawn "wood_hit_fg"}
				else stuff "zenite fg"
					{spawn "wood_hit_bul"}
					{spawn "ex_bul_zenit"}
				else stuff "zenite"
					{spawn "wood_hit_bul"}
					{spawn "spheredust_norm"}
				else stuff "fg grenade"
					{spawn "wood_hit_bul"}
					{spawn "ex_bul_zenit"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "shell ap atgm"
					{spawn "ex_fg_medium"}
				else stuff "shell small"
					{spawn "wood_hit_br_small"}
				else stuff "shell"
					{spawn "wood_hit_br"}
				else
					{spawn "wood_hit_br"}
				}
;concrete
			else material "concrete"
				{if stuff "bullet"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "zenite"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "fg grenade"
					{spawn "ex_fg_medium"}
				else stuff "big shell fg"
				 	{spawn	"stone_hit_br_big"}
				else stuff "shell ap atgm"
					{spawn "ex_fg_medium"}
				else stuff "shell small"
				 	{spawn	"stone_hit_br_small"}
				else
				 	{spawn	"stone_hit_br"}
				}
;sand
			else material "sand"
				{if stuff "zenite"
					{spawn "ex_air_sm"}
					{spawn "sandbags_hit_big_50"}
				else stuff "small bullet"
					{if rand 0.5
						{spawn "sandbags_hit_small1"}
					else
						{spawn "sandbags_hit_small2"}
					}
				else stuff "big bullet"
					{spawn "sandbags_hit_big_50"}
				else stuff "bullet"
					{if rand 0.5
						{spawn "sandbags_hit_big1"}
					else
						{spawn "sandbags_hit_big1"}
					}
				else stuff "mortar"
					{spawn "ex_mort_sm"}
				else stuff "fg grenade"
					{spawn "ex_mort_sm"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "shell ap atgm"
					{spawn "ex_fg_medium"}
				else stuff "rocketlauncher"
					{spawn "ex_air_big"}
				else
					{spawn "sandbags_crush"}
				}
;ice
			else material "ice"
				{if stuff "shell fg"
					{spawn "ex_mort_sm_snow"}
				else
					{spawn "snow_hit_small"}
				}
;misc			
			else material "misc"
				{if stuff "bullet"
					{spawn "spheredust_small_short"}
				else stuff "mortar"
					{spawn "spheredust_norm"}
					{spawn "ex_fg_medium"}
				else stuff "zenite"
					{spawn "ex_bul_zenit"}
				else stuff "fg grenade"
					{spawn "ex_bul_zenit"}
				else stuff "shell fg"
					{spawn "spheredust_norm"}
					{spawn "ex_fg_medium"}
				else stuff "shell ap atgm"
					{spawn "spheredust_norm"}
					{spawn "ex_fg_medium"}
				else
					{spawn "spheredust_norm"}
				}
			}
		}
	}
}

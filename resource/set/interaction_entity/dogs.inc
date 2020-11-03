{"evil_animal"
	{on spawn
		{call "idle"}
	}
	{on move on
		{call "stop_idle"}
		{if not "blocked"
			{ani_play "run" 2.5 loop}
		}
	}
	{on move off
		{ani_stop "run"}
		{call "idle"}
	}
	{on turn on
		{call "stop_idle"}
		{if not "blocked"
			{ani_play "walk" 1.0 loop}
		}
	}
	{on turn off
		{ani_stop "walk"}
		{call "idle"}
	}
	{on "idle"
		{set "idle" 1}
		{if not "blocked"
			{if rand 0.5
				{ani_play "passive" 0.5 callback}
			 else
				{ani_play "passive2" 0.5 callback}
			}
		}
	}
	{on "safe-idle"
		{if "idle"
			{call "idle"}
		}
	}
	{on "start-idle"
		{set "idle" 1}
		{delay_effect 1 "safe-idle"}
	}
	{on animation_end "passive"
		{delay_effect 4 1.5 "safe-idle"}
	}
	{on animation_end "passive2"
		{delay_effect 4 1.5 "safe-idle"}
	}
	{on "stop_idle"
		{set "idle" 0}
		{ani_stop "passive"}
		{ani_stop "passive2"}
	}
	{on blast
		{call "damage"}
	}
	{on fire "gun"
	;	{set "blocked" 1}
	;	{call "stop_idle"}
	;	{ani_stop "walk"}
	;	{ani_stop "run"}
	;	{ani_play "attack" callback}
	}
	{on animation_end "attack"
		{set "blocked" 0}
		{call "start-idle"}
	}
	{on ik begin "foresight3"
		{call "stop_idle"}
	}
	{on bullet_hit
		{health_damage_pierce
			{effects "" "damage-low" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on "damage-low"
		{spawn "bloodsparks_small"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{call "stop_idle"}
		{ani_stop "walk"}
		{ani_stop "attack"}
		{ani_stop "run"}
		{set "blocked" 1}
		{ani_play "death"}
		{die}
	}
}

{"dog"
	{on "damage"
		{start_sound "animal/dog/die"}	
	}
}
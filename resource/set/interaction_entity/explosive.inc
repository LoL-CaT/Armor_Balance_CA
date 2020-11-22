{"mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		{add_view "mined_view_own"		"mined_own"		"mined_view"}
		{add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		{add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on "_explosion"
		{volumes "body1" disable blast}
		{volumes "body" disable blast}
		{stuff_detonate}
	}
	{on "explosion"
		{if mined
			{call "_explosion"}
		}
	}
	{on "change_state"
		{if mined
			{tags add "mine_planted"}
			{bone hide "folded"}
			{bone show "unfolded"}
			{volumes "body1" disable all}
			{volumes "body1" enable bullet}
			{volumes "body" enable contact contact_ground blast}
		else
			{tags remove "mine_planted"}
			{bone show "folded"}
			{bone hide "unfolded"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast bullet}
		}
	}
}

{"kamikaze_bomb"
	{on blast_hit
		{if min_energy 0.1
			{stuff_detonate}
		}	
	}
}

{"mine_antipersonnel"
	{on contact
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		}
	}
	{on blast_hit
		{if min_energy 0.1
			{if not stuff "mine"
				{stuff_detonate}
			}
		}	
	}
}

{"mine_antitank"
	{on blast_hit
		{if min_energy 0.1
			{if not stuff "mine"
				{stuff_detonate}
			}
		}				
	}
	{on contact
		{if mine_effector "mine_exploder"
			{delay 0
				{call "explosion"}
			}
		else mine_effector "vehicle"
			{if mined
				{volumes disable contact}
				{delay 0.1
					{call "explosion"}
				}
			}
		}
	}
}

{"claymore"
	{on contact
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		}
	}
	{on blast_hit
		{if min_energy 1.5
			{if not stuff "mine"
				{stuff_detonate}
			}
		}
	}
	{on bullet_hit
		{if rand 0.75
			{if not stuff "mine"
				{stuff_detonate}
			}
		}
	}
}

{"dynamite"
	{on "undermine"
		{tags add "fuse dynamite_planted"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
	}
	{on "onThrow"
		{if stuff_activated
			{tags add "fuse"}
			{add_view "flash_fuse_small" "fire" "fire"}
			{view start "fire"}
			{ani_play "fire" 0.06}
			{volumes disable touch select}
		}
	}
	{on blast
		{if min_energy 0.25
			{stuff_detonate}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
}

{"c4"
	{on "undermine"
		{tags add "c4_planted"}
	}
	{on "onThrow"
		{tags add "c4_planted"}
	}
}

{"air_bomb"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{ani_play "start"}
		{delay 0.5
			{volumes enable contact}
		}
	}
	{on ground_hit
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"air_bomb_stuff"
	{on "explosion"
		{stuff_detonate}
	}
	{on break_armor
		{call "explosion"}
	}
	{on contact
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"artillery_explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{delay 0
			{start_sound "weapon/shot/artillery"}
			{delay 2
				{call "explosion"}
			}
		}
	}
}

{"artillery_explosion_flaer"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{spawn "smoke_red_small"}
		{spawn "smoke_red_norm"}
		{delay 10
			{delay 2
				;{set_radius 20
				{call "explosion"}
			}
			{start_sound "mission/artillery/"}
			{start_sound "weapon/shot/artillery"}
		}
	}
}

{"explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{call "explosion"}
	}
}


{"explosive_barrel"
	{inflammation_time 3}
	{on spawn
		{set "exploded" 0}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "fuel" 20
				{call "explosion"}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
		else name "blast"
			{call "break"}
		}
	}
	{on contact
;		{if effector "vehicle"
;			{if effector_velocity 5
;				{call "break"}
;			}
;		}
	}
	{on "burn"
		{call "break"}
	}
	{on "break"
		{if stuff_filled "fuel" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{blastwave c4 5 r0 2 r1 4}
			{spawn "barrel_die" offset 0 0 7}
			;{add_view "smoke_barrel" "smoke" "root"}
			{delete}
			{spawn "fire_mark_1"}
		}
	}
	{on ground_hit
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"balloon"
	{on break_armor
		{if name "pierce"
			{if rand 0.2
				{bullet_detonate}
				{if stuff_filled "fuel" 5
					{call "explosion"}
				}
			}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{spawn "flamer_die"}
			{spawn "fire_molot_ground"}
			{blastwave c4 10 r0 1 r1 1.5}
			{fire radius 6 time 2 heating 6}
			{delete}
		}
	}
}

{"explosive_stuff"
	{inflammation_time 7}
	{on break_armor
		{call "explosion"}
	}
	{on "burn"
		{call "explosion"}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}

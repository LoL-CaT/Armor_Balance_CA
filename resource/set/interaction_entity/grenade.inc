{"grenade"
	{on spawn
		{add_view "marker_grenade_normal" "marker1" "root" not_manual not_scenario}
		{add_view "marker_grenade_acute" "marker2" "root" not_manual not_scenario}
		{add_view "marker_grenade_normal_dc" "marker3" "root" in_manual in_zoom}
		{add_view "marker_grenade_acute_dc" "marker4" "root" in_manual in_zoom}
	}
	{on "onThrow"
		{volumes "body" disable contact}
	}
	{on "onThrowActivate"
		{volumes "body" enable contact}
	}
	{on contact
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
;		{call "hide_marker"}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}

	{on "show_marker1"
		{view start "marker1"}
		{view start "marker3"}
	}
	{on "show_marker2"
		{view pause "marker1"}
		{view start "marker2"}
		{view pause "marker3"}
		{view start "marker4"}
	}
	{on "hide_marker"
		{view stop "marker1"}
		{view stop "marker2"}
		{view stop "marker3"}
		{view stop "marker4"}
	}
}

{"grenade fg"
	{on "onThrow"
		{delay 1.5
			{call "show_marker1"}
		}
		{delay 3.5
			{call "show_marker2"}
		}
	}
}

{"grenade dynamite"
	{on "undermine"
		{delay 7
			{call "show_marker1"}
		}
		{delay 9
			{call "show_marker2"}
		}
	}
	{on "onThrow"
		{call "undermine"}
	}
}

{"grenade training"
	{on spawn
		{tags add "grenade"}
	}
}

{"grenade contact"
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact
		{if stuff_activated
			{call "contact_detonate"}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate}
	}
	{on "fall_down" overload}
	{on blast
		{if min_energy 0.5
			{call "detonate"}
		}
	}
}

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/grenade_smoke"}
	}
	{on "add_smoke"
;		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		{play_sound "smoke" 1}
		{tags add "smoke"}
;		{call "hide_marker"}
;		{view stop "smoke1"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 3
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 5
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 60
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 62
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}

{"inc_grenade"
	
	{on spawn
		
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "activate"
		
		{delay 0.001
		        {hide 1}
            		{spawn "grenade_incendiary_explosion"}
			
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}

{"smoke_66mm"
	{on spawn
		{add_view 	"dust_shot_big"			"smoke_init" "root"}
		{add_view 	"smoke_cover-up_big"	"smoke_long" "root"}
		{link_sound "smoke_sound"			"detonation/grenade_smoke/grenade_smoke"}
		{link_sound "smoke_detonation"		"weapon/shot/gun/smoke/"}		
	}
	{on "activate"
		{volumes disable touch select}
		{play_sound "smoke_detonation"}
		{play_sound "smoke_sound" 1}
		{tags add 	"smoke"}
		{view start "smoke_init"}
		{view start "smoke_long"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 60
			{view stop "smoke_long"}
			{stop_sound "smoke_sound"}
		}
		{delay 62
			{hide 1}
		}
	}
}

{"smoke_shell"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/grenade_smoke"}
		{call "activate"}		
	}
	{on "add_smoke"
;		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}	
	{on "activate"
		{volumes disable touch select}
		{play_sound "smoke" 1}
		{tags add "smoke"}
;		{view stop "smoke1"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 3
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 5
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 120
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 122
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke mortar_smoke"
	{on spawn
		{volumes disable touch select}
		{call "activate"}
	}
}

{"molotov_coctail"
	{on bullet_hit
		{fire radius 1.5 time 2 heating 6 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 1.5 time 2 heating 6 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 2 time 5}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 1.5 time 2 heating 6 effector}
			{delay 0.1
				{call "detonate"}
			}
		else
		;	{fire radius 1.5 time 2 heating 20 effector follow}
			{fire radius 0.7 time 0.7 heating 30 effector}
			{call "detonate"}
		}
	}
}

{"grenade_m24flaml"
	{on bullet_hit
		{fire radius 1.5 time 2 heating 6 effector}
		{call "detonate"}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 1.5 time 2 heating 6 effector}
			{call "detonate"}
		}
	}
	{on "ground_detonate"
		{fire radius 2 time 5}
	}
	{on "contact_detonate" overload
		{if effector "construction"
			{volumes disable bullet contact blast}
			{fire radius 1.5 time 2 heating 6 effector}
			{delay 0.1
				{call "detonate"}
			}
		else
		;	{fire radius 1.5 time 2 heating 20 effector follow}
			{fire radius 0.7 time 0.7 heating 30 effector}
			{call "detonate"}
		}
	}
}

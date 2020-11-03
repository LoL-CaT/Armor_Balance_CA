{"animal"
	{on blast
		{health_damage_blast
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on blow opponent
		{health_damage_blow
			{effects "hit" "hit" "die" "die" "explosion" "explosion" "explosion"}
		}
		{call "damage"}
	}
	{on bullet_hit
		{call "pierce_damage"}
	}
	{on "pierce_damage"
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on contact 
		{if effector "vehicle"
			{if effector_velocity 0.1
				{health_damage_crush "die" "explosion"}
			}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count 180 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count 60 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count 40 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count 20 {effects "" "hit" "damage" "die" "die"}}
			}
		}
	}
	{on "die"
		{volumes disable contact}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
	}
	{on "explosion"
		{delete}
	}
	{on "idle"
		{if name "enter"
			{call "idle_try"}
		else name "exit"
			{ani_stop "passive"}
			{ani_stop "eat"}
			{kill_delay "idle_try"}
			{kill_delay "idle_noanm"}
		}
	}
	{on "idle_try"
		{delay 0.2 0.1 "idle_try"
			{if rand 0.4
				{ani_play "eat" callback}
			else rand 0.4
				{ani_play "passive" callback}
			else
				{delay 5 3 "idle_noanm"
					{call "idle_try"}
				}
			}
		}
	}
	{on animation_end "passive"
		{call "idle_try"}
	}
	{on animation_end "eat"
		{call "idle_try"}
	}
}

{"chicken"
	{on "damage"
		{spawn "pero_hit_small"}
		{start_sound "animal/chicken/cluck"}
	}
	{on "die"
		{call "explosion"}
	}
	{on "explosion"
		{start_sound "animal/chicken/die"}
		{spawn "pero_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/chicken/cluck"}
		}
	}
	{on ground_hit
		{call "feather"}
	}
	{on contact
		{if velocity 4
			{call "feather"}
		}
	}
	{on "feather"
		{if not "feather"
			{set "feather" 1}
			{spawn "pero_hit_small"}
			{start_sound "animal/chicken/cluck"}
			{delay 0.2
				{set "feather" 0}
			}
		}
	}
}

(define "imp"
	{spawn %0 %1
		{impulse	up 1 0.5 dir 8 4
					cx 0 12 cy 0 12
					fx 0 60 fy 0 60 fz 80 40
		}
	}
)

{"dog"
	{on spawn
		{add_view	"drops_water_small3"	"on_water"	"leg1"}
		{add_view	"drops_water_small3"	"on_water"	"leg2"}
		{add_view	"drops_water_small3"	"on_water"	"leg3"}
		{add_view	"drops_water_small3"	"on_water"	"leg4"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "animal/dog/aw"}
		}
	}
	{on "die"
		{start_sound "animal/dog/die"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/dog/die"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/dog/aw"}
		}
	}

	(define "terrain_fx_dog"
		{on terrain_fx %0 enter
			{view start "on_%1"}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_dog" args "shallow_water" 	water)
	("terrain_fx_dog" args "puddle"			water)
}

{"rabbit"
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"cow"
	{on "pierce_damage" overload
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion"}
		}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
	}
	{on "die"
		{start_sound "animal/cow/moo"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/cow/moo"}
		}
	}
}

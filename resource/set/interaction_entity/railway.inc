{"railway"
	{on pierce sync
		{vehicle_health_damage_pierce}
		{## if stuff "atgm"
			{call "blast_body"}
		}
		{## if stuff "rocketlauncher"
			{call "blast_body"}
		}
		{## if stuff "ammo grenade fg"
			{call "blast_body"}
		}
	}

	{## on break_armor
		{if name "blast"
			{call "blast_body"}
		}
	}

	{## on "blast_body"
		{if min_energy 40
			{impulse up 1.5 0.5 dir 1.5 0.5}
		else min_energy 25
			{impulse up 0.8 0.3 dir 0.8 0.3}
		}
		{call "explosion"}
	}
}

{"railway_switch"
	{on "switch"
		{rail_switch -1}
	}
	{on "switchr"
		{rail_switch 0}
	}
	{on "switchl"
		{rail_switch 1}
	}
	{on "switch_left"
		{volumes "body" disable touch}
		{volumes "body1" enable touch}
		{tags add "switch_left"}
		{tags remove "switch_right"}
	}
	{on "switch_right"
		{volumes "body" enable touch}
		{volumes "body1" disable touch}
		{tags add "switch_right"}
		{tags remove "switch_left"}
	}
}

{"railway_part"
	{on "break"
		{tags add "broken"}
		{rail_break}
	}
	{## on break_armor
		{call "break"}
	}
}


{"train_part"
	;{on "add_movement_sound"
	;	{link_sound "accelerating" "vehicle/wheels/train_end"}
	;	{link_sound "moving" "world/railway"}
	;	{link_sound "braking" "vehicle/wheels/train_end"}
	;}
	{on accelerate on
		{play_sound "accelerating"}
		{delay 1
			{view pause "warm_smoke"}
		}
		{view start "accelerate_smoke"}
		{view start "accelerate_steam"}
		{delay 2
			{view pause "accelerate_steam"}
		}
	}
	{on accelerate off
		{stop_sound "accelerating"}
		{delay 2
			{view pause "accelerate_smoke"}
		}
		{call "update_moving"}
	}
	{on "update_moving"
		{if not simulating
			{if velocity 0 ; > 0 km/h
				{play_sound "moving" 1}
				{if velocity 8 ;fast
					{view start "move_smoke_fast"}
				else
					{view start "move_smoke_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on "moving"
		{if velocity 8
			{delay 15 2 "moving"
				{view start "move_steam_fast"}
				{delay 0.7
					{view pause "move_steam_fast"}
				}
				{call "moving"}
			}
		else
			{delay 8 2 "moving"
				{view start "move_steam_slow"}
				{delay 0.5
					{view pause "move_steam_slow"}
				}
				{call "moving"}
			}
		}
	}
	{on brake on
		{stop_sound "moving"}
		{play_sound "braking"}
		{view pause "move_smoke_fast"}
		{view pause "move_smoke_slow"}
		{kill_delay "moving"}
		{view start "brake_smoke"}
		{view start "brake_steam"}
		{delay 2
			{view pause "brake_steam"}
		}
	}
	{on brake off
		{stop_sound "braking"}
		{view pause "brake_smoke"}
		{call "update_moving"}
	}
	{on move off
		{stop_sound "moving"}
		{play_sound "braking"}
	}

	{on "_explosion"
		{impulse up 2 1 dir 2 1}
		{chassis_work 0}
	}
	{## on break_armor
		{component break}
	}
}

(define "fire_start"
	{add_view "smoke_dead_wheel" "fire%0" "fx_fire%0"}
	{view start "fire%0"}
	{delay 30 5
		{view stop "fire%0"}
	}
)

(define "cut_part"
	{tear "piece_medium_steel" bone %0
		{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
		{delay_effect 20 5 "stop"}
	}
)

(define "explosive"
	{on break_armor
		{if volume %0
			{call "explosion"}
		}
	}
	{on contact
		{if volume %0
			{if effector "vehicle"
				{call "explosion"}
			}
		}
	}
	{on "cut_parts"
		{blastwave c4 15 r0 8 r1 12}

		{spawn "aero_die"}
		{delay 0.15 0.05 {spawn "aero_die_fire"}}
		{spawn "aero_die_particle"}

		{add_view "smoke_black_big" "deathfx" "fxsmoke1"}
		{view start "deathfx"}
		{delay 40 5	{view stop "deathfx"}}

		("fire_start" args 1)
		("fire_start" args 2)
		("fire_start" args 3)
		("fire_start" args 4)
		("fire_start" args 5)
		("fire_start" args 6)

		("cut_part" args "part1")
		("cut_part" args "part2")
	}
)

{"train_fuelwagon"
	("explosive" args "body7")
}

{"post"
	{inflammation_time 4}
	{on break_armor
		{if volume "body"
			{call "break"}
		}
	}
	{on contact 
		{if can_crush
			{call "break"}
		}
	}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on "break"
   		{volumes "body" disable contact blast}
		{call "light_break"}
		{if not fallen
			{pillar_fall}
		}
	}
	{on "light_break"} ; handled in extender
}

{"post wood"
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8
					{call "break"}
				}
			}
		}
	}
}

{"post concrete"
	{inflammation_time 10000}
}

{"post steel"
	{inflammation_time 10000}
}

{"disable_area post"
	{on "break"
		{area disable}
		{volumes disable obstacle contact}
	}
}

{"ring_post"
	{on "ring"
		{delay 0.5
			{ani_play "gong"}
			{start_sound "push/ring"}
			{tags add "gong"}
		}
	}
}
{"traffic_light_blinking"
	{on spawn
		{set "light_on" 0}
		{call "update_blinking"}
	}
	{on "break"
		{set "light_on" 0}
		{call "update_blinking"}
	}
	{on "update_blinking"
		{if not fallen
			{if "light_on"
				{view hide "lights_glow"}
				{set "light_on" 0}
			else
				{view show "lights_glow"}
				{set "light_on" 1}
			}
			{delay_effect 0.5 "update_blinking"}
		else
			{kill_delay "update_blinking"}
			{view hide "lights_glow"}
		}
	}
}
{"traffic_light_on"
	{on spawn
		{if fallen
			{set "light_on" 0}
		else
			{set "light_on" 1}
		}
		{call "update_lights"}
	}
	{on "break"
		{set "light_on" 0}
		{call "update_lights"}
	}
	{on "update_lights"
		{if not "light_on"
			{view hide "lights_glow"}
		}
	}
}

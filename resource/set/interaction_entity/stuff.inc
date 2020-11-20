(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "FXshell"}
		}
	}
)

("shell_fx" tag(shell5)		shell(shell5))
("shell_fx" tag(shell7)		shell(shell7))
("shell_fx" tag(shell9)		shell(shell9))
("shell_fx" tag(shell11)	shell(shell11))
("shell_fx" tag(shell12)	shell(shell12))
("shell_fx" tag(shotgun)	shell(shell_shotgun))

(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight3"}
			else
				{add_view "flash_gun_silencer" "flashbarrel" "foresight3"}
			}
		}
	}
)

("flash_fx" tag(smg2)			flash(flash_gun_small))
("flash_fx" tag(pistol)			flash(flash_gun_small))
("flash_fx" tag(shotgun)		flash(flash_shotgun))
("flash_fx" tag(rifle)			flash(flash_gun_small_x))
("flash_fx" tag(assaultrifle)	flash(flash_gun_small_x))
("flash_fx" tag(mgun)			flash(flash_gun_big))

{"stuff weapon"
	{on "fire"
		{ani_play "recoil"}
		{view show	"flashbarrel"}
		{view start	"flashbarrel"}
		{view start "shell"}
		{delay 0.1 "shell"
			{view pause "shell"}
		}
		{delay 0.4 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
}

{"stuff weapon fx_thrower"
	{on spawn
		{add_view "flamer_fire"			"flame"	"foresight3"}
		{add_view "flamer_fire_barrel"	"fire"	"foresight3"}
	}
	{on "link"
		{view show	"fire"}
		{view start	"fire"}
	}
	{on "fire" overload
		{view start	"flame"}
		{kill_delay "fire"}
		{delay 0.4 "fire"
			{view pause	"flame"}
		}
	}
}

{"stuff weapon object_thrower"
	{on spawn
		{add_view "flamer_fire_barrel"	"fire"	"foresight3"}
	}
	{on "link"
		{view show	"fire"}
		{view start	"fire"}
	}
	{on "fire" overload
		{spawn "flamethrower_shell" "foresight3" x
			{impulse dir 30 rnd_dir 1}
			{gravity 1}
			{linear_damping 0}
		}
	}
}

{"stuff weapon rocketlauncher"
	{on "fire"
		{spawn "bazooka_shot" "fxshot" x}
	}
}

{"stuff weapon anim_extension"
	{on spawn
		{ani_wind "extended" begin}
	}
	{on "link"
		{delay 0.3
			{ani_play "extended"}
		}
	}
	{on "unlink"
		{ani_play "extended" -1}
	}
}

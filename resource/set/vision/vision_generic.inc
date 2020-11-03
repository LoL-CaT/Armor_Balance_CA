;= START =====================================


(define "vision_human"
	("radius" r(80))				;vision = radius * (one) applicable "rules" situation * (one) applicable "mods" situation
	{rules							;no multiplication within rules blocks
		{human 1.15					;fallback value if no other subordinated case is applicable
			{firing 1.20			;shooting with a weapon?
				("firing")			;shooting with a stealth weapon or throwable? (a modifier picked here is final, the stance for example will not be considered anymore)
			}
			("vision")				;not shooting? check other cases of visibility
		}
		("cannon")
		("tank")
	}
	{mods							;no nested blocks allowed, but all applicable values will be multiplied
		{stand 1.0}
	}
)
(define "vision_human_peripheral"
	("radius" r(20))
	{rules
		{human 1.0
			{firing 3.0
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1.0}
	}
)
(define "vision_human2"
	("radius" r(90))
	{rules
		{human 1.0
			{firing 1.5
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1.0}
	}
)

(define "visor_huizor"
    ("radius" r(25))
    {rules
        {human 1
            {firing 1.15
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
    }
    {mods
        {stand 1}
    }
)


(define "vision_humancrew"
    ("radius" r(50))
    {rules
        {human 1
            {firing 1.10
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
    }
    {mods
        {stand 1}
    }
)

(define "vision_optic"
    ("radius" r(115))
    {rules
        {human 0.90
            {firing 1.50
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
    }
    {mods
        {stand 1}
    }
)

(define "vision_driver"
	("radius" r(30))
	{rules
		{human 0.75
			{firing 1.25
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1.0}
	}
)

(define "vision_human_air"
    ("radius" r(130))
    {rules
        {human 1.75
            {firing 1.75
                ("firing")
            }
            ("vision")
        }
        ("cannon")
        ("tank")
;        {tsmoke 0}
    }
    {mods
        {stand 1}
    }
)

(define "vision_gunner"
    ("radius" r(40))
    {rules
        {human 0.80
            {firing 1.10
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
    }
    {mods
        {stand 1}
    }
)


(define "vision_turret"
    ("radius" r(50))
    {rules
        {human 1.30
            {firing 1.40
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
    }
    {mods
        {stand 1}
    }
)

(define "vision_helicopter"
	("radius" r(130))
	{rules
		{human 0.75
			{firing 1.25
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{human		1.5}
		{cannon_01	1.5}
		{cannon_02	1.5}
		{cannon_03	1.5}
		{vehicle_01	1.5}
		{vehicle_02	1.5}
		{vehicle_03	1.5}
	}
)

(define "vision_seeair_around"
    ("radius" r(700))
    {rules
        {human 0}
        {cannon_01 0}
        {cannon_02 0}
        {cannon_03 0}
        {cannon_04 0}
        {cannon_05 0}
        {vehicle_01 0}
        {vehicle_02 0}
        {vehicle_03 0}
        {vehicle_04 0}
        {vehicle_05 0}
        {air 1.2
            {firing 1.5}
            {visible 0.9}
            {still 0.1}
        }
;       {tsmoke 0}
    }
    {mods
        {stand 1}
    }
)
(define "vision_ship"
    ("radius" r(500))
    {rules
        {human 1
            {firing 1.15
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
;		{tsmoke 0}
    }
    {mods
        {stand 1}
    }
)
(define "vision_ship_tower"
    ("radius" r(600))
    {rules
        {human 1
            {firing 1.15
				("firing")
            }
			("vision")
        }
		("cannon")
		("tank")
;		{tsmoke 0}
    }
    {mods
        {stand 1}
    }
)


(define "glass"
		("radius" r(%0))
        {rules
            {zero 0}
        }
)

;= MAP HELPER ====================================

(define "ultra_vision"
	{radius 20}
	{h_fov 360}
   	{v_fov 180}
	{uncover %range}
)
{"start_point"  ("ultra_vision" range(20))}
{"map_point"    ("ultra_vision" range(20))}
{"flag_point"   ("ultra_vision" range(20))}

;SDL

(define "peep_chain"
	{State "peep_%0_in"
		{condition "peep-%0-in"}
		{from "stand"}
		{to "peep_%0"}
		{tag "up"}
		{tag "looking"}
	}
	{State "peep_%0"
		{to "peep_%0_out"}
		{tag "peep-%0-in"}
		{tag "up"}
		{tag "looking"}
	}
	{State "peep_%0_out"
		{to "stand"}
		{tag "up"}
		{tag "looking"}
	}
)
("peep_chain" args left)
("peep_chain" args right)
;///////////////////////////////////////////////////
(define "look_chain"
	{State "look_%0_in"
		{condition "look-%0-in"}
		{from "stand"}
		{to "look_%0"}
		{tag "up"}
		{tag "looking"}
	}
	{State "look_%0"
		{to "look_%0_fire"}
		{to "look_%0_throw_begin"}
		{to "look_%0_out"}
;		{to "look_%0_switch"}
		{tag "look-%0-in"}
		{tag "hold-nothing"}
		{tag "up"}
		{tag "weapon"}
		{tag "aim"}
		{tag "aim-thrower"}
		{tag "can-aim"}
		{tag "can-aim-thrower"}
		{tag "looking"}
	}
;отключено, т.к. тогда солдат может сразу взять в руки оружие после 
;броска гранаты, что включит другую обратную анимацию, и солдат сместится в другое место
;	{State "look_%0_switch"
;		{to "look_%0"}
;		{tag "switch-weapon"}
;		{tag "up"}
;		{tag "looking"}
;	}
	{State "look_%0_throw_begin"
    	{transit "look_%0_throw_end"}
		{tag "throw"}
		{tag "up"}
		{tag "looking"}
		{tag "aim-thrower"}
		{tag "can-aim-thrower"}
	}
	{State "look_%0_throw_end"
    	{transit "look_%0"}
		{tag "up"}
		{tag "looking"}
	}
    {State "look_%0_fire"
    	{to "look_%0_recoil"}
		{tag "up"}
		{tag "fire"}
		{tag "weapon"}
		{tag "looking"}
    }
    {State "look_%0_recoil"
    	{transit "look_%0"}
		{tag "up"}
		{tag "weapon"}
		{tag "recoil"}
		{tag "looking"}
    }
	{State "look_%0_out"
		{to "stand"}
		{tag "up"}
		{tag "looking"}
	}
)
("look_chain" args left)
("look_chain" args right)
("look_chain" args sleft)
("look_chain" args sright)

;SDL

{state "stand_knock_down"
	{condition "knock-down"}
	{fromTagged "up"}
	{fromTagged "snipe"}
	{fromTagged "squat"}
	{fromTagged "onboard"}
	{transit "knock_down"}
	{tag "knock-down"}
	{tag "up"}
}
{state "lie_knock_down"
	{condition "knock-down"}
	{fromTagged "down"}
	{transit "knock_down"}
	{tag "knock-down"}
	{tag "down"}
}
{state "knock_down"
	{to "lie"}
	{tag "knock-down"}
	{tag "keep-knock-down"}
	{tag "down"}
}
{state "stand_kick"
	{condition "kick"}
	{fromTagged "up"}
	{fromTagged "snipe"}
	{fromTagged "squat"}
	{to "stand"}
	{tag "kick"}
	{tag "up"}
}
{state "lie_kick"
	{condition "kick"}
	{fromTagged "down"}
	{to "lie"}
	{tag "kick"}
	{tag "down"}
}
{State "swim_dying"
	{fromTagged "swim"}
	{transit "dead"}
	{tag "dying"}
}
{State "lie_dying"
	{fromTagged "down"}
	{transit "dead"}
	{tag "dying"}
}
{State "squat_dying"
	{fromTagged "squat"}
	{fromTagged "cover"}
	{transit "dead"}
	{tag "dying"}
}
{State "stand_dying"
	{fromTagged "up"}
	{fromTagged "snipe"}
	{fromTagged "onboard"}
	{transit "dead"}
	{tag "dying"}
}
{State "dead"
	{to "corpse_drag"}
	{tag "dead"}
	{tag "dying"}
	{tag "stored"}
}
{State "corpse_drag"
	{to "corpse_drop"}
	{tag "dying"}
	{tag "corpse"}
	{tag "stored"}
}
{State "corpse_drop"
	{transit "dead"}
	{tag "dying"}
}
{State "throwoff"
	{condition "throwoff"}
	{fromTagged "up"}
	{fromTagged "snipe"}
	{fromTagged "squat"}
	{fromTagged "onboard"}
	{fromTagged "swim"}
	{to "throwoff_end"}
	{tag "throwoff"}
	{tag "stored"}
}
{State "throwoff_end"
	{to "lie"}
	{to "dead"}
	{tag "dying"}
}

{collider "construction"}
{obstacleID "unbreakable"}
{props "concrete" "cornered" "parts" "construction" "no_destroyed_stamp"}
{mass 1000}

{Volume "rock"
	{thickness 1000}
}
{Volume "body1"
	{tags "body"}
	{thickness 1000}
}
{Volume "body"
	{tags "body"}
	{thickness 1000}
}
{armor
	{setting "body"
		{threshold {pierce {calibre 12}}}
		{ray_cast_thickness}
		{volumes "body*"}
		{threshold  
			{blast {value 10}}
		}
	}
}

{lodclass "decor_medium"}
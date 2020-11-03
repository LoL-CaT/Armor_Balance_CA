{collider "construction"}
{obstacleID "construction"}
{props "small" "concrete" "cornered" "parts" "construction" "no_destroyed_stamp"}	
{simulation {able 1}}
{mass 100}

{Volume "rock"
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}
{Volume "body1"
	{tags "body"}
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}
{Volume "body"
	{tags "body"}
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}	
	{armor
		{setting "body"
			{ray_cast_thickness 0}
		}
	}
	{armor
		{setting "body"
			{threshold {pierce {calibre 12}}}
			{ray_cast_thickness}
			{volumes "body*"}
		}
	}
	{armor
		{setting "body"
			{threshold  
				{blast {value 10}}
			}
			{durability 
				{blast {value 25}}
				{pierce {value 50}}			
			}
		}
	}

{lodclass "decor_small"}
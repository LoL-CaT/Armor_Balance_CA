game_entity
	(include "seasons.inc")
	{volume "crown"
		{Able {contact 0} {bullet 0} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}
	}
	{volume "crown1"
		{Able {contact 0} {bullet 0} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}
	}

	{collider "bush"}
	{obstacleID "nothing"}

	{props "tree" "bush" "wind_has_foliage" "remove_on_land_patch" }
	{volume defaultmaterial "wood"}

	{lodclass "decor_bush"}
	{NoGroupMesh 1}

;SDL

{State "walk"
	{split "walk_all" "linked"}
	{to "walk_switch"}
	{to "walk_inventory_in"}
	{to "walk_inventory_out"}
	{to "walk_reload"}
	{to "walk_unload"}
	{to "stand"}
	{tag "move"}
	{tag "up"}
	{tag "rotate"}
	{tag "hold-item"}
	{tag "hold-nothing"}
	{tag "stop-hold-back"}
}
{State "walk_switch_move"
	{from "walk"}
	{transit "walk"}
	{tag "move"}
	{tag "switch-move"}
	{tag "up"}
}
{State "walk_switch"
	{split "walk" "switch_begin"}
	{to "walk"}
	{tag "up"}
	{tag "move"}
	{tag "switch-weapon"}
}
{State "walk_inventory_in"
	{split "walk" "inventory_in"}
	{to "walk"}
	{tag "up"}
	{tag "move"}
	{tag "inventory-drop"}
}
{State "walk_inventory_out"
	{split "walk" "inventory_out"}
	{to "walk"}
	{tag "up"}
	{tag "move"}
	{tag "inventory-pick"}
}
{State "walk_holdback_in"
	{split "walk" "holdback_in"}
	{from "walk"}
	{to "walk_holdback_out"}
	{tag "up"}
	{tag "move"}
	{tag "weapon"}
	{tag "hold-back"}
}
{State "walk_holdback_out"
	{split "walk" "holdback_out"}
	{to "walk"}
	{tag "up"}
	{tag "move"}
	{tag "weapon"}
}
{State "walk_aim_prepare"
	{split "walk" "move_aim_prepare"}
	{from "walk"}
	{to "walk_aim"}
	{tag "up"}
	{tag "move"}
	{tag "weapon"}
	{tag "no-fire"}
	{tag "can-aim"}
}
{State "walk_aim"
	{split "walk" "move_aim"}
	{to "walk_fire"}
	{to "walk"}
	{tag "up"}
	{tag "move"}
	{tag "aim"}
	{tag "can-aim"}
	{tag "weapon"}
}
{State "walk_fire"
	{split "walk" "move_fire"}
	{to "walk_recoil"}
	{tag "up"}
	{tag "move"}
	{tag "fire"}
	{tag "weapon"}
}
{State "walk_recoil"
	{split "walk" "move_recoil"}
	{transit "walk_aim"}
	{tag "up"}
	{tag "move"}
	{tag "recoil"}
	{tag "weapon"}
	{tag "can-aim"}
	{tag "no-fire"}
}
{State "walk_reload"
	{split "walk" "reload"}
	{transit "walk"}
	{tag "up"}
	{tag "move"}
	{tag "reload"}
	{tag "weapon"}
	{tag "no-aim"}
}
{State "walk_unload"
	{split "walk" "unload"}
	{transit "walk"}
	{tag "up"}
	{tag "move"}
	{tag "unload"}
	{tag "weapon"}
}
{State "walk_belt_in"
	{split "walk" "belt_in"}
	{from "walk"}
	{to "walk_belt_out"}
	{tag "belt-drop"}
	{tag "move"}
	{tag "up"}
}
{State "walk_belt_out"
	{split "walk" "belt_out"}
	{to "walk"}
	{tag "belt-pick"}
	{tag "move"}
	{tag "up"}
}
{State "walk_pistol_in"
	{split "walk" "pistol_in"}
	{from "walk"}
	{to "walk_pistol_out"}
	{tag "pistol-drop"}
	{tag "move"}
	{tag "up"}
}
{State "walk_pistol_out"
	{split "walk" "pistol_out"}
	{to "walk"}
	{tag "pistol-pick"}
	{tag "move"}
	{tag "up"}
}

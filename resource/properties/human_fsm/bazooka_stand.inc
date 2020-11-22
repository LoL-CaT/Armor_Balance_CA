;SDL

{State "stand_bazooka_pick"
	{from "stand"}
	{to "stand"}
	{tag "up"}
	{tag "bazooka-pick"}
}
{State "stand_bazooka_aim_prepare"
	{from "stand"}
	{to "stand_bazooka_aim"}
	{tag "up"}
	{tag "weapon"}
}
{State "stand_bazooka_aim"
	{to "stand_bazooka_fire"}
	{to "stand"}
	{tag "up"}
	{tag "aim-bazooka"}
	{tag "can-aim-bazooka"}
	{tag "weapon"}
}
{State "stand_bazooka_fire"
	{from "stand"}
	{to "stand_bazooka_recoil"}
	{tag "up"}
	{tag "fire-bazooka"}
	{tag "weapon"}
}
{State "stand_bazooka_recoil"
	{transit "stand"}
	{tag "up"}
	{tag "recoil"}
	{tag "weapon"}
}
{State "stand_bazooka_reload"
	{from "stand"}
	{transit "stand"}
	{tag "up"}
	{tag "reload-bazooka"}
	{tag "weapon"}
}
{State "stand_bazooka_unload"
	{from "stand"}
	{transit "stand"}
	{tag "up"}
	{tag "unload-bazooka"}
	{tag "weapon"}
}
{State "stand_bazooka_drop"
	{from "stand"}
	{to "stand"}
	{tag "up"}
	{tag "bazooka-drop"}
}

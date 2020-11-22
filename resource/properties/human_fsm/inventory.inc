;SDL

; drop items
{State "stand_drop"
	{from "stand"}
	{to "stand_drop_end"}
	{tag "up"}
	{tag "ground-drop"}
}
{State "stand_drop_end"
	{to "stand"}
	{tag "up"}
}
{State "lie_drop"
	{from "lie"}
	{to "lie_drop_end"}
	{tag "down"}
	{tag "ground-drop"}
}
{State "lie_drop_end"
	{to "lie"}
	{tag "down"}
}

; pickup items
{State "stand_pickup"
	{from "stand"}
	{to "stand_pickup_end"}
	{tag "up"}
	{tag "pickup-stand"}
	{tag "pickup-hand"}
	{tag "pickup-bazooka"}
}
{State "stand_pickup_end"
	{to "stand"}
	{tag "up"}
}
{State "lie_pickup"
	{from "lie"}
	{to "lie_pickup_end"}
	{tag "down"}
	{tag "pickup-hand"}
}
{State "lie_pickup_end"
	{to "lie"}
	{tag "down"}
}

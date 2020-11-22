;SDL

{State "boarding"
	{tag "onboard"}
}
{State "board"
	{condition "board"}
	{from "stand"}
	{tag "board"}
	{tag "onboard"}
	{tag "stored"}
	{tag "stop-animation"}
}
{State "board_animation"
	{from "board"}
	{to "board"}
	{tag "board"}
	{tag "onboard"}
	{tag "animation"}
}

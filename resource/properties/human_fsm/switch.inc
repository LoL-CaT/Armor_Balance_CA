{switch "walk"
	{split 0 "stand" "walk"}	; { split <index> <from> <to> }
	{split 0 "stand_aim" "walk"}	; { split <index> <from> <to> }
	{link "stand" "walk"} 		; { link <from> <to> }
	{link "stand" "walk_switch_move"}
}

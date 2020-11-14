	{level "lvl_1"
		{stand
			{accuracy 1.00}
		}
		{squat
			{accuracy 1.20}
		}
		{crawl
			{accuracy 1.40}
		}
		{cover
			{accuracy 1.50}
		}
		{vehicle
			{accuracy 2.00}
		}
	}
	{level "lvl_2"
		{stand
			{accuracy 1.35}
		}
		{squat
			{accuracy 1.55}
		}
		{crawl
			{accuracy 1.75}
		}
		{cover
			{accuracy 1.85}
		}
		{vehicle
			{accuracy 2.35}
		}
	}
	{level "lvl_3"
		{stand
			{accuracy 1.55}
		}
		{squat
			{accuracy 1.75}
		}
		{crawl
			{accuracy 1.95}
		}
		{cover
			{accuracy 2.05}
		}
		{vehicle
			{accuracy 2.55}
		}
	}
	{level "lvl_4"
		{stand
			{accuracy 1.75}
		}
		{squat
			{accuracy 1.95}
		}
		{crawl
			{accuracy 2.15}
		}
		{cover
			{accuracy 2.25}
		}
		{vehicle
			{accuracy 2.75}
		}
	}
	{level "lvl_5"
		{stand
			{accuracy 1.80}
		}
		{squat
			{accuracy 2.00}
		}
		{crawl
			{accuracy 2.20}
		}
		{cover
			{accuracy 2.30}
		}
		{vehicle
			{accuracy 2.80}
		}
	}
;------------------------------CA----------------------------------;	
(define "ability_light"
	{level "lvl_1"
		{stand
			{accuracy 1.50}				; weapon accuracy, the higher the better
			{recoil 1.00}				; weapon recoil, the higher the weaker
			{zoom_recoil 1.25}			; weapon recoil in zoom, the higher the weaker
			{sway 0.90}					; weapon sway in zoom, the higher the stronger
		}
		{squat
			{accuracy 1.75}
			{recoil 1.25}
			{zoom_recoil 1.50}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_2"
		{stand
			{accuracy 1.75}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.90}
		}
		{squat
			{accuracy 2.00}
			{recoil 1.25}
			{zoom_recoil 1.50}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_3"
		{stand
			{accuracy 2.00}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.90}
		}
		{squat
			{accuracy 2.25}
			{recoil 1.25}
			{zoom_recoil 1.50}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_4"
		{stand
			{accuracy 2.25}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.90}
		}
		{squat
			{accuracy 2.50}
			{recoil 1.25}
			{zoom_recoil 1.50}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_5"
		{stand
			{accuracy 2.50}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.90}
		}
		{squat
			{accuracy 2.75}
			{recoil 1.25}
			{zoom_recoil 1.50}
			{sway 0.75}
		}
		{crawl
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
)

(define "ability_medium" 
	{level "lvl_1"
		{stand
			{accuracy 0.50}
			{recoil 0.75}
			{zoom_recoil 1.00}
			{sway 2.00}
		}
		{squat
			{accuracy 1.50}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_2"
		{stand
			{accuracy 0.75}
			{recoil 0.75}
			{zoom_recoil 1.00}
			{sway 2.00}
		}
		{squat
			{accuracy 1.75}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.25}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_3"
		{stand
			{accuracy 1.00}
			{recoil 0.75}
			{zoom_recoil 1.00}
			{sway 2.00}
		}
		{squat
			{accuracy 2.00}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.50}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_4"
		{stand
			{accuracy 1.25}
			{recoil 0.75}
			{zoom_recoil 1.00}
			{sway 2.00}
		}
		{squat
			{accuracy 2.25}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.75}
		}
		{crawl
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 2.75}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
	{level "lvl_5"
		{stand
			{accuracy 1.50}
			{recoil 0.75}
			{zoom_recoil 1.00}
			{sway 2.00}
		}
		{squat
			{accuracy 2.50}
			{recoil 1.00}
			{zoom_recoil 1.25}
			{sway 0.75}
		}
		{crawl
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{cover
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0.10}
		}
		{vehicle
			{accuracy 3.00}
			{recoil 1.50}
			{zoom_recoil 1.75}
			{sway 0}
		}
	}
)	
;------------------------------CA----------------------------------;	
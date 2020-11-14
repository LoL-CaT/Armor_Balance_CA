; == STANDARD ==
(define "standard_all"
	{common
		{unitset
			{value "all"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	1500}		; in seconds
					{growTable	"0.65 0.65 0.65 0.70 0.70 0.70 0.75 0.75 0.75 0.80 0.80 0.80 0.80 0.80 0.80 0.85 0.85 0.85 0.90 0.90 0.90 0.90 0.90 0.90 1.00"}
					{payback
						{cp			"0		10		20		30		40		51"}
						{restore	"3.00	2.50	2.00 	1.50	1.00	0.5"}
					}
				}
				{buttons "s1 s2 v1 v2 v3"}
			}
			{hero
				{resource 
					{start 		10}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		}
	}
	{bots
		(include "bots_combined_arms.inc")
	}
)

; == CUSTOM ==
(define "custom_all"
	{common
		{unitset
			{value "all"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "custom"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	1500}		; in seconds
					{growTable	"0.65 0.65 0.65 0.70 0.70 0.70 0.75 0.75 0.75 0.80 0.80 0.80 0.80 0.80 0.80 0.85 0.85 0.85 0.90 0.90 0.90 0.90 0.90 0.90 1.00"}
					{payback
						{cp			"0		10		20		30		40		51"}
						{restore	"3.00	2.50	2.00 	1.50	1.00	0.5"}
					}
					{limitmin	1000}
					{limitmax	50000}
					{speedset	"2500 3000 3500 4000 4500 5000 8000 10000 20000 50000"}
				}
				{buttons "s1 s2 v1 v2 v3"}
			}
			{hero
				{resource 
					{start 		10}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		}
	}
	{bots
		(include "bots_combined_arms.inc")
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:standard_100_all"
		{gameMode "standard"}
		{unitMode "all"}
		{specMode "all_normal"}
		("standard_all"			start(2500) finish(8000) cp(0:50,90:60,180:70,270:80,360:90,450:100))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------	
	{"c:custom_50_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_50"}
		("custom_all"			start(2500) finish(8000) cp(50))
	}
	{"c:custom_60_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_60"}
		("custom_all"			start(2500) finish(8000) cp(60))
	}
	{"c:custom_80_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_80"}
		("custom_all" 			start(2500) finish(8000) cp(80)) 
	}
	{"c:custom_100_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_100"}
		("custom_all"			start(2500) finish(8000) cp(100))
	}
	{"c:custom_120_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_120"}
		("custom_all"			start(2500) finish(8000) cp(120))
	}
	{"c:custom_140_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_140"}
		("custom_all"			start(2500) finish(8000) cp(140))
	}
	{"c:custom_160_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_160"}
		("custom_all"			start(2500) finish(8000) cp(160))
	}
	{"c:custom_180_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_180"}
		("custom_all"			start(2500) finish(8000) cp(180))
	}
	{"c:custom_200_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_200"}
		("custom_all"			start(2500) finish(8000) cp(200))
	}
;------------------------------------------------------------------------------------------------------------
}